<?php

// Função para excluir um produto
if (isset($_POST['excluir'])) {
    $id = $_POST['id']; // Obtém o ID do produto a ser excluído

    // Primeiro, busca o produto para obter o nome da imagem
    $sql = MySql::conectar()->prepare("SELECT imagem FROM `tb_admin_estoque` WHERE produto_id = ?");
    $sql->execute([$id]);
    $produto = $sql->fetch(PDO::FETCH_ASSOC);

    if ($produto) {
        // Apaga a imagem do servidor
        Painel::deleteFile($produto['imagem']);

        // Apaga o registro do banco de dados
        $sql = MySql::conectar()->prepare("DELETE FROM `tb_admin_estoque` WHERE produto_id = ?");
        $sql->execute([$id]);

        // Exibe uma mensagem de sucesso
        echo('sucesso Produto e imagem excluídos com sucesso!');
    }
}

// Função para editar um produto
if (isset($_POST['editar'])) {
    $id = $_POST['id']; // Obtém o ID do produto a ser editado
    $nome = $_POST['nome'];
    $descricao = $_POST['descricao'];
    $preco = $_POST['preco'];
    $imagem = $_FILES['imagem'];

    // Verifica se uma nova imagem foi enviada
    if ($imagem['name'] != '') {
        // Verifica se a nova imagem é válida
        if (Painel::imagemValida($imagem) == false) {
            echo('erro o formato da nova imagem especificada não está correto!');
        } else {
            // Faz o upload da nova imagem
            $novaImagem = Painel::uploadFile($imagem);

            if ($novaImagem) {
                // Apaga a imagem antiga
                $sql = MySql::conectar()->prepare("SELECT imagem FROM `tb_admin_estoque` WHERE produto_id = ?");
                $sql->execute([$id]);
                $produto = $sql->fetch(PDO::FETCH_ASSOC);
                Painel::deleteFile($produto['imagem']);

                // Atualiza com a nova imagem
                $sql = MySql::conectar()->prepare("UPDATE `tb_admin_estoque` SET nome = ?, descricao = ?, imagem = ?, preco = ? WHERE produto_id = ?");
                $sql->execute([$nome, $descricao, $novaImagem, $preco, $id]);
              echo('sucesso Produto editado com sucesso, nova imagem carregada!');
            }
        }
    } else {
        // Caso nenhuma imagem nova tenha sido enviada, atualiza apenas os outros dados
        $sql = MySql::conectar()->prepare("UPDATE `tb_admin_estoque` SET nome = ?, descricao = ?, preco = ? WHERE produto_id = ?");
        $sql->execute([$nome, $descricao, $preco, $id]);
       echo ("O produto foi editado com sucesso");
    }
}

// Exibir todos os produtos
$sql = MySql::conectar()->query("SELECT * FROM `tb_admin_estoque` ORDER BY `produto_id` DESC");
$produtos = $sql->fetchAll(PDO::FETCH_ASSOC);
?>

<div class="box-content">
    <h2><i class="fa fa-list"></i> Lista de Produtos</h2>

    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Nome</th>
                <th>Imagem</th>
                <th>Descrição</th>
                <th>Preço</th>
                <th>Editar</th>
                <th>Excluir</th>
            </tr>
        </thead>
        <tbody>
            <?php if (count($produtos) > 0): ?>
                <?php foreach ($produtos as $produto): ?>
                    <tr>
                        <td><?php echo htmlspecialchars($produto['produto_id']); ?></td>
                        <td><?php echo htmlspecialchars($produto['nome']); ?></td>
                        <td><img src="uploads/<?php echo htmlspecialchars($produto['imagem']); ?>" width="100"></td>
                        <td><?php echo htmlspecialchars($produto['descricao']); ?></td>
                        <td>R$<?php echo ($produto['preco']); ?></td>
                        <td>
                            <!-- Botão de editar, abre um formulário com os dados preenchidos -->
                            <button onclick="document.getElementById('editar<?php echo $produto['produto_id']; ?>').style.display = 'block';">Editar</button>

                            <!-- Formulário de edição do produto -->
                            <div id="editar<?php echo $produto['produto_id']; ?>" style="display:none;">
                                <form method="post" enctype="multipart/form-data">
                                    <input type="hidden" name="id" value="<?php echo $produto['produto_id']; ?>">

                                    <label>Nome:</label>
                                    <input type="text" name="nome" value="<?php echo $produto['nome']; ?>" required>

                                    <label>Descrição:</label>
                                    <textarea name="descricao" required><?php echo $produto['descricao']; ?></textarea>

                                    <label>Preço:</label>
                                    <input type="text" name="preco" value="<?php echo $produto['preco']; ?>" required><br>

                                    <label>Imagem</label>
                                    <input type="file" name="imagem">

                                    <input type="submit" name="editar" value="Salvar alterações">
                                </form>
                            </div>
                        </td>
                        <td>
                            <!-- Botão de excluir -->
                            <form method="post">
                                <input type="hidden" name="id" value="<?php echo $produto['produto_id']; ?>">
                                <button type="submit" name="excluir">X</button>
                            </form>
                        </td>
                    </tr>
                <?php endforeach; ?>
            <?php else: ?>
                <tr>
                    <td colspan="7">Nenhum produto encontrado.</td>
                </tr>
            <?php endif; ?>
        </tbody>
    </table>
</div><!--box-content-->

