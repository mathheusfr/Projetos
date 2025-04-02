<?php

    class Carteira {

        private $saldo = 0;

        public function getSaldo () {
            return $this->saldo;
        }

        public function setDepositivo ($deposito) {
            $this->saldo = ($this->saldo + $deposito);
        }

        public function retirarSaldo ($retirada) {
            $this->saldo = ($this->saldo - $retirada);
        }
    }

    $Conta1 = New Carteira;

    $Conta1->setDepositivo(100);

    $Conta1->retirarSaldo(50);

    echo " O valor atual da conta e ". $Conta1->getSaldo();
?>