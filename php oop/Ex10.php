<?php

 class Pessoa {
    private $nome;
    public $idade;

    public function alterarNome ($novoNome) {
        $this->nome = $novoNome;
    }

    public function getNome () {
        return $this->nome;
    }
 }

    $p1 = New Pessoa;

    $p1->alterarNome("Matheus");

    echo " O nome da primeira pessoa é ". $p1->getNome();

    