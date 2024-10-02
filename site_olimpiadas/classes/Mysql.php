<?php
class Mysql {
    private static $pdo;

    public static function conectar(){
        if (isset(self::$pdo)){
            return self::$pdo;
        } else {
            try {
                self::$pdo = new PDO('mysql:host='.HOST.';dbname='.DATABASE, USER, PASSWORD);
                self::$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                return self::$pdo;
            } catch (Exception $e) {
                echo 'Erro ao conectar: '.$e->getMessage();
                return null;
            }
        }
    }
}
?>
