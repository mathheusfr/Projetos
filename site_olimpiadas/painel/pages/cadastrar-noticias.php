<?php

if (isset($_POST['acao'])) {
    $titulo = $_POST['titulo'];
    $conteudo = $_POST['conteudo'];
    $imagem = $_FILES['imagem']; // Corrigido para $_FILES

    // Verifica se a imagem é válida
    if (Painel::imagemValida($imagem) == false) {
        Painel::alerta('erro', 'O formato especificado não está correto!');
    } else {
        // Faz o upload da imagem
        $imagem = Painel::uploadFile($imagem);

        // Se o upload foi bem-sucedido, insere no banco de dados
        if ($imagem) {
            $sql = MySql::conectar()->prepare("INSERT INTO `posts` (titulo,conteudo,imagem) VALUES (?,?,?)");
            $sql->execute(array($titulo, $conteudo, $imagem));
            Painel::alerta('sucesso', 'A notícia "' . $titulo . '" foi criada com sucesso!');
        } else {
            Painel::alerta('erro', 'Falha ao fazer o upload da imagem.');
        }
    }
}
?>

<div class="box-content">
    <h2><i class="fa fa-pencil"></i> Cadastrar Noticias </h2>
  
    <form method="post" enctype="multipart/form-data"> <!-- Adicionado enctype para uploads -->
        <div class="form-group">
            <label>Nome:</label>
            <input type="text" name="titulo" placeholder="Digite o titulo da noticia" required>
        </div>

        <div class="form-group">
            <label>Notícia:</label>
            <textarea name="conteudo"></textarea>
        </div>

        <div class="form-group">
            <label>Imagem</label>
            <input type="file" name="imagem"/>
        </div>

        <div class="form-group">
            <input type="submit" name="acao" value="Enviar">
        </div>
    </form>
</div>
