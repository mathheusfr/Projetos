<?php

    class Time {
        public $jogador = "Pedro";
    }

    $Flamengo = New Time;

    class GerenciarTime{

        public function alterarJogador($obj) {
            $obj->jogador = "Arrascaeta";
        }
    }

    $GerenciamentoFlamengo = new GerenciarTime;

    $GerenciamentoFlamengo->alterarJogador($Flamengo);

  

    echo (" o ". $Flamengo->jogador . " é jogador do Flamengo");
    


?>