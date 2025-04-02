<?php

    class Car {
        private $modelo;
        public $marca;
        public $ano;

        public function setCarro($novoModelo) {
            $this->modelo = $novoModelo;
           // $this->marca = $novaMarca;
           // $this->ano = $novoAno;
        }

        public function getNome() {
            return $this->modelo;
        }
    }

    $c1 = new Car;

    $c1->setCarro("Prisma");

    echo ( " o nome do carro cadastrado e ". $c1->getNome());


?>