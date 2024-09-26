<?php
        $pdo = new PDO('mysql:host=localhost;dbname=brasilerao','root','');

        $sql = $pdo->prepare("SELECT * FROM `times` WHERE `id` = ?");

        $sql->execute(array($_GET['id']));

        $mostrar = $sql->fetchAll();

        echo '<pre>';
        print_r($mostrar);
        echo '<pre>';


?>


