<?php 

class ClaUzumaki {
    
    public $nome = 'Naruto';

    public function Cla(){
        echo 'Cla Uzumaki';
    }

    public $ocupacao = "Hokage";


    public $vila = "Konaha";
}

class newGenaration extends ClaUzumaki{
    
    public $nome = 'Boruto';


    public function Cla() {
        echo 'Cla uzumaki';
    }

    public $ocupacao = "Gennin";

    public $vila = "Konaha";

}



?>