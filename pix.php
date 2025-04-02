<?php
require_once 'vendor/autoload.php';

use MercadoPago\Client\Common\RequestOptions;
use MercadoPago\Client\Payment\PaymentClient;
use MercadoPago\Exceptions\MPApiException;
use MercadoPago\MercadoPagoConfig;

// Configure o token de acesso de produção
MercadoPagoConfig::setAccessToken("TEST-5712997283849528-010722-c9441a8dcd96b8e7733e30f1c690ac06-291287566");

// Verifique se o valor foi enviado via POST
if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['amount'])) {
    $amount = $_POST['amount'];
} else {
    die('Valor não foi fornecido.');
}

// Verifique se o valor é numérico e positivo
if (!is_numeric($amount) || $amount <= 0) {
    die('Valor inválido. Por favor, insira um valor numérico positivo.');
}

// Converta o valor para float e garanta duas casas decimais
$amount = number_format((float)$amount, 2, '.', '');

// Crie opções de requisição com chave de idempotência única
$request_options = new RequestOptions();
$request_options->setCustomHeaders(["X-Idempotency-Key: " . uniqid()]);

// Crie um cliente de pagamento
$client = new PaymentClient();

try {
    // Configuração do pagamento
    $payment_data = [
        "transaction_amount" => (float)$amount,
        "description" => "Descrição do pagamento",
        "payer" => [
            "first_name" => "Nome",
            "last_name" => "Sobrenome",
            "email" => "cliente@real.com", // Substitua pelo email do cliente real
            "identification" => [
                "type" => "CPF",
                "number" => "CPF_DO_CLIENTE_REAL" // Substitua pelo CPF do cliente real
            ],
            "address" => [
                "zip_code" => "06233200", // CEP de exemplo
                "street_name" => "Av. das Nações Unidas",
                "street_number" => "3003",
                "neighborhood" => "Bonfim",
                "city" => "Osasco",
                "federal_unit" => "SP"
            ]
        ],
        "payment_method_id" => 'pix'
    ];

    // Crie o pagamento com a configuração definida
    $payment = $client->create($payment_data, $request_options);

    // Obtenha dados do PIX
    $dados_pix = $payment->point_of_interaction->transaction_data;
    $payload = $dados_pix->qr_code;
    $qrcode = "data:image/jpeg;base64,{$dados_pix->qr_code_base64}";

    // Exiba o QR code e payload com estilo
    echo "<div style='text-align: center;'>
            <h2>QR Code para Pagamento PIX</h2>
            <img src='{$qrcode}' style='width: 300px; height: 300px;' /> <br />
            <p>Escaneie este código com o aplicativo do seu banco para realizar o pagamento.</p>
            <p>{$payload}</p>
          </div>";

} catch (MPApiException $e) {
    print_r($e->getApiResponse()->getContent());
} catch (\Exception $e) {
    echo "Erro ao processar o pagamento: " . $e->getMessage();
}
?>
