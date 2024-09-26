<?php
   include("../config.php");


   Painel::teste();

   if (Painel::logado() == false) {
      include("login.php");
   }else{
      include("main.php");
   }

?>