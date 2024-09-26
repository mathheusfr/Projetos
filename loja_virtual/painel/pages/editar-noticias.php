<?php

$sql = MySql::conectar()->query("SELECT * FROM `posts` ORDER BY `id` DESC");
$noticias = $sql->fetchAll(PDO::FETCH_ASSOC);

// Função para excluir uma notícia
if (isset($_POST['excluir'])) {
    $id = $_POST['id']; // Obtém o ID da notícia a ser excluída

    // Primeiro, buscamos a notícia para obter o nome da imagem
    $sql = MySql::conectar()->prepare("SELECT imagem FROM `posts` WHERE id = ?");
    $sql->execute([$id]);
    $noticia = $sql->fetch(PDO::FETCH_ASSOC);

    if ($noticia) {
        // Apaga a imagem do servidor
        Painel::deleteFile($noticia['imagem']);

        // Apaga o registro do banco de dados
        $sql = MySql::conectar()->prepare("DELETE FROM `posts` WHERE id = ?");
        $sql->execute([$id]);

        // Exibe uma mensagem de sucesso
        Painel::alerta('sucesso', 'Notícia e imagem excluídas com sucesso!');
    }
}
?>

<div class="box-content">
    <h2><i class="fa fa-list"></i> Lista de Notícias</h2>

    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Título</th>
                <th>Imagem</th>
                <th>Conteúdo</th>
                <th>#</th>
                <th>#</th>
            </tr>
        </thead>
        <tbody>
            <?php if (count($noticias) > 0): ?>
                <?php foreach ($noticias as $noticia): ?>
                    <tr>
                        <td><?php echo htmlspecialchars($noticia['id']); ?></td>
                        <td><?php echo htmlspecialchars($noticia['titulo']); ?></td>
                        <td> <img src="uploads/<?php echo htmlspecialchars($noticia['imagem']); ?>" width="100"></td>
                        <td><?php echo htmlspecialchars($noticia['conteudo']); ?></td>
                        <td>Editar</td>
                        <td>
                            <!-- Botão de excluir -->
                            <form method="post" onsubmit="return confirm('Deseja realmente excluir esta notícia?')">
                                <input type="hidden" name="id" value="<?php echo $noticia['id']; ?>">
                                <button type="submit" name="excluir">X</button>
                            </form>
                        </td>
                    </tr>
                <?php endforeach; ?>
            <?php else: ?>
                <tr>
                    <td colspan="5">Nenhuma notícia encontrada.</td>
                </tr>
            <?php endif; ?>
        </tbody>
    </table>
</div><!--box-content-->
