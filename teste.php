<?php
require_once __DIR__ . '/vendor/autoload.php';

use MercadoPago\SDK;

SDK::setAccessToken("APP_USR-4747529223961987-010813-e7d6f91708b3c8c562cd697f30e43496-2202391298");

echo "Autoloader e Mercado Pago configurados com sucesso!";
