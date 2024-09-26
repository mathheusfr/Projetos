<?php
    if(isset($_POST['acao'])){
        $nome = $_POST['nome'];
        $conteudo_depoimentos = $_POST['conteudo_depoimento'];
        $imagem = $_FILES['imagem']; 

        if (Painel::imagemValida($imagem) == false) {
            Painel::alerta('erro', 'O formato especificado não está correto!');
        } else {
            $imagem = Painel::uploadFile($imagem);
    
            if ($imagem) {
                $sql = MySql::conectar()->prepare("INSERT INTO `tb_admin_depoimentos` (nome,conteudo_depoimento,imagem) VALUES (?,?,?)");
                $sql->execute(array($nome, $conteudo_depoimentos, $imagem));
                Painel::alerta('sucesso', 'A notícia "' . $nome . '" foi criada com sucesso!');
            } else {
                Painel::alerta('erro', 'Falha ao fazer o upload da imagem.');
            }
        }
    }
?>

<div class="box-content">
    <h2><i class="fa fa-pencil"></i> Cadastrar Depoimentos </h2>
  
    <form method="post" enctype="multipart/form-data"> <!-- Adicionado enctype para uploads -->
        <div class="form-group">
            <label>Nome:</label>
            <input type="text" name="nome" placeholder="Digite o titulo da noticia" required>
        </div>

        <div class="form-group">
            <label>Notícia:</label>
            <textarea name="conteudo_depoimento"></textarea>
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
