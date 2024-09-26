<?php
        $pdo = new PDO('mysql:host=localhost;dbname=brasilerao','root','');

        $sql = $pdo->prepare("SELECT * FROM `times` ORDER BY nome_time ");
        

        $sql->execute();


        $mostrar = $sql->fetchAll();

        foreach ($mostrar as $key => $value) {
                echo $value['nome_time'];
                echo '<hr>';
        }



?>


