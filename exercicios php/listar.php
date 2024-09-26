<?php
    // Conectando ao banco de dados
    $pdo = new PDO('mysql:host=localhost;dbname=brasilerao', 'root', '');

    // Preparando a consulta com um parâmetro
    $sql = $pdo->prepare("SELECT * FROM `times` WHERE `id` = ?");

    // Verificando se o parâmetro 'id' existe na URL
    if (isset($_GET['id'])) {
        // Executando a consulta com o parâmetro da URL
        $sql->execute(array($_GET['id']));

        // Obtendo os resultados
        $mostrar = $sql->fetchAll();

        // Exibindo os resultados
        echo '<pre>';
        print_r($mostrar);
        echo '</pre>';
    } else {
        echo 'O parâmetro "id" não foi fornecido na URL.';
    }
?>
