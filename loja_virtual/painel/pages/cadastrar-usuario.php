
<div class="box-content">
	<h2><i class="fa fa-pencil"></i> Adicionar Usuário</h2>

	<form method="post" enctype="multipart/form-data">

		<?php
			if(isset($_POST['acao'])){
				$login = $_POST['login'];
				$nome = $_POST['nome'];
				$senha = $_POST['password'];
				$imagem = $_FILES['imagem'];
        
                 if(Painel::imagemValida($imagem) == false){
                    Painel::alerta('erro','O formato especificado não está correto!');
                }else if(Usuario::userExists($login)){
                    Painel::alerta('erro','O login já existe, selecione outro por favor!');
                }else{
                    //Apenas cadastrar no banco de dados!
                    $usuario = new Usuario();
                    $imagem = Painel::uploadFile($imagem);
                    $usuario->cadastrarUsuario($login,$senha,$imagem,$nome);
                    Painel::alerta('sucesso','O cadastro do usuário '.$login.' foi feito com sucesso!');
                }
            }	
		
				
		?>

		<div class="form-group">
			<label>Login:</label>
			<input type="text" name="login">
		</div><!--form-group-->

		<div class="form-group">
			<label>Nome:</label>
			<input type="text" name="nome">
		</div><!--form-group-->
		<div class="form-group">
			<label>Senha:</label>
			<input type="password" name="password">
		</div><!--form-group-->

		<div class="form-group">
			<label>Imagem</label>
			<input type="file" name="imagem"/>
		</div><!--form-group-->

		<div class="form-group">
			<input type="submit" name="acao" value="Cadastrar!">
		</div><!--form-group-->

	</form>



</div><!--box-content-->

