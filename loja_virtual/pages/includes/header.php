<!DOCTYPE html>
<html>
<head>
	<title>Loja</title>
	<meta charset="viewport" content="width=device-width;initial-scale=1.0;maximum-scale=1.0">
	<link href="https://fonts.googleapis.com/css?family=Open+Sans:300,400" rel="stylesheet">
	<link rel="stylesheet" href="<?php echo INCLUDE_PATH ?>estilo/font-awesome.min.css">
	<link rel="stylesheet" href="<?php echo INCLUDE_PATH ?>estilo/style.css">
</head>
<body>
<header>
	<div class="container">
		<div class="logo"><a href="<?php echo INCLUDE_PATH ?>">Loja Virtual</a></div>
		<nav class="desktop">
			<ul>
				<li><a href="javascript:void(0);"><i class="fa fa-shopping-cart" aria-hidden="true"></i> Carrinho(<?php echo \models\homeModel::getTotalItemsCarrinho(); ?>)</a></li>
				<li ><a href="<?php echo INCLUDE_PATH ?>finalizar">Finalizar Pedido</a></li>
				<li ><a href="<?php echo INCLUDE_PATH ?>painel"><i class="fa fa-user"></i></a></li>
			</ul>
		</nav>
		<div class="clear"></div>
	</div><!--container-->
</header>