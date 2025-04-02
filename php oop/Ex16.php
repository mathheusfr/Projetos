<?php

     class Funcionario {
        public $nome;
        public $salario = 500;
    }

    $f1 = new Funcionario;

    class Gerenciamento{
        public $nome;

        public function alterarSalario($obj, $valor){
            $obj->salario = $valor;
        }
    }

    $g1 = new Gerenciamento;

    $g1->alterarSalario($f1, 2000);

    echo (" O salario atual do funcionario ". $f1->nome . " é de ". $f1->salario);
?>