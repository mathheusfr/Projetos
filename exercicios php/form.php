<?php
    $pdo = new PDO('mysql:host=localhost;dbname=modulo_08', 'root','');

    if(isset($_POST['acao'])) {
        $nome = $_POST['nome'];
        $sobrenome = $_POST['sobrenome'];
        $momento_registro = $_POST['momento_registro'];

        $sql = $pdo->prepare("INSERT INTO `clientes` VALUES (null,?,?,?)");

        $sql->execute([$nome, $sobrenome, $momento_registro]);
        echo 'Cliente inserido com sucesso';
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cadastro no banco</title>
</head>
<body>
    <form method="post">
        <input type="text" name="nome" required />
        <input type="text" name="sobrenome" required />
        <input type="datetime-local" name="momento_registro" />
        <input type="submit" name="acao" value="Enviar!" />
    </form>
</body>
</html>