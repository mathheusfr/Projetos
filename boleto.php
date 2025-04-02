<?php
require_once 'vendor/autoload.php';

use MercadoPago\Client\Common\RequestOptions;
use MercadoPago\Client\Payment\PaymentClient;
use MercadoPago\Exceptions\MPApiException;
use MercadoPago\MercadoPagoConfig;

MercadoPagoConfig::setAccessToken("TEST-5712997283849528-010722-c9441a8dcd96b8e7733e30f1c690ac06-291287566");

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['amount'])) {
    $amount = trim($_POST['amount']);
    $amount = filter_var($amount, FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
    if (!is_numeric($amount) || $amount <= 0) {
        die('Valor inválido. Por favor, insira um valor numérico positivo.');
    }
    $amount = number_format((float)$amount, 2, '.', '');
} else {
    die('Valor não foi fornecido.');
}

$request_options = new RequestOptions();
$request_options->setCustomHeaders(["X-Idempotency-Key: " . uniqid()]);

$client = new PaymentClient();

try {
    $payment_data = [
        "transaction_amount" => (float)$amount,
        "description" => "Pagamento via Boleto",
        "payer" => [
            "first_name" => "João",
            "last_name" => "Silva",
            "email" => "joao.silva@exemplo.com",
            "identification" => [
                "type" => "CPF",
                "number" => "12345678909"
            ]
        ],
        "payment_method_id" => 'bolbradesco'
    ];
    $payment = $client->create($payment_data, $request_options);

    $boleto_url = $payment->transaction_details->external_resource_url;

    header("Location: {$boleto_url}");
    exit;

} catch (MPApiException $e) {
    print_r($e->getApiResponse()->getContent());
} catch (\Exception $e) {
    echo $e->getMessage();
}
?>
