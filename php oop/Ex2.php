<?php

class Animal{
    public function fazersom() {
        echo 'Som';
    }
}

class Cachorro extends Animal {
    public function fazerSom() {
        echo 'latido';
    }
}

class Gato extends Animal {
    public function fazersom() {
        echo 'Miado';
    }
}


    $Doguinho = new Cachorro;

    $Gatinho = new Gato;

    $Doguinho->fazerSom();
    echo "<br>";
    $Gatinho->fazerSom();
?>
