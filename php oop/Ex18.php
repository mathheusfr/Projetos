<?php

    class Cidade{
        public $nome;
        public $estado;

        public function __construct($nome, $estado) {
            $this->nome = $nome;
            $this->estado = $estado;
        }

        public function getCidade(){
            return $this->nome;
        }
    }

    $c1 = New Cidade("Cidreira", "RS");

    echo "O nome da cidade cadastrada é ". $c1->getCidade();


    


?>