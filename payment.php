<?php
require_once __DIR__ . '/vendor/autoload.php';

use MercadoPago\Client\Common\RequestOptions;
use MercadoPago\Client\Payment\PaymentClient;
use MercadoPago\Exceptions\MPApiException;
use MercadoPago\MercadoPagoConfig;
use GuzzleHttp\Client;
use GuzzleHttp\Exception\RequestException;

$accessToken = "TEST-5712997283849528-010722-c9441a8dcd96b8e7733e30f1c690ac06-291287566";

session_start();
$token = null;

// Recuperar o valor da transação do formulário
if (isset($_POST['amount']) && is_numeric($_POST['amount'])) {
    $amount = floatval($_POST['amount']);
    if ($amount < 1.00) {
        echo "Erro: O valor da transação deve ser maior ou igual a 1 BRL.";
        exit;
    }
    // Certifique-se de que o valor está como float
} else {
    echo "Erro: O valor da transação deve ser um número válido.";
    exit;
}

// Imprimir o valor para verificação
echo "Valor da transação após formatação: " . $amount . "<br>";

try {
    $client = new Client();
    $response = $client->request('POST', 'https://api.mercadopago.com/v1/card_tokens', [
        'headers' => [
            'Authorization' => 'Bearer ' . $accessToken,
            'Content-Type' => 'application/json'
        ],
        'json' => [
            'card_number' => '5031433215406351',
            'security_code' => '123',
            'expiration_month' => '11',
            'expiration_year' => '2025',
            'cardholder' => [
                'name' => 'APRO',
                'identification' => [
                    'type' => 'CPF',
                    'number' => '12345678909'
                ]
            ]
        ]
    ]);

    $body = json_decode($response->getBody(), true);
    $token = $body['id'];
    $_SESSION['card_token'] = $token; // Armazena o token na sessão
    echo "Token do cartão criado com sucesso! Token: " . $token . "<br>";
} catch (RequestException $e) {
    echo "Erro: " . $e->getMessage();
    if ($e->hasResponse()) {
        $body = $e->getResponse()->getBody();
        var_dump(json_decode($body, true));
    }
    exit;
}

MercadoPagoConfig::setAccessToken($accessToken);

$paymentClient = new PaymentClient();
$request = [
    "transaction_amount" => $amount,
    "token" => $token,
    "description" => "Compra de teste",
    "installments" => 1,
    "payment_method_id" => "master",
    "payer" => [
        "email" => "user@test.com",
    ],
];
$requestOptions = new RequestOptions();
$requestOptions->setCustomHeaders(["X-Idempotency-Key: " . uniqid()]);

try {
    $payment = $paymentClient->create($request, $requestOptions);
    echo "Pagamento realizado com sucesso!";
    echo "<pre>";
    print_r($payment);
    echo "</pre>";
} catch (MPApiException $e) {
    echo "Erro: " . $e->getMessage();
    echo "<pre>";
    var_dump($e->getApiResponse());
    echo "</pre>";
}
?>
