<?php 
    // Inclui o arquivo de configuração
    include('../config.php'); 
?>

<!-- Inclui o CSS -->
<link href="<?php echo INCLUDE_PATH; ?>painel/css/style-login.css" rel="stylesheet" />

<div class="center">
    <div class="box-login">
       <?php
            if(isset($_POST['acao'])){
                $user = $_POST['user'];
                $password = $_POST['password'];
                
                $sql = Mysql::conectar()->prepare("SELECT * FROM `tb_admin_usuarios` WHERE user = ? AND password = ?");
                $sql->execute(array($user, $password));
                
                if($sql->rowCount() == 1){
                    // Defina as variáveis de sessão após o login bem-sucedido
                    $_SESSION['login'] = true;
                    $_SESSION['user'] = $user;
                    $_SESSION['password'] = $password;
                    
                    // Supondo que o nome do usuário é obtido do banco de dados
                    $userData = $sql->fetch();
                    $_SESSION['nome'] = $userData['nome']; // Certifique-se de que 'nome' é uma coluna no banco de dados
                    
                    echo '<p>Login realizado com sucesso!</p>';
                    header('Location: ' . INCLUDE_PATH_PAINEL);
                    die();
                } else {
                    echo '<p>Usuário ou senha incorretos.</p>';
                }
            }
        ?>
        
        <!-- Formulário de login -->
        <form method="post">
            <h1 class="title-center">Login</h1>
            <br><br><br><br>
            <input class="form-login" type="text" name="user" placeholder="Digite seu nome" required>
            <br><br><br><br>
            <input class="form-login" type="password" name="password" placeholder="Digite sua senha" required>
            <br><br><br><br>
            <input type="submit" name="acao" value="logar">
        </form>
    </div>


</div>
