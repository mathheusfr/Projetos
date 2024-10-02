<div class="box-content">
    <h2><i class="fa fa-pencil"></i> Editar Usuário </h2>

    <form method="post" enctype="multipart/form-data">
    <?php
    if (isset($_POST['acao'])) {
        // Enviou o formulário.
        
        $nome = $_POST['nome'];
        $senha = $_POST['password'];
        $imagem = $_FILES['imagem'];
        $imagem_atual = $_POST['imagem_atual'];
        
        // Inicialize o objeto de usuário
        $usuario = new Usuario();
        
        // Verifique se foi enviada uma nova imagem
        if ($imagem['name'] != '') {
            // Lógica para upload de imagem
            if (Painel::imagemValida($imagem)) {
                // Exclua a imagem antiga
                Painel::deleteFile($imagem_atual);
                // Faça o upload da nova imagem
                $imagem = Painel::uploadFile($imagem);
                // Atualize o usuário com a nova imagem
                if ($usuario->atualizarUsuario($nome, $senha, $imagem)) {
                    $_SESSION['img'] = $imagem;
                    echo "A imagem foi atualizada com sucesso";
                } else {
                    echo "Erro ao atualizar o usuário com a nova imagem";
                }
            } else {
                Painel::alerta('erro', 'O formato da imagem não é válido');
            }
        } else {
            // Caso não haja nova imagem, mantenha a imagem atual
            $imagem = $imagem_atual;
            if ($usuario->atualizarUsuario($nome, $senha, $imagem)) {
                Painel::alerta('sucesso', 'Usuário atualizado com sucesso!');
            } else {
                Painel::alerta('erro', 'Ocorreu um erro ao atualizar o usuário');
            }
        }
    }
    ?>

        <div class="form-group">
            <label>Nome:</label>
            <input type="text" name="nome" required 
                   value="<?php echo isset($_SESSION['nome']) ? $_SESSION['nome'] : ''; ?>">
        </div><!--form-group-->

        <div class="form-group">
            <label>Senha:</label>
            <input type="password" name="password" required 
                   value="<?php echo isset($_SESSION['password']) ? $_SESSION['password'] : ''; ?>">
        </div><!--form-group-->

        <div class="form-group">
            <label>Imagem</label>
            <input type="file" name="imagem"/>
            <input type="hidden" name="imagem_atual" 
                   value="<?php echo isset($_SESSION['img']) ? $_SESSION['img'] : ''; ?>">
        </div><!--form-group-->

        <div class="form-group">
            <input type="submit" name="acao" value="Atualizar!">
        </div><!--form-group-->
    </form>
</div>
