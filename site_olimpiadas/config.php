<?php 
     if (session_status() == PHP_SESSION_NONE) {
       session_start();
   }

    $autoload = function($class) {
    include('classes/'.$class.'.php');
    };

    spl_autoload_register($autoload);

    // Conectar com banco de dados
   if (!defined('HOST')) define('HOST', 'localhost');
   if (!defined('USER')) define('USER', 'root');
   if (!defined('PASSWORD')) define('PASSWORD', '');
   if (!defined('DATABASE')) define('DATABASE', 'modulo_08');

   if (!defined('INCLUDE_PATH')) define('INCLUDE_PATH', 'http://localhost/site_olimpiadas/');
   if (!defined('INCLUDE_PATH_PAINEL')) define('INCLUDE_PATH_PAINEL', INCLUDE_PATH.'painel/');

   @define('BASE_DIR_PAINEL',__DIR__.'/painel');



?>
