<div class="tabela-pedidos">
    <div class="container">
    <h2><i class="fa fa-shopping-cart"></i> Carrinho:</h2>

    <?php
        // Verifica se o carrinho está vazio
        @$itemsCarrinho = $_SESSION['carrinho'];
        
        if(empty($itemsCarrinho)){
            echo '<p>O carrinho está vazio!</p>';
        } else {
    ?>
        <table>
            <tr>
                <td>Nome do produto</td>
                <td>Quantidade</td>
                <td>Valor</td>
                <td>Ação</td>
            </tr>
            <?php
                $total = 0;
                foreach ($itemsCarrinho as $key => $value) {
                    $idProduto = $key;

                    $produto = \MySql::conectar()->prepare("SELECT * FROM `tb_admin_estoque` WHERE produto_id = :idProduto");
                    $produto->bindParam(':idProduto', $idProduto, PDO::PARAM_INT);
                    $produto->execute();
                    $produto = $produto->fetch();

                    // Verifica se o produto foi encontrado
                    if($produto === false) {
                        echo '<tr><td colspan="4"><p>Erro: Produto não encontrado!</p></td></tr>';
                        continue; 
                    }

                    // Calcula o valor total de cada item (quantidade * preço)
                    $valor = $value * $produto['preco'];
                    $total += $valor;
            ?>
            <tr>
                <td><?php echo htmlspecialchars($produto['nome']); ?></td>
                <td><?php echo htmlspecialchars($value); ?></td>
                <td>R$<?php echo number_format($valor, 2, ',', '.'); ?></td>
                <td>
                    <a href="?remover=<?php echo htmlspecialchars($idProduto); ?>" class="btn-excluir">X</a>
                </td>
            </tr>
            <?php } ?>
        </table>
        <?php } ?>
    </div>
</div>

<?php
if(!empty($itemsCarrinho)) {
?>
    <div class="finalizar-pedido">
        <div class="container">
            <h2>Total: R$<?php echo number_format($total, 2, ',', '.'); ?></h2>
            <div class="clear"></div>
            <a href="" class="btn-pagamento">Pagar!</a>
            <div class="clear"></div>
        </div>
    </div>
<?php } ?>

<?php
// Função para remover um item do carrinho
if(isset($_GET['remover'])){
    $idProdutoRemover = (int)$_GET['remover'];

    // Verifica se o produto está no carrinho
    if(isset($_SESSION['carrinho'][$idProdutoRemover])){
        unset($_SESSION['carrinho'][$idProdutoRemover]);
    }

    // Redireciona após remover o item
    header("Location: http://localhost/loja_virtual/finalizar");
    die();
}
?>
