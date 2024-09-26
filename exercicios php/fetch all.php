<?php
    $pdo = new PDO('mysql:host=localhost;dbname=modulo_08','root','');


    $sql = $pdo->prepare("SELECT * FROM `posts` WHERE categoria_id = '2' ");

    $sql->execute();

    $info = $sql->fetchAll();

    echo '<pre>';
    print_r($info);
    echo '<pre>';

    /* 

    foreach ($info as $key => $value) {
        echo 'Titulos' .$value['titulo'];
        echo '<br>';
        echo 'Noticias' .$value['conteudo'];
        echo '<hr>';
    }

    */
?>

