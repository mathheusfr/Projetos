-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 26-Set-2024 às 21:18
-- Versão do servidor: 10.4.32-MariaDB
-- versão do PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `modulo_08`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `categorias`
--

CREATE TABLE `categorias` (
  `id` int(11) NOT NULL,
  `nome` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `categorias`
--

INSERT INTO `categorias` (`id`, `nome`) VALUES
(1, 'Esportes'),
(2, 'Geral');

-- --------------------------------------------------------

--
-- Estrutura da tabela `clientes`
--

CREATE TABLE `clientes` (
  `id` int(11) NOT NULL,
  `nome` varchar(255) DEFAULT NULL,
  `sobrenome` varchar(255) NOT NULL,
  `momento_registro` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `clientes`
--

INSERT INTO `clientes` (`id`, `nome`, `sobrenome`, `momento_registro`) VALUES
(2, 'Matheus', 'Freitas', '2024-07-15 00:00:00'),
(16, 'Denis', 'Lisboa', '2025-02-02 14:06:00');

-- --------------------------------------------------------

--
-- Estrutura da tabela `posts`
--

CREATE TABLE `posts` (
  `id` int(11) NOT NULL,
  `titulo` varchar(255) DEFAULT NULL,
  `categoria_id` int(11) NOT NULL,
  `imagem` varchar(255) NOT NULL,
  `conteudo` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `posts`
--

INSERT INTO `posts` (`id`, `titulo`, `categoria_id`, `imagem`, `conteudo`) VALUES
(29, 'Rebeca Andrade é ouro no solo em Paris', 0, '66e125aa371e1.jpg', 'Rebeca Andrade chorou de emoção e alívio, e o Brasil chorou com ela. A estrela mais brilhante do Olimpo brasileiro conquistou o ouro na final do solo na manhã desta segunda-feira (5), na Bercy Arena, em Paris, e se tornou a maior medalhista olímpica do país em todos os tempos. Tudo isso aos 25 anos. Foi um dia de emoção e redenção. Rebeca havia falhado na final de trave menos de uma hora antes e ficado fora do pódio. Mas levantou a cabeça e entregou tudo no tablado, com um solo belíssimo, chegadas praticamente cravadas ao fim de cada acrobacia e as lágrimas de quem sabia que havia encerrado sua participação nas Olimpíadas de Paris com uma apresentação de encantar o mundo todo. Simone Biles fez acrobacias incríveis, mas falhas na execução a deixaram com a medalha de prata. A americana Jordan Chiles ficou com o bronze.\r\n\r\nCom sua sexta medalha em duas Olimpíadas, Rebeca Andrade ultrapassou os cinco pódios dos velejadores Robert Scheidt e Torben Grael. E pode ter se despedido do solo da maneira mais perfeita possível. A ginasta disse, nos últimos dias, que deve deixar de fazer o solo, que sacrifica muito seus joelhos. Rebeca teve que passar por três cirurgias de ligamento cruzado anterior (LCA), e os joelhos sofrem com o impacto da aterrissagem. Se realmente essa foi a última vez, a brasileira fechou com graça, leveza e acrobacias impressionantes, altas e difíceis. Tanta beleza rendeu à ginasta um excelente 14.166 e o ouro. E quem sabe não a faz repensar a decisão?\r\n\r\n'),
(31, 'Dream Team vence França e garante ouro no basquete em Paris 2024', 0, '66e25fd95fac0.jpg', 'O Dream Team americano confirmou o favoritismo e ficou com a medalha de ouro no basquete masculino nos Jogos Olímpicos de Paris 2024. Os Estados Unidos venceram a França na final, neste sábado (10), por 98 a 87. Os EUA entraram em quadra com Stephen Curry, Lebron James, Kevin Durant, Joel Embiid e Devin Booker. Do lado francês, o destaque era Victor Wembanyama, que também atua na NBA. Como foi costume durante a Olimpíada, a arquibancada para assistir o Dream Team na final também teve presenças ilustres. Dessa vez, o presidente da França, Emmanuel Macron, e o presidente da Fifa, Gianni Infantino, marcaram presença. Os dois primeiros quartos não terminaram com uma grande diferença no placar, mas os americanos estiveram na frente o tempo todo, vencendo as parciais por 20 a 15 e depois 29 a 26. Com isso, o Dream Team foi para o intervalo com o placar de 49 a 41. Uma vantagem confortável.\r\n\r\nDepois do intervalo, os franceses voltaram acima, e, apesar de não conseguirem tirar toda a vantadem americana, venceram a parcial por 25 a 23.\r\n\r\nO último quarto teve altos e baixos das duas equipes. Primeiro, os americanos conseguiram voltar aos 10 pontos de vantagem, mas logo depois os franceses diminuíram o placar para 79 a 82, apenas três pontos de diferença.\r\n\r\n\r\n\r\n'),
(34, 'Espanha derrota a França em Paris e é bicampeã olímpica no futebol', 0, '66f5ad9d26077.jpg', 'Os espanhóis chegaram a abrir 3 a 1, os anfitriões foram buscar o empate nos acréscimos do segundo tempo, mas na prorrogação Camello garantiu a vitória por 5 a 3 com dois gols e a segunda medalha de ouro para o país ibérico no futebol masculino.\r\n\r\nDonos da casa, os franceses também buscavam o segundo título nas Olimpíadas, mas amargaram a prata para tristeza de um lotado Parque dos Príncipes, com os torcedores dando show nas arquibancadas.');

-- --------------------------------------------------------

--
-- Estrutura da tabela `produtos`
--

CREATE TABLE `produtos` (
  `id` int(11) NOT NULL,
  `id_categoria` int(11) NOT NULL,
  `nome_produto` varchar(255) NOT NULL,
  `descricao` text NOT NULL,
  `imagem` varchar(255) NOT NULL,
  `endereco` varchar(255) NOT NULL,
  `valor` int(11) NOT NULL,
  `anexo` varchar(255) NOT NULL,
  `slug` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `produtos`
--

INSERT INTO `produtos` (`id`, `id_categoria`, `nome_produto`, `descricao`, `imagem`, `endereco`, `valor`, `anexo`, `slug`) VALUES
(1, 1, 'asd', 'asdasd', '66f2e89991e55.jpg', 'asdasd', 2, '', 'teste');

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_admin_depoimentos`
--

CREATE TABLE `tb_admin_depoimentos` (
  `id` int(11) NOT NULL,
  `nome` varchar(255) NOT NULL,
  `conteudo_depoimento` varchar(255) NOT NULL,
  `imagem` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_admin_depoimentos`
--

INSERT INTO `tb_admin_depoimentos` (`id`, `nome`, `conteudo_depoimento`, `imagem`) VALUES
(6, 'Brasil fecha Paris 2024 com 20 medalhas', 'Antes, o recorde era de Atenas 2004, quando 5 medalhas douradas foram garantidas pela delegação brasileira. Em outras edições os números eram mais modestos, com 3 medalhas no máximo.\r\n\r\nEm 24 participações na história olímpica, o Brasil deixou de ganhar m', '66e2243f63908.jpg');

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_admin_descricao`
--

CREATE TABLE `tb_admin_descricao` (
  `id` int(11) NOT NULL,
  `titulo` varchar(255) NOT NULL,
  `descricao` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_admin_descricao`
--

INSERT INTO `tb_admin_descricao` (`id`, `titulo`, `descricao`) VALUES
(1, 'O MELHOR DOS JOGOS OLIMPICOS DE PARIS 2024', 'Jogos Olímpicos de Verão de 2024, oficialmente denominados Jogos da XXXIII Olimpíada e comumente conhecidos como Paris 2024, foi um evento multiesportivo internacional realizado de 26 de julho (data da cerimônia de abertura) a 11 de agosto de 2024 na França, com Paris como principal cidade anfitriã e 16 outras cidades espalhadas pela França Metropolitana, além de uma subsede no Taiti uma ilha dentro do país ultramarino francês e da coletividade ultramarina da Polinésia Francesa.\r\n\r\n');

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_admin_estoque`
--

CREATE TABLE `tb_admin_estoque` (
  `produto_id` int(11) NOT NULL,
  `nome` varchar(255) DEFAULT NULL,
  `descricao` text DEFAULT NULL,
  `imagem` varchar(255) DEFAULT NULL,
  `preco` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_admin_estoque`
--

INSERT INTO `tb_admin_estoque` (`produto_id`, `nome`, `descricao`, `imagem`, `preco`) VALUES
(16, 'Inglês em 60 dias', 'Aprender inglês não precisa ser um tédio. Foi por esse motivo que criamos a Efekta Hyperclass™. Desenvolvida por especialistas em jogos, a Hyperclass utiliza a realidade virtual para colocar o aluno em situações da vida real que o ajudam a se manter motivado e a aprender mais rápido. Temos mais de 2 mil horas de exercícios para complementar suas aulas particulares e em grupo. Pratique com vídeos, testes de vocabulário, jogos de gramática, lições de escrita e muito mais.', '66f5922d8219f.jpg', 1000),
(23, 'Curso de ingles', 'teste', '66f5a3233b323.jpg', 1000),
(24, 'Aprenda Inglês com AudioBooks', 'teste', '66f5a33f4ac3d.png', 1000),
(28, 'teste', 'teste', '66f5a6d937903.jpg', 1000);

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_admin_online`
--

CREATE TABLE `tb_admin_online` (
  `id` int(11) NOT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `ultima_acao` datetime DEFAULT NULL,
  `token` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_admin_online`
--

INSERT INTO `tb_admin_online` (`id`, `ip`, `ultima_acao`, `token`) VALUES
(1, '::1', '2024-09-06 06:19:53', '66d9fb054643a'),
(2, '::1', '2024-09-06 20:21:40', '66db4833891a9'),
(3, '::1', '2024-09-06 20:37:46', '66db4a76da474'),
(4, '::1', '2024-09-06 21:48:07', '66db576d018c8'),
(5, '::1', '2024-09-07 02:11:46', '66db5c7dd1475'),
(6, '::1', '2024-09-07 02:17:34', '66db9a8676f41'),
(7, '::1', '2024-09-07 02:23:42', '66db9d0e5fa92'),
(8, '::1', '2024-09-07 02:30:27', '66db9e8ad1e5f'),
(9, '::1', '2024-09-07 02:43:36', '66dba1b8886c1'),
(10, '::1', '2024-09-07 04:43:24', '66dbbdcb81d4f'),
(11, '::1', '2024-09-07 05:34:31', '66dbc9c7121bb'),
(12, '::1', '2024-09-09 05:06:10', '66de655812343'),
(13, '::1', '2024-09-09 07:38:57', '66de88ac3fc06'),
(14, '::1', '2024-09-09 08:11:44', '66de919fd5f93'),
(15, '::1', '2024-09-10 01:07:23', '66df7fa9de0cc'),
(16, '::1', '2024-09-10 05:08:43', '66dfb83abb9ec'),
(17, '::1', '2024-09-11 07:53:31', '66e0e42223159'),
(18, '::1', '2024-09-12 01:14:29', '66e2024b478b7'),
(19, '::1', '2024-09-12 01:49:17', '66e22c665e402'),
(20, '::1', '2024-09-12 03:44:33', '66e23e03c9013'),
(21, '::1', '2024-09-12 04:24:40', '66e24ee362e98'),
(22, '::1', '2024-09-12 05:40:03', '66e25d70c1eb9'),
(23, '::1', '2024-09-12 06:17:58', '66e26299ba2a6'),
(24, '::1', '2024-09-12 21:33:33', '66e3206908036'),
(25, '::1', '2024-09-12 21:48:30', '66e3426336d1f'),
(26, '::1', '2024-09-13 20:22:18', '66e4740d07c32'),
(27, '::1', '2024-09-14 06:33:28', '66e4a00c3ce78'),
(28, '::1', '2024-09-14 07:10:31', '66e51ac74e43f'),
(29, '::1', '2024-09-16 03:48:10', '66e7798318d54'),
(30, '::1', '2024-09-17 04:12:09', '66e8d593cf5a5'),
(31, '::1', '2024-09-17 04:54:09', '66e8e83089297'),
(32, '::1', '2024-09-17 18:50:44', '66e9ace168f7b'),
(33, '::1', '2024-09-18 00:24:45', '66ea019faf258'),
(34, '::1', '2024-09-18 00:26:46', '66ea01ed94496'),
(35, '::1', '2024-09-18 00:44:14', '66ea023c84538'),
(36, '::1', '2024-09-18 01:31:39', '66ea0660f3342'),
(37, '::1', '2024-09-18 01:32:28', '66ea1182c144c'),
(38, '::1', '2024-09-20 19:36:39', '66edabe177c23'),
(39, '::1', '2024-09-24 19:18:26', '66f2f461c3dd1'),
(40, '::1', '2024-09-24 21:38:56', '66f3154f4f977'),
(41, '::1', '2024-09-24 21:45:50', '66f316e4d56b9'),
(42, '::1', '2024-09-25 01:52:14', '66f3171d2c481'),
(43, '::1', '2024-09-24 21:49:52', '66f3173ba6b29'),
(44, '::1', '2024-09-25 04:16:29', '66f36aff18e7a'),
(45, '::1', '2024-09-25 04:23:36', '66f372849d7dd'),
(46, '::1', '2024-09-25 04:36:09', '66f374443f72f'),
(47, '::1', '2024-09-26 07:41:56', '66f4f40bef95a'),
(48, '::1', '2024-09-26 07:42:24', '66f4f440135f6'),
(49, '::1', '2024-09-26 19:25:18', '66f598fd4a669'),
(50, '::1', '2024-09-26 20:19:29', '66f5a5b1355a5'),
(51, '::1', '2024-09-26 20:37:53', '66f5a9bf971b6'),
(52, '::1', '2024-09-26 20:51:06', '66f5aa356212e'),
(53, '::1', '2024-09-26 21:05:01', '66f5ada51b7b4');

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_admin_slides`
--

CREATE TABLE `tb_admin_slides` (
  `id` int(11) NOT NULL,
  `nome` varchar(255) DEFAULT NULL,
  `slide` varchar(255) DEFAULT NULL,
  `order_id` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_admin_slides`
--

INSERT INTO `tb_admin_slides` (`id`, `nome`, `slide`, `order_id`) VALUES
(4, 'Banner1', '66e33bdd1d2ed.jpg', NULL),
(5, 'Banner2', '66e33bf0e567b.jpg', NULL),
(6, 'Banner3', '66e33c8785c07.jpg', NULL);

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_admin_usuarios`
--

CREATE TABLE `tb_admin_usuarios` (
  `id` int(11) NOT NULL,
  `user` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `img` varchar(255) DEFAULT NULL,
  `nome` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_admin_usuarios`
--

INSERT INTO `tb_admin_usuarios` (`id`, `user`, `password`, `img`, `nome`) VALUES
(1, 'admin', 'admin', '', 'Lucas'),
(4, 'denis', '123', 'perfil.jpg', 'Denis'),
(7, 'wqe', '123', NULL, NULL),
(8, 'Teste', 'teste', '66de8745767d4.jpg', 'Matheus'),
(9, 'a', 'a', '66de80cd74ed1.jpg', 'a'),
(10, 'theus', 'theus', '66df7fddcd769.jpg', 'theus'),
(11, 'Denis123', 'admin', '66e22c3425d5b.jpg', 'Denis');

-- --------------------------------------------------------

--
-- Estrutura da tabela `teste`
--

CREATE TABLE `teste` (
  `id` int(11) NOT NULL,
  `nome` varchar(255) DEFAULT NULL,
  `senha` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `teste`
--

INSERT INTO `teste` (`id`, `nome`, `senha`) VALUES
(1, NULL, ''),
(2, NULL, ''),
(3, 'Theus', ''),
(4, 'Gabriel', ''),
(5, 'Pablo', '123'),
(6, 'Bruno', ''),
(7, 'Bruno', ''),
(8, 'Didico', ''),
(9, 'Marli', ''),
(10, 'Trouxa', ''),
(11, 'Trouxa', '');

--
-- Índices para tabelas despejadas
--

--
-- Índices para tabela `categorias`
--
ALTER TABLE `categorias`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `clientes`
--
ALTER TABLE `clientes`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `posts`
--
ALTER TABLE `posts`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `produtos`
--
ALTER TABLE `produtos`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `tb_admin_depoimentos`
--
ALTER TABLE `tb_admin_depoimentos`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `tb_admin_descricao`
--
ALTER TABLE `tb_admin_descricao`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `tb_admin_estoque`
--
ALTER TABLE `tb_admin_estoque`
  ADD PRIMARY KEY (`produto_id`);

--
-- Índices para tabela `tb_admin_online`
--
ALTER TABLE `tb_admin_online`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `tb_admin_slides`
--
ALTER TABLE `tb_admin_slides`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `tb_admin_usuarios`
--
ALTER TABLE `tb_admin_usuarios`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `teste`
--
ALTER TABLE `teste`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `categorias`
--
ALTER TABLE `categorias`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT de tabela `clientes`
--
ALTER TABLE `clientes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT de tabela `posts`
--
ALTER TABLE `posts`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=35;

--
-- AUTO_INCREMENT de tabela `produtos`
--
ALTER TABLE `produtos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT de tabela `tb_admin_depoimentos`
--
ALTER TABLE `tb_admin_depoimentos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT de tabela `tb_admin_descricao`
--
ALTER TABLE `tb_admin_descricao`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT de tabela `tb_admin_estoque`
--
ALTER TABLE `tb_admin_estoque`
  MODIFY `produto_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;

--
-- AUTO_INCREMENT de tabela `tb_admin_online`
--
ALTER TABLE `tb_admin_online`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=54;

--
-- AUTO_INCREMENT de tabela `tb_admin_slides`
--
ALTER TABLE `tb_admin_slides`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT de tabela `tb_admin_usuarios`
--
ALTER TABLE `tb_admin_usuarios`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT de tabela `teste`
--
ALTER TABLE `teste`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
