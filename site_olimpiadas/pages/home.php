<?php
    $posts = Mysql::conectar()->prepare("SELECT * FROM `posts` LIMIT 3"); // Limitando para pegar apenas 3 posts
    $posts->execute();
    $posts = $posts->fetchAll();
?>

<?php
     $descricao = Mysql::conectar()->prepare("SELECT * FROM `tb_admin_descricao`");
     $descricao->execute();
     $descricao = $descricao->fetch();
?>



<h1>  <?php // echo $conteudoSite['titulo'] ?></h1>

<section class="banner-container">
    <?php
        // Consulta para pegar todos os slides
        $slidesQuery = Mysql::conectar()->prepare("SELECT * FROM `tb_admin_slides`");
        $slidesQuery->execute();
        $slides = $slidesQuery->fetchAll(); // Buscar todos os slides
    ?>

    <?php foreach ($slides as $index => $slide): ?>
        <div id="slide-<?php echo $slide['id']; ?>" class="banner-single" style="background-image: url('<?php echo INCLUDE_PATH; ?>painel/uploads/<?php echo htmlspecialchars($slide['slide']); ?>'); display: <?php echo $index == 0 ? 'block' : 'none'; ?>;">
            <div class="center"> 
                <div class="w50">
                    <form>
                        <!-- Formulário ou conteúdo opcional -->
                    </form>
                </div> <!-- fim do w50 -->
            </div><!-- fim da div center -->
        </div>
    <?php endforeach; ?>
    
    <div class="bullets">
        <?php foreach ($slides as $index => $slide): ?>
            <span class="<?php echo $index == 0 ? 'active-slider' : ''; ?>"></span> 
        <?php endforeach; ?>
    </div> <!-- fim da div bullets -->
    
    <div class="clear"></div>
</section> <!-- fim do banner principal -->



    <section class="about">
        <div class="center">
        <div class="w50 left box-about-title">
            <p class="center"><?php echo $descricao['titulo']; ?> </p>
        </div>

        <div class="w50 right box-about-descritption">
            <p> <?php echo $descricao['descricao']; ?></p>
        </div>

        </div> 
    </section>

    <?php 
   if (count($posts) > 0) {
    // Exibe a primeira notícia isoladamente
    $primeiraNoticia = $posts[0];
?>

  
    <section class="descrica-autor">
    <h2 class="title-center">Ultimas publicações</h2>
        <div class="center">
            

            <div class="w50 left box-notice">
                <br>
                    <div class="radius-box">
                        <a href="noticias-single?id=<?php echo $primeiraNoticia['id']; ?>">
                            <img class="img-notice" src="painel/uploads/<?php echo htmlspecialchars($primeiraNoticia['imagem']); ?>" alt="" width="600px" height="400px">
                        </a>                 
                    <p class="description-text"> <?php echo $primeiraNoticia['titulo']; ?> </p>
                </div> <!-- radius -->
            </div> <!-- fim do w50 box-notice-->

            
            <div class="center">
                <div class="w33 left box-notice">
                    <br>
                    <!-- Segunda e terceira notícias -->
                    <?php
                    // Exibe as outras duas notícias (se existirem)
                    for ($i = 1; $i < count($posts); $i++) {
                        $noticia = $posts[$i];
                    ?>
                        <div class="radius-box2">
                            <a href="noticias-single?id=<?php echo $noticia['id']; ?>">
                                <img class="img-notice" src="painel/uploads/<?php echo htmlspecialchars($noticia['imagem']); ?>" alt="" width="592px" height="200px">
                            </a>
                            <p><?php echo htmlspecialchars($noticia['titulo']); ?></p>
                        </div> <!-- radius -->
                        <br>
                    <?php } ?>
                </div> <!-- fim do w33 box-notice-->
            </div> <!-- fim da div center -->
        



            </div> <!-- fim da div center -->
            
            
        </div> <!-- fim da div class -->
        <div class="clear"></div>
    </section>

    <?php
} else {
    echo "<p>Nenhuma publicação encontrada.</p>";
}
?>


    <section class="especialidades">
        <div class="center-slider">
       
        <div class="sliderR">
                <div><img src="images/slider1.png" alt="Slide 1"></div>
                <div><img src="images/slider2.png" alt="Slide 1"></div>
                <div><img src="images/slider3.png" alt="Slide 1"></div>
                <div><img src="images/slider4.png" alt="Slide 1"></div>
                <div><img src="images/slider5.jpg" alt="Slide 1"></div>
            </div>


        </div>
    </section> <!-- fim da section especialidades -->

    <section class="extras">
        <div class="center">

        <?php
            $depoimentos = Mysql::conectar()->prepare("SELECT * FROM `tb_admin_depoimentos`");
            $depoimentos->execute();
            $depoimentos = $depoimentos->fetch();
        ?>

            <div id="depoimentos" class="w50 left depoimentos-container">
                <h2 class="title-center"><?php echo $depoimentos['nome']; ?></h2>
                <br><br>
                <p> <?php echo $depoimentos['conteudo_depoimento'];?> </p>
            </div>


            <div id="depoimentos" class="w50 left depoimentos-container">
                <img src="<?php echo INCLUDE_PATH; ?>painel/uploads/<?php echo htmlspecialchars($depoimentos['imagem']); ?>" width="600px" height="350px">
            </div>

            <div class="clear"></div>
        </div><!--center-->
    </section><!--extras-->