    <?php
        if (isset($_GET['id']) && is_numeric($_GET['id'])) {
        $id = intval($_GET['id']);

        $noticia = Mysql::conectar()->prepare("SELECT * FROM `posts` WHERE id = ?");
        $noticia->execute([$id]);
        $noticia = $noticia->fetch();

        if ($noticia) {
    ?>
             

        <div class="center">
            <div class="container-single"> 
             <h1 class="title-noticia-single"><?php echo ($noticia['titulo']); ?></h1>
            <section>
                <img src="painel/uploads/<?php echo ($noticia['imagem']); ?>" alt="Imagem da notícia" width="600px" height="400px">

                <p class="right w33"><?php echo(($noticia['conteudo'])); ?></p>
            </section>  
  
                <?php
                } else {
                        echo "<p>Notícia não encontrada.</p>";
                    }
                } else {
                    echo " notícia inválido ";
                }

             
    ?>
           
        </div> <!-- container-single -->
        <br><br><br>
      


    </div> <!-- fim do center -->
    <br><br><br><br><br>
    <div class="center">
            <div class="container-single">
                <br><a href="index.php">Voltar para home</a>
            </div>
        </div>

    </div>

