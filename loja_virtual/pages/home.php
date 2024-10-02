<div class="lista-items">
<h2 class="chamada-escolher"> Nossos cursos</h2>
	<div class="container">
		
		<?php
			$items = \models\homeModel::getLojaItems();
			foreach ($items as $key => $value) {
				$stmt = \MySql::conectar()->prepare("SELECT * FROM `tb_admin_estoque` WHERE produto_id = ?");
				$stmt->execute([$value['produto_id']]);
				$imagem = $stmt->fetch()['imagem'];
		?>
		<div class="produto-single-box">
			<img src="<?php echo INCLUDE_PATH_PAINEL ?>uploads/<?php echo $imagem; ?>" alt="Imagem do produto" />
			<p>Preço: R$<?php echo ($value['preco']); ?></p>
			<a href="<?php echo INCLUDE_PATH ?>?addCart=<?php echo $value['produto_id']; ?>">Adicionar no carrinho!</a>
		</div><!--produto-single-box-->
		<?php } ?>
		<div class="clear"></div>
	</div><!--container-->
</div><!--lista-items-->
