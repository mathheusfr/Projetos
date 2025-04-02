<?php

if (session_status() == PHP_SESSION_NONE) {
    session_start();
}

$autoload = function($class) {
    include('classes/'.$class.'.php');
};

spl_autoload_register($autoload);

// Defina o path correto do seu projeto
@define('INCLUDE_PATH','http://localhost/pagamentos/');
@define('INCLUDE_PATH_PAINEL',INCLUDE_PATH.'painel/');
@define('BASE_DIR_PAINEL',__DIR__.'/painel');

// Configuração para desenvolvimento (localhost)
$local_host = 'localhost';
$local_user = 'root';
$local_password = '';
$local_database = 'pagamento_db';

// Configuração para produção
$prod_host = 'sql202.infinityfree.com';
$prod_user = 'if0_38082236';
$prod_password = '1FCYqJVgGV';
$prod_database = 'if0_38082236_webhook';

// Determinar o ambiente (desenvolvimento ou produção)
if ($_SERVER['SERVER_NAME'] == 'localhost') {
    define('HOST', $local_host);
    define('USER', $local_user);
    define('PASSWORD', $local_password);
    define('DATABASE', $local_database);
} else {
    define('HOST', $prod_host);
    define('USER', $prod_user);
    define('PASSWORD', $prod_password);
    define('DATABASE', $prod_database);
}
?>
