<?php
$pdo = new PDO('mysql:host=localhost;dbname=checkout', 'root', '');

if (isset($_POST['acao'])) {
    $nome_produto = $_POST['nome_produto'];
    $descricao = $_POST['descricao'];
    $endereco = $_POST['endereco'];
    $valor = $_POST['valor'];

    $sql = $pdo->prepare("INSERT INTO `tb_produtos` (nome_produto, descricao, endereco, valor) VALUES (?, ?, ?, ?)");
    $sql->execute([$nome_produto, $descricao, $endereco, $valor]);

    echo 'Produto inserido com sucesso';
}
?>

 <div class="container-form">
      <div class="center">
        <form method="post" enctype="multipart/form-data">
                <h2>Cadastro de Produto</h2>

                <label for="nome_produto">Nome do Produto:</label>
                <br><br>
                <input type="text" id="nome_produto" name="nome_produto" required>
                <br><br>
                
                <label for="descricao">Descrição:</label>
                <br><br>
                <input type="text" id="descricao" name="descricao" required>
                <br><br>
                
                <label for="endereco">Endereço:</label>
                <br><br>
                <input type="text" id="endereco" name="endereco" required>
                <br><br>
                
                <label for="valor">Valor:</label>
                <br><br>
                <input type="number" id="valor" name="valor" required>
                <br><br>
                
                <input type="submit" name="acao" value="Enviar">
            </form>
      </div>
    </div>