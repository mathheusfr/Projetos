<?php
     class Ninja{

        public $nome;
        public $aldeia;
        public $chakra;

        public function setCargo($chakra) {
            if ($chakra <= 100) {
                echo "Chunnin";
                return $cargo = "Chunnin";
            }

           else if ( ($chakra >= 100) && ($chakra <= 500) ) {
               echo "Gennin";
            }

            else if ( ($chakra > 500) && ($chakra <= 1000) ) {
                echo "Jonnin";
             }
        }

        public function getterCargo($chakra) {
            return $this->setCargo($chakra);
        }

        public function TipoElemento ($elemento, $chakra) {
            if ($elemento == "Fogo") {
                echo "Jutsu bola de fogo";
            }

            if ($elemento == "Vento" && ($chakra >= (1000) ) ) {
                echo "Rasengan";
            }
        } // fim da classe elemento 



    } // fim da classe Ninja


    $Nina1 = New Ninja("Naruto", "dsfdf", "raasd");


   

    echo (" O nome do ninja ". $Nina1->nome);
 

?>