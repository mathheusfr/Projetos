<?php
require_once 'vendor/autoload.php';
require_once 'config.php';
require_once 'classes/Mysql.php';
use MercadoPago\Client\Payment\PaymentClient;
use MercadoPago\Exceptions\MPApiException;
use MercadoPago\MercadoPagoConfig;

// Configure o token de acesso do Mercado Pago
MercadoPagoConfig::setAccessToken('TEST-2115395507896823-010316-c1783b866a98224b591f2dd54eff16e3-291287566');

// Receba o corpo da notificação
$body = json_decode(file_get_contents('php://input'));

try {
    // Conecte ao banco de dados usando a classe Mysql
    $pdo = Mysql::conectar();

    if (!$pdo) {
        throw new Exception('Erro ao conectar ao banco de dados.');
    }

    // Verifique se o corpo da notificação contém o ID do pagamento
    if (isset($body->data->id)) {
        $id = $body->data->id;
        $client = new PaymentClient();

        try {
            // Obtenha os detalhes do pagamento
            $payment = $client->get($id);
            $external_reference = $payment->external_reference;
            $status = $payment->status;

            // Insira a notificação no banco de dados
            $stmt = $pdo->prepare("INSERT INTO notificacoes (pagamento_id, status, external_reference) VALUES (:pagamento_id, :status, :external_reference)");
            $stmt->execute([
                'pagamento_id' => $id,
                'status' => $status,
                'external_reference' => $external_reference
            ]);

            // Responda ao Mercado Pago com um status 200 OK
            http_response_code(200);

        } catch (MPApiException $e) {
            error_log("Erro na API do Mercado Pago: " . $e->getApiResponse()->getContent());
            http_response_code(500);
        } catch (\Exception $e) {
            error_log("Erro ao processar o pagamento: " . $e->getMessage());
            http_response_code(500);
        }
    } else {
        error_log('ID de pagamento não encontrado na notificação.');
        http_response_code(400);
    }
} catch (PDOException $e) {
    error_log('Erro de conexão: ' . $e->getMessage());
    http_response_code(500);
} catch (\Exception $e) {
    error_log($e->getMessage());
    http_response_code(500);
}
?>
