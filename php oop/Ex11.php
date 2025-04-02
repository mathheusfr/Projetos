<?php


    class Jogador {
        public $nome;  
        public $idade;
        public $time;

        public function CriarJogador($novo_nome, $nova_idade, $novo_time) {
             $this->nome = $novo_nome;
             $this->idade = $nova_idade;
             $this->time = $novo_time;
        }
    }

    $j1 = New Jogador;

    $j1->CriarJogador("Solteldo", "28", "Gremio");

    echo (" O nome do jogador é ". $j1->nome);

?>

