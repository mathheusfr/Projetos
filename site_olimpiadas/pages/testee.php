<?php
    // Consulta para buscar as 3 últimas notícias
    $posts = Mysql::conectar()->prepare("SELECT * FROM `posts` LIMIT 3");
    $posts->execute();
    $posts = $posts->fetchAll();

    // Verifica se há posts disponíveis
    if (count($posts) > 0) {
        $primeiraNoticia = $posts[0]; // Obtém a primeira notícia
    }
?>
<section class="descrica-autor">
    <h2 class="title-center">Últimas publicações</h2>
    <div class="center">
        <div class="w50 left box-notice">
            <br>
            <div class="radius-box">
                <!-- Link para a primeira notícia com URL padrão -->
                <a href="noticias-single?id=<?php echo $primeiraNoticia['id']; ?>">
                    <img class="img-notice" src="painel/uploads/<?php echo htmlspecialchars($primeiraNoticia['imagem']); ?>" alt="" width="600px" height="400px">
                </a>
            
                <p class="description-text"><?php echo htmlspecialchars($primeiraNoticia['titulo']); ?></p>
            </div>
        </div>

        <div class="center">
            <div class="w33 left box-notice">
                <br>
                <?php
                // Exibe as outras duas notícias (se existirem)
                for ($i = 1; $i < count($posts); $i++) {
                    $noticia = $posts[$i];
                ?>
                    <div class="radius-box2">
                        <!-- Link para as demais notícias com URL padrão -->
                        <a href="noticias-single.php?id=<?php echo $primeiraNoticia['id']; ?>">
    <img class="img-notice" src="painel/uploads/<?php echo htmlspecialchars($primeiraNoticia['imagem']); ?>" alt="" width="600px" height="400px">
</a>

                        <p><?php echo ($noticia['titulo']); ?></p>
                    </div>
                    <br>
                <?php } ?>
            </div>
        </div>
    </div>
    <div class="clear"></div>
</section>
