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
                
                <div class="avatar-usuario">

                <img src="uploads/<?php $_SESSION['img'];?>" alt="Avatar do Usuário">

                </div>
              
                <h2>Cadastro</h2>
                    <a href="<?php echo INCLUDE_PATH_PAINEL?>cadastrar-usuario">   Cadastrar Usúario</a>  
                    <a href="<?php echo INCLUDE_PATH_PAINEL?>editar-usuario"   >   Editar Usúario</a>  

                <h2>Noticias</h2>
                    <a href="<?php echo INCLUDE_PATH_PAINEL?>cadastrar-noticias">  Criar noticias</a>  
                    <a href="<?php echo INCLUDE_PATH_PAINEL?>editar-noticias"   >  Editar noticia</a>  

                <h2>Slides</h2>
                    <a href="<?php echo INCLUDE_PATH_PAINEL?>cadastrar-slides"  >  Cadastrar Slide</a>  
                    <a href="<?php echo INCLUDE_PATH_PAINEL?>editar-slides"  >     Editar Slide</a>  

                <h2>Editar site</h2>
                    <a href="<?php echo INCLUDE_PATH_PAINEL?>inserir-noticias">    Editar Site</a>  
                    

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

<script>
    document.addEventListener('DOMContentLoaded', function() {
        const items = document.querySelectorAll('.left-panel li');
        
        items.forEach(item => {
            item.addEventListener('click', function() {
                // Remove a classe 'selected' de todos os itens
                items.forEach(i => i.classList.remove('selected'));
                // Adiciona a classe 'selected' ao item clicado
                this.classList.add('selected');
            });
        });
    });
</script>
</body>
</html>