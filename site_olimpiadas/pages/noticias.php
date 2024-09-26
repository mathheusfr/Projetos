

<?php
    $noticias = Mysql::conectar()->prepare("SELECT * FROM posts"); 
    $noticias->execute();
    $noticias = $noticias->fetchAll();
?>


<?php 
    for ($i = 0; $i < count($noticias); $i++) {
        $posts = $noticias[$i];
?>
<body>
    <div class="center">
        <div class="container-notices"> 
       <br><br><br> <h1 class="w50 left"><?php echo ($posts['titulo']); ?></h1>
       <a href="noticias-single?id=<?php echo $posts['id']; ?>">
                            <img class="img-notice" src="painel/uploads/<?php echo htmlspecialchars($posts['imagem']); ?>" alt="" width="600px" height="200px">
                        </a>         <div class="clear"></div>
        <br><br><hr><br><br>
    </div>
        </div>
    <?php } ?>
</body>
