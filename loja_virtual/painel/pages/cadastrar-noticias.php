<?php

if (isset($_POST['acao'])) {
    $nome = $_POST['nome'];
    $descricao = $_POST['descricao'];
    $largura = $_POST['largura'];
    $altura = $_POST['altura'];
    $comprimento = $_POST['comprimento'];
    $peso = $_POST['peso'];
    $quantidade = $_POST['quantidade'];

    // Insere os dados no banco de dados
    $sql = MySql::conectar()->prepare("INSERT INTO `tb_admin_estoque` (nome, descricao, largura, altura, comprimento, peso, quantidade) VALUES (?, ?, ?, ?, ?, ?, ?)");
    
    if ($sql->execute(array($nome, $descricao, $largura, $altura, $comprimento, $peso, $quantidade))) {
        Painel::alerta('sucesso', 'O produto "' . $nome . '" foi cadastrado com sucesso!');
    } else {
        Painel::alerta('erro', 'Erro ao cadastrar o produto.');
    }
}
?>

<div class="box-content">
    <h2><i class="fa fa-pencil"></i> Cadastrar Produto </h2>
  
    <form method="post">
        <div class="form-group">
            <label>Nome:</label>
            <input type="text" name="nome" placeholder="Digite o nome do produto" required>
        </div>

        <div class="form-group">
            <label>Descrição:</label>
            <textarea name="descricao" required></textarea>
        </div>

        <div class="form-group">
            <label>Largura:</label>
            <input type="number" name="largura" placeholder="Digite a largura" required>
        </div>

        <div class="form-group">
            <label>Altura:</label>
            <input type="number" name="altura" placeholder="Digite a altura" required>
        </div>

        <div class="form-group">
            <label>Comprimento:</label>
            <input type="number" name="comprimento" placeholder="Digite o comprimento" required>
        </div>

        <div class="form-group">
            <label>Peso:</label>
            <input type="text" name="peso" placeholder="Digite o peso" required>
        </div>

        <div class="form-group">
            <label>Quantidade:</label>
            <input type="number" name="quantidade" placeholder="Digite a quantidade" required>
        </div>

        <div class="form-group">
            <input type="submit" name="acao" value="Cadastrar">
        </div>
    </form>
</div>
