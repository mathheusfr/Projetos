<?php 
    include('config.php'); 
    Site::updateUsuarioOnline();
?>



<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="Descrição do meu site">

    <script src="<?php echo INCLUDE_PATH; ?>js/jquery.js"></script> <!-- Corrigido aqui -->
    <script src="<?php echo INCLUDE_PATH; ?>js/scripts.js"></script>
    <script src="<?php echo INCLUDE_PATH; ?>js/slider.js"></script> 
    <script src="<?php echo INCLUDE_PATH; ?>js/main.js"></script> 
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.8.1/slick.css"/>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.8.1/slick-theme.css"/>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.8.1/slick.min.js"></script>
    <link rel="stylesheet" href="<?php echo INCLUDE_PATH; ?>css/font-awesome.min.css">
    <link href="<?php echo INCLUDE_PATH; ?>css/style.css" rel="stylesheet" />
    <link href="https://fonts.googleapis.com/css?family=Open+Sans:300,400,700" rel="stylesheet">
    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.6.0/css/all.min.css">


    <title>Projeto 01</title>
</head>
<body>
    <?php 
		$url = isset($_GET['url']) ? $_GET['url'] : 'home';

		switch ($url) {
			case 'depoimentos':
				echo '<target target="depoimentos" />';
				break;

			case 'servicos':
				echo '<target target="servicos" />';
				break;
		}
	?>

    <header>
        <div class="center">
            <div class="logo left"><a href="<?php echo INCLUDE_PATH; ?>"><img src="images/olimpiada-olympic-games-logo-0.png" width ="50px" heigh: ="50px" alt=""></a></div> <!-- logo -->
            <nav class="desktop right">
                <ul>
                    <li><a href="<?php echo INCLUDE_PATH; ?>">Home</a></li>
                    <li><a href="<?php echo INCLUDE_PATH; ?>noticias">Noticias</i></a></li>
                    <li><a href="<?php echo INCLUDE_PATH; ?>depoimentos">depoimentos</a></li>
                    <li><a href="<?php echo INCLUDE_PATH; ?>contato">contatos</a></li>
                    <li><a href="<?php echo INCLUDE_PATH; ?>painel">login</a></li>
                </ul>
            </nav>

            <nav class="mobile right">
                <div class="botao-menu-mobile"> 
                    <i class="class"><i class="fa-solid fa-bars"></i></i>
                    <ul>
                        <li><a href="<?php echo INCLUDE_PATH; ?>">Home </a></li>
                        <li><a href="<?php echo INCLUDE_PATH; ?>noticias">noticias</a></li>
                        <li><a href="<?php echo INCLUDE_PATH; ?>depoimentos">depoimentos</a></li>
                        <li><a href="<?php echo INCLUDE_PATH; ?>servicos">Serviços</a></li>
                        <li><a href="<?php echo INCLUDE_PATH; ?>contato">Contato</a></li>
                    </ul>
                </div>
            </nav>
        <class class="clear"></class>
        </div>
    </header>


    
<?php 
	if(file_exists('pages/'.$url.'.php')){
        include('pages/'.$url.'.php');
    
        // Check if the file exists in the 'panel' directory before including it
        if (file_exists('painel/'.$url.'.php')) {
            include('painel/'.$url.'.php');
        }
    } else {
        if($url != 'depoimentos' && $url != 'servicos'){
            $pagina404 = true;
            include('pages/404.php');
        } else {
            include('pages/home.php');
        }
    }
    
?>


<footer <?php if ((isset($pagina404) && $pagina404 == true) || $url == 'contato') echo 'class="fixed"'; ?>> 
        <div class="center"> 
            <br><br>
            <p class="title-center">Todos os direitos reservados</p>
        </div>
        <div class="clear"></div>
    </footer>


    <?php if ($url == 'contato') { ?>
    <script src='https://maps.googleapis.com/maps/api/js?v=3.exp&key=AIzaSyDHPNQxozOzQSZ-djvWGOBUsHkBUoT_qH4&callback=initialize' async defer></script>
    <script src="<?php echo INCLUDE_PATH; ?>js/map.js"></script>
    <?php } ?>


</body>
</html>


