<?php

if (isset($_POST['acao'])) {
    $titulo = $_POST['titulo'];
    $descricao = $_POST['descricao'];
            $sql = MySql::conectar()->prepare("INSERT INTO `tb_admin_descricao` (titulo,descricao) VALUES (?,?)");
            $sql->execute(array($titulo, $descricao));
            Painel::alerta('sucesso', 'A notícia "' . $titulo . '" foi criada com sucesso!');
    }
?>

<div class="box-content">
    <h2><i class="fa fa-pencil"></i> Cadastrar Descrição </h2>
  
    <form method="post" enctype="multipart/form-data"> <!-- Adicionado enctype para uploads -->
        <div class="form-group">
            <label>titulo:</label>
            <input type="text" name="titulo" placeholder="Digite o titulo da noticia" required>
        </div>

        <div class="form-group">
            <label>Descrição:</label>
            <textarea name="descricao"></textarea>
        </div>
    
        <div class="form-group">
            <input type="submit" name="acao" value="Enviar">
        </div>
    </form>
</div>
