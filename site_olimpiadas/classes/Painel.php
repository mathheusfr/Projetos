<?php

class Painel {
    public static function teste() {
        // echo "Ola mundo";
    }

    public static function logado() {
        return isset($_SESSION['login']);
    }

    public static function loggout() {
        session_destroy();
        header('Location:' . INCLUDE_PATH_PAINEL . 'login.php');
        exit();
    }

    public static function carregarPagina(){
        if(isset($_GET['url'])){
            $url = explode('/',$_GET['url']);
            if(file_exists('pages/'.$url[0].'.php')){
                include('pages/'.$url[0].'.php');
            }else{
                //Página não existe!
                header('Location: '.INCLUDE_PATH_PAINEL);
            }
        }else{
            include('pages/home.php');
        }
    }

    public static function alerta($tipo, $mensagem) {
        if ($tipo == 'sucesso') {
            echo "<div class='alert alert-success'>{$mensagem}</div>";
        } else if ($tipo == 'erro') {
            echo "<div class='alert alert-danger'>{$mensagem}</div>";
        }
    }
    public static function imagemValida($imagem){
        if($imagem['type'] == 'image/jpeg' ||
            $imagem['type'] == 'imagem/jpg' ||
            $imagem['type'] == 'imagem/png'){

            $tamanho = intval($imagem['size']/2024);
            if($tamanho < 1000)
                return true;
            else
                return false;
        }else{
            return false;
        }
    }

    public static function uploadFile($file){
        $formatoArquivo = explode('.',$file['name']);
        $imagemNome = uniqid().'.'.$formatoArquivo[count($formatoArquivo) - 1];
        if(move_uploaded_file($file['tmp_name'],BASE_DIR_PAINEL.'/uploads/'.$imagemNome))
            return $imagemNome;
        else
            return false;
    }

    public static function deleteFile($file){
        @unlink('uploads/'.$file);
    }

}

?>
