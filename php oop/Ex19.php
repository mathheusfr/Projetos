<?php

    class Jogador{
        public $nome;
        public $time;

        
        public function __construct($nome, $time) {
            $this->nome = $nome;
            $this->time = $time;
        }


    }

    $j = New Jogador("Matheus", "Gremio");

    echo (" O nome do jogador cadastrado é ". $j->nome);




?>