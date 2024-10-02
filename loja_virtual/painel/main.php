<?php
     if(isset($_GET['loggout'])){
       Painel::loggout();
     }
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link href="<?php echo INCLUDE_PATH; ?>painel/css/style-panel.css" rel="stylesheet" />
    <script src="<?php echo INCLUDE_PATH; ?>../js/main.js"></script> 
</head>


<body>
<div class="panel-wrapper">
    
<div class="w20 left left-panel">
                <h1 class="center" >Painel de controle   <p class="center"><?php echo $_SESSION['nome']; ?></p></h1>

                
                <h2>Gerenciar Usúario</h2>
                    <a  href="<?php echo INCLUDE_PATH_PAINEL?>cadastrar-usuario"> <i class="fa-solid fa-bars"></i>  Cadastrar Usuario</a>  
                    <a  href="<?php echo INCLUDE_PATH_PAINEL?>editar-usuario"><i class="fa-solid fa-pencil"></i>   Editar Usuario</a>  
               <br><br>
               
                <h2>Gerenciar cursos cadastrados</h2>
                    <a  href="<?php echo INCLUDE_PATH_PAINEL?>cadastrar-produto"> <i class="fa-solid fa-bars"></i>  Cadastrar Produto</a>  
                    <a href="<?php echo INCLUDE_PATH_PAINEL?>editar-produto"><i class="fa-solid fa-pencil"></i>   Editar Produto</a>  

                <div class="loggout">
                    <a href="<?php echo INCLUDE_PATH_PAINEL ?>?loggout">Loggout<i class="fa fa-window-close"></i></a>
                </div>
                </div> <!-- fim da left-panel -->

                <div class="content">
                    <?php Painel::carregarPagina(); ?>
                    <div class="clear"></div>
                </div> <!-- fim do content -->
        <div class="clear"></div>
    </div> <!-- fim da  left-panel -->
</div> <!-- fim da div wrapper -->

</body>
</html>