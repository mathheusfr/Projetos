<?php

$sql = MySql::conectar()->query("SELECT * FROM `tb_admin_slides` ORDER BY `id` DESC");
$slides = $sql->fetchAll(PDO::FETCH_ASSOC);

// Função para excluir um slide
if (isset($_POST['excluir'])) {
    $id = $_POST['id']; // Obtém o ID do slide a ser excluído

    // Primeiro, buscamos o slide para obter o nome do arquivo
    $sql = MySql::conectar()->prepare("SELECT slide FROM `tb_admin_slides` WHERE id = ?");
    $sql->execute([$id]);
    $slide = $sql->fetch(PDO::FETCH_ASSOC);

    if ($slide) {
        // Apaga a imagem do servidor
        Painel::deleteFile($slide['slide']);

        // Apaga o registro do banco de dados
        $sql = MySql::conectar()->prepare("DELETE FROM `tb_admin_slides` WHERE id = ?");
        $sql->execute([$id]);

        // Exibe uma mensagem de sucesso
        Painel::alerta('sucesso', 'Slide e imagem excluídos com sucesso!');
    }
}
?>

<div class="box-content">
    <h2><i class="fa fa-list"></i> Lista de Slides</h2>

    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Nome</th>
                <th>Imagem</th>
                <th>#</th>
                <th>#</th>
            </tr>
        </thead>
        <tbody>
            <?php if (count($slides) > 0): ?>
                <?php foreach ($slides as $slide): ?>
                    <tr>
                        <td><?php echo htmlspecialchars($slide['id']); ?></td>
                        <td><?php echo htmlspecialchars($slide['nome']); ?></td>
                        <td> <img src="uploads/<?php echo htmlspecialchars($slide['slide']); ?>" width="100"></td>
                        <td>Editar</td>
                        <td>
                            <!-- Botão de excluir -->
                            <form method="post" onsubmit="return confirm('Deseja realmente excluir este slide?')">
                                <input type="hidden" name="id" value="<?php echo $slide['id']; ?>">
                                <button type="submit" name="excluir">X</button>
                            </form>
                        </td>
                    </tr>
                <?php endforeach; ?>
            <?php else: ?>
                <tr>
                    <td colspan="5">Nenhum slide encontrado.</td>
                </tr>
            <?php endif; ?>
        </tbody>
    </table>
</div><!--box-content-->
