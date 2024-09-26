<?php 

if (isset($post['acao'])){
    $nome = $_POST['nome'];
    $sobrenome = $_POST['sobrenome'];

$sql = $pdo->prepare("INSERT INTO `clientes` values (null, ?,?,)");

$sql->execute(array($nome, $sobrenome, $momento_registro));
echo "Cliente inserido com sucesso  !";
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cadastrar no banco</title>
</head>
<body>
    <form method="post">
    <input type="text" name="nome" require />
    <input type="text" name="sobrenome" require />
    <input type="submite" name="acao" value="Enviar" require />

    </form>
    
</body>
</html>