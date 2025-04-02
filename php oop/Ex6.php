<?php

class Matematica {

    public function soma($x, $y) {
        $resultado =  $x + $y;
        echo (" O resultado da soma é ". $resultado . "<br>");
    }

    public function subtracao($x, $y) {
        $resultado = $x - $y;
        echo (" O resultado da soma é ". $resultado . "<br>");
    }


    public function divisao($x, $y) {
        $resultado = $x / $y;
        echo ("O resultado da divisão é ". $resultado . "<br>");
    }

    public function multiplicacao($x, $y) {
        $resultado = $x * $y;
        echo ("O resultado da multiplicacao é ". $resultado . "<br>");
    }

    } // fim da classe 

    $conta_soma = New Matematica;
    $conta_sub = New Matematica;
    $conta_div = New Matematica;
    $conta_mult = New Matematica;

    $conta_soma->soma(100, 20);
    $conta_sub->subtracao(90, 10);
    $conta_div->divisao(10,2);
    $conta_mult->multiplicacao(15,4);




?>