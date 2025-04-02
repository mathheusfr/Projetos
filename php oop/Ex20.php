<?php

    class Calculo{

        public function __construct($n1, $n2) {
            $this->n1 = $n1;
            $this->n2 = $n2;
        }

        public function soma () {
            return $this->n1 + $this->n2;
        }

        public function subtracao() {
            return $this->n1 - $this->n2;
        }

        public function divisao() {
            return $this->n1 / $this->n2;
        }

        public function multiplicacao() {
            return $this->n1 * $this->n2;
        }
    }

    $c1 = new Calculo(10,20);

    echo ("  <br> O resultado da soma e ". $c1->soma());
    echo ("  <br> O resultado da subtracao e ". $c1->subtracao());
    echo ("  <br> O resultado da divisao e ". $c1->divisao());
    echo ("  <br> O resultado da multiplicacao e ". $c1->multiplicacao());
?>