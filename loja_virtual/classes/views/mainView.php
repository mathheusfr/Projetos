<?php
namespace Views;

class mainView
{
    public static function render($fileName, $arr = [], $header = 'pages/includes/header.php', $footer = 'pages/includes/footer.php')
    {
        include($header);
        
        include('pages/' . $fileName);
        
        if ($fileName == 'finalizar.php') {
            $footer = 'pages/includes/footerFinalizar.php';
        }
        
        include($footer);
        die();
    }
}
?>
