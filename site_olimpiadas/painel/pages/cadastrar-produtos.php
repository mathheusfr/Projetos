<?php


?>

<div class="box-content">

    
    <form method="post" enctype="multipart/form-data">
        <?php
            if(isset($_POST)){
                $id_categoria = $_POST['login'];
                $_nome = $_POST['nome_produto'];
                $descricao = $_POST['descricao'];
                $_endereco = $_POST['endereco'];
                $_valor = $_POST['valor'];
                $_imagem = $_FILES['imagem'];
                $_anexo = $_POST['post'];
                $_slug - $_POST['slug'];

                $sql = MySql::conectar()->prepare("INSERT INTO `produtos` (nome,descricao) VALUES (NULL,?,?)");
                $sql->execute(array($nome,$descricao));
            }
        ?>

        <div class="form-group">
              <label>Nome:</label>
              <input type="text" name="titulo" placeholder="Digite o titulo da noticia" required>
        </div>

        <div class="form-group">
              <label>Noticia:</label>
              <textarea name="noticias"></textarea>
        </div>




    </form>
</div>