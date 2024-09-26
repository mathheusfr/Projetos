<?php

if (isset($_POST['acao'])) {
    $nome = $_POST['nome'];
    $slide = $_FILES['slide'];
   
    if (Painel::imagemValida($slide) == false) {
        Painel::alerta('erro', 'O formato especificado não está correto!');
    } else {
        // Faz o upload da imagem
        $slide = Painel::uploadFile($slide);

        // Se o upload foi bem-sucedido, insere no banco de dados
        if ($slide) {
            $sql = MySql::conectar()->prepare("INSERT INTO `tb_admin_slides` (nome,slide) VALUES (?,?)");
            $sql->execute(array($nome, $slide));
            Painel::alerta('sucesso', 'A notícia "' . $nome . '" foi criada com sucesso!');
        } else {
            Painel::alerta('erro', 'Falha ao fazer o upload da slide.');
        }
    }
}
?>

<div class="box-content">
    <h2><i class="fa fa-pencil"></i> Cadastrar Slide </h2>
  
    <form method="post" enctype="multipart/form-data"> 
        <div class="form-group">
            <label>Nome:</label>
            <input type="text" name="nome" placeholder="Digite o titulo da noticia" required>
        </div>

        <div class="form-group">
            <label>slide</label>
            <input type="file" name="slide"/>
        </div>

        <div class="form-group">
            <input type="submit" name="acao" value="Enviar">
        </div>
    </form>
</div>
