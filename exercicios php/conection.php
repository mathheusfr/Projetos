<?php
    $pdo = new PDO('mysql:host=localhost;dbname=modulo_08','root','');

    $sql = $pdo->prepare("INSERT INTO `clientes` VALUES(null, 'Matheus','Freitas', '2024-07-15')");

    $sql->execute();
?>