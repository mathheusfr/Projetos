<?php

if (isset($_POST['acao'])) {
    $nome = $_POST['nome'];
    $descricao = $_POST['descricao'];
    $imagem = $_FILES['imagem']; // Captura o arquivo da imagem
    $preco = $_POST['preco'];
    // Verifica se a imagem é válida
    if (Painel::imagemValida($imagem) == false) {
        Painel::alerta('erro', 'O formato especificado não está correto!');
    } else {
        // Faz o upload da imagem
        $imagem = Painel::uploadFile($imagem);

        // Se o upload foi bem-sucedido, insere no banco de dados
        if ($imagem) {
            $sql = MySql::conectar()->prepare("INSERT INTO `tb_admin_estoque` (nome, descricao, imagem, preco) VALUES (?, ?, ?, ?)");
            if ($sql->execute(array($nome, $descricao,$imagem,$preco))) {
                echo('sucesso'. 'O produto "' . $nome . '" foi cadastrado com sucesso!');
            } else {
                echo('erro' . 'Erro ao cadastrar o produto.');
            }
            } else {
                echo('Falha ao fazer o upload');
            }
    }
}
?>

<div class="box-content">
    <h2><i class="fa fa-pencil"></i> Cadastrar Produto </h2>
  
    <form method="post" enctype="multipart/form-data"> <!-- Adicionado enctype para uploads -->
        <div class="form-group">
            <label>Nome:</label>
            <input type="text" name="nome" placeholder="Digite o nome do produto" required>
        </div>

        <div class="form-group">
            <label>Descrição:</label>
            <textarea name="descricao" required></textarea>
        </div>

        <div class="form-group">
            <label>Imagem:</label>
            <input type="file" name="imagem" required/> <!-- Campo para upload da imagem -->
        </div>


        <div class="form-group">
            <label>Preço:</label>
            <input type="text" name="preco" placeholder="Digite o preço" required>
        </div>

        <div class="form-group">
            <input type="submit" name="acao" value="Cadastrar">
        </div>
    </form>
</div>
