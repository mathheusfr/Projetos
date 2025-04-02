<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Adicionar Dinheiro</title>
    <link rel="stylesheet" href="css/styles.css">
</head>
<body>
    <div class="container">
        <div class="sidebar">
            <a href="#">Início</a>
            <a href="#">Seu dinheiro</a>
            <a href="#">Atividade</a>
            <a href="#">Transferir dinheiro</a>
            <a href="#">Receber na sua loja</a>
            <a href="#">Link de pagamento</a>
            <a href="#">Acessar o site</a>
        </div>
        <div class="content">
            <h1>Como você quer adicionar?</h1>
            <form id="payment-form" method="post">

                <div class="payment-option">
                    <input type="radio" id="pix" name="payment" value="pix" required>
                    <label for="pix">Pix</label>
                </div>

                <div class="pg-payment">

</div>

                <div class="payment-option">
                    <input type="radio" id="boleto" name="payment" value="boleto" required>
                    <label for="boleto">Boleto</                
                </div><br><br>

                <div class="payment-option">
                    <input type="radio" id="cartao" name="payment" value="cartao" required>
                    <label for="cartao">Pagamento por Cartão de Crédito</label>
                </div><br>
                
                <label for="amount">Valor da Transação (em BRL):</label>
                <input type="number" id="amount" name="amount" step="0.01" min="1.00" required>
                <input type="submit" value="Pagar">
            </form>
        </div>
    </div>
    <script>
        document.getElementById('payment-form').addEventListener('submit', function(event) {
            var paymentMethod = document.querySelector('input[name="payment"]:checked').value;
            if (paymentMethod === 'pix') {
                this.action = 'pix.php';
            } else if (paymentMethod === 'boleto') {
                this.action = 'boleto.php';
            } else {
                this.action = 'payment.php'; // Se a opção for cartão de crédito
            }
        });
    </script>
</body>
</html>
