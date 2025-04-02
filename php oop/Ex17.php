<?php


    class Pessoa {

        public function falar() {
            echo "Ola mundo ";
        }
    }

    class Professor extends Pessoa{
        public function Ensinar() {
            echo "Ensinar os alunos";
        }
    }

    
    $Professor1 = new Professor;

    $Professor1->Falar();

    if ($Professor1 instanceof Pessoa) {
        echo " A classe professor é uma classe herdada";
    }
?>