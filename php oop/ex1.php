<?php
 
    class Pessoa{
        private $nome = "Matheus";
        private $idade = "24";
        private $peso = '76kg';

        public function crescer () {
            $this->comer();
            echo 'estou crescendo';
        }

        private function comer() {
            echo 'estou comendo';
        }
    }

    $pessoa = new Pessoa;
    $pessoa2 = new Pessoa;

    

?>