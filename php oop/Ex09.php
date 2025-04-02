<?php

    class Car {

        public $modelo;
        public $ano;
        public $velocidadeMaxima;

        public function setVelocidade($vel){
            $this->velocidadeMaxima = $vel;
        }

        public function getVelocidade(){
            echo "A velocidade maxima do carro e ". $this->velocidadeMaxima;
        }

    }

    $prisma = new Car;

    $prisma->nome = ("Chevolet Prisma");
    $prisma->ano = ("2012");
    $prisma->setVelocidade(200);
    $prisma->getVelocidade();

?>