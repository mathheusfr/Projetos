<?php

    class Brasileirao{

        public $nomeTime;
        public $estadio;

        public function setEstadio($nomeEstadio) {
            if ($nomeTime == "Gremio") {
                $nomeEstadio == "Arena do Gremio";
            }
        }

        public function getterEstadio() {
            echo " O nome do estadio do é ". $this->nomeEstadio;
        }
    }

    $Gremio = New Brasileirao;

    $Gremio->nome = ("Gremio");

    echo " O nome do time criado e ". $Gremio->nome;

    $Gremio->getterEstadio();

    

?>