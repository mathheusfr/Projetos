<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulário de Produto</title>
</head>
<body>
    <form action="processar_formulario.php" method="post" enctype="multipart/form-data">
        <h2>Categoria</h2>
        
        <label for="categoria">Categoria:</label>
        <select name="categoria" id="categoria" required>
            <option selected disabled>Selecione</option>
            <option value="ebook">E-Book</option>
            <option value="curso" disabled>Curso</option>
        </select>
        
        <h2>Produto</h2>
        
        <label for="nome_produto">Nome do produto:</label>
        <input type="text" id="nome_produto" name="nome_produto" required>
        
        <label for="descricao_produto">Descrição do produto:</label>
        <textarea id="descricao_produto" name="descricao_produto" required></textarea>
        
        <label for="imagem_produto">Imagem do produto:</label>
        <input type="file" id="imagem_produto" name="imagem_produto" required>
        
        <label for="url_venda">Endereço da página de venda:</label>
        <input type="url" id="url_venda" name="url_venda" required>
        
        <label for="valor_produto">Valor do produto:</label>
        <input type="number" step="0.01" id="valor_produto" name="valor_produto" required>
        
        <label for="anexo_pdf">Anexo PDF:</label>
        <input type="file" id="anexo_pdf" name="anexo_pdf" accept=".pdf" required>
        
        <label for="ativo">Ativo (publico):</label>
        <input type="checkbox" id="ativo" name="ativo" value="1">
        
        <label for="token">Token (hash):</label>
        <input type="text" id="token" name="token" required>
        
        <label for="dt_lancamento">Lançamento do produto:</label>
        <input type="date" id="dt_lancamento" name="dt_lancamento" required>
        
        <label for="dt_encerramento">Encerramento do produto:</label>
        <input type="date" id="dt_encerramento" name="dt_encerramento" required>
        
        <button type="submit">Enviar</button>
    </form>
</body>
</html>
