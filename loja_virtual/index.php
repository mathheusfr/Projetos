<?php 
include('config.php'); 


$homeController = new controller\homeController();
$finalizarController = new controller\finalizarController();

Router::get('/',function() use ($homeController){
	$homeController->index();
});

Router::get('/finalizar',function() use ($finalizarController){
	$finalizarController->index();
})


?>
