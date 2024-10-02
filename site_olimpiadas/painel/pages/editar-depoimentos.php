<?php
    $sql = MySql::conectar()->query("SELECT * FROM `tb_admin_depoimentos` ORDER BY `id` DESC");
    $depoimentos = $sql->fetchAll(PDO::FETCH_ASSOC);
?>

<div class="box-content">
    <h2><i class="fa fa-list"></i> Lista de Notícias</h2>

    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Título</th>
                <th>Conteúdo</th>
                <th>#</th>
                <th>#</th>
            </tr>
        </thead>
        <tbody>
            <?php if (count($depoimentos) > 0): ?>
                <?php foreach ($depoimentos as $depoimentos): ?>
                    <tr>
                        <td><?php echo htmlspecialchars($depoimentos['id']); ?></td>
                        <td><?php echo htmlspecialchars($depoimentos['nome']); ?></td>
                        <td><?php echo htmlspecialchars($depoimentos['conteudo_depoimento']); ?></td>
                        <td class="center">Editar</td>
                        <td class="center">X</td>


                    </tr>
                <?php endforeach; ?>
            <?php else: ?>
                <tr>
                    <td colspan="3">Nenhuma notícia encontrada.</td>
                </tr>
            <?php endif; ?>
        </tbody>
    </table>
</div><!--box-content-->
