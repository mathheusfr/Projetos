<?php
    class Pessoa {
        private $nome;
        public $cidade = "Cidreira";
    }

    $matheus = new Pessoa;

    class AlterarEndereco {
        public function Mudar($obj) {
           $obj->cidade = "Porto Alegre";
        }
    }

    $MudarCidade = new AlterarEndereco;

    $MudarCidade->Mudar($matheus);

    echo (" O endereço de ". $matheus->cidade);


?>
