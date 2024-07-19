import javax.swing.JOptionPane;
import java.util.List;

public class Testes {

    private static ClienteDAO clienteDAO = new ClienteDAOImpl();
    private static VeiculoDAO veiculoDAO = new VeiculoDAOImpl();
    private static ContratoAluguelDAO contratoAluguelDAO = new ContratoAluguelDAOImpl();

    public static void main(String[] args) {
        

        boolean sair = false;
        while (!sair) {
            String opcaoPrincipal = JOptionPane.showInputDialog(
                    "MENU PRINCIPAL\n" +
                            "1 Clientes\n" +
                            "2 Veículos\n" +
                            "3 Contrato de Aluguel\n" +
                            "4 Sair\n" +
                            "Escolha uma opção:");

            if (opcaoPrincipal == null) {
                sair = true;
                continue;
            }

            switch (opcaoPrincipal) {
                case "1":
                    menuClientes();
                    break;
                case "2":
                    menuVeiculos();
                    break;
                case "3":
                    menuContratosAluguel();
                    break;
                case "4":
                    sair = true;
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção inválida.");
                    break;
            }
        }
    }

    private static void menuClientes() {
        boolean voltar = false;
        while (!voltar) {
            String opcaoCliente = JOptionPane.showInputDialog(
                    "MENU CLIENTES\n" +
                            "1 Pesquisar Cliente\n" +
                            "2 Cadastrar Cliente\n" +
                            "3 Editar Cliente\n" +
                            "4 Excluir Cliente\n" +
                            "5 Voltar ao Menu Principal\n" +
                            "Escolha uma opção:");

            if (opcaoCliente == null) {
                voltar = true;
                continue;
            }

            switch (opcaoCliente) {
                case "1":
                    menuPesquisarCliente();
                    break;
                case "2":
                    cadastrarCliente();
                    break;
                case "3":
                    editarCliente();
                    break;
                case "4":
                    excluirCliente();
                    break;
                case "5":
                    voltar = true;
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção inválida.");
                    break;
            }
        }
    }

    private static void menuPesquisarCliente() {
        String opcaoPesquisaCliente = JOptionPane.showInputDialog(
                "PESQUISAR CLIENTE\n" +
                        "1 Buscar por ID\n" +
                        "2 Pesquisar por CPF\n" +
                        "3 Pesquisar por CNPJ\n" +
                        "4 Pesquisar por Nome\n" +
                        "5 Listar Todos os Clientes\n" +
                        "Escolha uma opção:");

        if (opcaoPesquisaCliente == null) {
            return;
        }

        switch (opcaoPesquisaCliente) {
            case "1":
                buscarClientePorId();
                break;
            case "2":
                buscarClientePorCpf();
                break;
            case "3":
                buscarClientePorCnpj();
                break;
            case "4":
                pesquisarClientePorNome();
                break;
            case "5":
                listarTodosClientes();
                break;
            default:
                JOptionPane.showMessageDialog(null, "Opção inválida.");
                break;
        }
    }

    private static void buscarClientePorId() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do cliente:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            Cliente cliente = clienteDAO.buscarPorId(id);
            if (cliente != null) {
                JOptionPane.showMessageDialog(null, "Cliente encontrado:\n" + cliente);
            } else {
                JOptionPane.showMessageDialog(null, "Cliente não encontrado.");
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        }
    }

    private static void buscarClientePorCpf() {
        String cpf = JOptionPane.showInputDialog("Digite o CPF do cliente:");
        if (cpf == null) {
            return;
        }

        Cliente cliente = clienteDAO.buscarPorCpf(cpf);
        if (cliente != null) {
            JOptionPane.showMessageDialog(null, "Cliente encontrado:\n" + cliente);
        } else {
            JOptionPane.showMessageDialog(null, "Cliente com CPF " + cpf + " não encontrado.");
        }
    }

    private static void buscarClientePorCnpj() {
        String cnpj = JOptionPane.showInputDialog("Digite o CNPJ do cliente:");
        if (cnpj == null) {
            return;
        }

        Cliente cliente = clienteDAO.buscarPorCnpj(cnpj);
        if (cliente != null) {
            JOptionPane.showMessageDialog(null, "Cliente encontrado:\n" + cliente);
        } else {
            JOptionPane.showMessageDialog(null, "Cliente com CNPJ " + cnpj + " não encontrado.");
        }
    }

    private static void pesquisarClientePorNome() {
        String nome = JOptionPane.showInputDialog("Digite o nome do cliente:");
        if (nome == null) {
            return;
        }

        List<Cliente> clientes = clienteDAO.pesquisarPorNome(nome);
        if (!clientes.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            sb.append("Clientes encontrados com o nome ").append(nome).append(":\n");
            for (Cliente cliente : clientes) {
                sb.append(cliente).append("\n");
            }
            JOptionPane.showMessageDialog(null, sb.toString());
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum cliente encontrado com o nome " + nome);
        }
    }

    private static void listarTodosClientes() {
        List<Cliente> clientes = clienteDAO.buscarTodos();
        if (!clientes.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            sb.append("Lista de todos os clientes:\n");
            for (Cliente cliente : clientes) {
                sb.append(cliente).append("\n");
            }
            JOptionPane.showMessageDialog(null, sb.toString());
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum cliente cadastrado.");
        }
    }

    private static void cadastrarCliente() {
        String[] tiposCliente = {"Cliente Físico", "Cliente Jurídico"};
        String tipoCliente = (String) JOptionPane.showInputDialog(null,
                "Selecione o tipo de cliente:",
                "Cadastro de Cliente",
                JOptionPane.PLAIN_MESSAGE,
                null,
                tiposCliente,
                tiposCliente[0]);

        if (tipoCliente == null) {
            return;
        }

        switch (tipoCliente) {
            case "Cliente Físico":
                cadastrarClienteFisico();
                break;
            case "Cliente Jurídico":
                cadastrarClienteJuridico();
                break;
            default:
                JOptionPane.showMessageDialog(null, "Tipo de cliente inválido.");
                break;
        }
    }

    private static void cadastrarClienteFisico() {
        String cpf = JOptionPane.showInputDialog("Digite o CPF:");
        if (cpf == null) {
            return;
        }

        String nome = JOptionPane.showInputDialog("Digite o nome:");
        if (nome == null) {
            return;
        }

        String endereco = JOptionPane.showInputDialog("Digite o endereço:");
        if (endereco == null) {
            return;
        }

        String telefone = JOptionPane.showInputDialog("Digite o telefone:");
        if (telefone == null) {
            return;
        }

        String email = JOptionPane.showInputDialog("Digite o email:");
        if (email == null) {
            return;
        }

        ClienteFisico cliente = new ClienteFisico(cpf, null, nome, endereco, telefone, email);

        try {
            if (clienteDAO.inserir(cliente)) {
                JOptionPane.showMessageDialog(null, "Cliente físico cadastrado com sucesso:\n" + cliente);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível cadastrar o cliente físico.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao cadastrar cliente físico: " + e.getMessage());
        }
    }

    private static void cadastrarClienteJuridico() {
        String cnpj = JOptionPane.showInputDialog("Digite o CNPJ:");
        if (cnpj == null) {
            return;
        }

        String nomeFantasia = JOptionPane.showInputDialog("Digite o nome fantasia:");
        if (nomeFantasia == null) {
            return;
        }

        String endereco = JOptionPane.showInputDialog("Digite o endereço:");
        if (endereco == null) {
            return;
        }

        String telefone = JOptionPane.showInputDialog("Digite o telefone:");
        if (telefone == null) {
            return;
        }

        String email = JOptionPane.showInputDialog("Digite o email:");
        if (email == null) {
            return;
        }

        ClienteJuridico cliente = new ClienteJuridico(cnpj, null, nomeFantasia, endereco, telefone, email);

        try {
            if (clienteDAO.inserir(cliente)) {
                JOptionPane.showMessageDialog(null, "Cliente jurídico cadastrado com sucesso:\n" + cliente);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível cadastrar o cliente jurídico.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao cadastrar cliente jurídico: " + e.getMessage());
        }
    }

    private static void editarCliente() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do cliente que deseja editar:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            Cliente cliente = clienteDAO.buscarPorId(id);
            if (cliente == null) {
                JOptionPane.showMessageDialog(null, "Cliente não encontrado.");
                return;
            }

            String[] tiposCliente = {"Cliente Físico", "Cliente Jurídico"};
            String tipoCliente = (String) JOptionPane.showInputDialog(null,
                    "Selecione o tipo de cliente:",
                    "Edição de Cliente",
                    JOptionPane.PLAIN_MESSAGE,
                    null,
                    tiposCliente,
                    tiposCliente[0]);

            if (tipoCliente == null) {
                return;
            }

            switch (tipoCliente) {
                case "Cliente Físico":
                    if (!(cliente instanceof ClienteFisico)) {
                        JOptionPane.showMessageDialog(null, "Tipo de cliente físico inválido.");
                        return;
                    }
                    editarClienteFisico((ClienteFisico) cliente);
                    break;
                case "Cliente Jurídico":
                    if (!(cliente instanceof ClienteJuridico)) {
                        JOptionPane.showMessageDialog(null, "Tipo de cliente jurídico inválido.");
                        return;
                    }
                    editarClienteJuridico((ClienteJuridico) cliente);
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Tipo de cliente inválido.");
                    break;
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        }
    }

    private static void editarClienteFisico(ClienteFisico cliente) {
        String nome = JOptionPane.showInputDialog("Digite o nome:", cliente.getNome());
        if (nome == null) {
            return;
        }

        String endereco = JOptionPane.showInputDialog("Digite o endereço:", cliente.getEndereco());
        if (endereco == null) {
            return;
        }

        String telefone = JOptionPane.showInputDialog("Digite o telefone:", cliente.getTelefone());
        if (telefone == null) {
            return;
        }

        String email = JOptionPane.showInputDialog("Digite o email:", cliente.getEmail());
        if (email == null) {
            return;
        }

        cliente.setNome(nome);
        cliente.setEndereco(endereco);
        cliente.setTelefone(telefone);
        cliente.setEmail(email);

        try {
            if (clienteDAO.atualizar(cliente)) {
                JOptionPane.showMessageDialog(null, "Cliente físico atualizado com sucesso:\n" + cliente);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível atualizar o cliente físico.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao atualizar cliente físico: " + e.getMessage());
        }
    }

    private static void editarClienteJuridico(ClienteJuridico cliente) {
        String nomeFantasia = JOptionPane.showInputDialog("Digite o nome fantasia:", cliente.getNomeFantasia());
        if (nomeFantasia == null) {
            return;
        }

        String endereco = JOptionPane.showInputDialog("Digite o endereço:", cliente.getEndereco());
        if (endereco == null) {
            return;
        }

        String telefone = JOptionPane.showInputDialog("Digite o telefone:", cliente.getTelefone());
        if (telefone == null) {
            return;
        }

        String email = JOptionPane.showInputDialog("Digite o email:", cliente.getEmail());
        if (email == null) {
            return;
        }

        cliente.setNomeFantasia(nomeFantasia);
        cliente.setEndereco(endereco);
        cliente.setTelefone(telefone);
        cliente.setEmail(email);

        try {
            if (clienteDAO.atualizar(cliente)) {
                JOptionPane.showMessageDialog(null, "Cliente jurídico atualizado com sucesso:\n" + cliente);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível atualizar o cliente jurídico.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao atualizar cliente jurídico: " + e.getMessage());
        }
    }

    private static void excluirCliente() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do cliente que deseja excluir:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            Cliente cliente = clienteDAO.buscarPorId(id);
            if (cliente == null) {
                JOptionPane.showMessageDialog(null, "Cliente não encontrado.");
                return;
            }

            int confirmacao = JOptionPane.showConfirmDialog(null, "Tem certeza que deseja excluir o cliente:\n" + cliente, "Confirmar Exclusão", JOptionPane.YES_NO_OPTION);
            if (confirmacao == JOptionPane.YES_OPTION) {
                if (clienteDAO.excluir(cliente)) {
                    JOptionPane.showMessageDialog(null, "Cliente excluído com sucesso.");
                } else {
                    JOptionPane.showMessageDialog(null, "Não foi possível excluir o cliente.");
                }
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        }
    }

    // Métodos para o menu de Veículos

    private static void menuVeiculos() {
        boolean voltar = false;
        while (!voltar) {
            String opcaoVeiculo = JOptionPane.showInputDialog(
                    "MENU VEÍCULOS\n" +
                            "1 Pesquisar Veículo\n" +
                            "2 Cadastrar Veículo\n" +
                            "3 Editar Veículo\n" +
                            "4 Excluir Veículo\n" +
                            "5 Voltar ao Menu Principal\n" +
                            "Escolha uma opção:");

            if (opcaoVeiculo == null) {
                voltar = true;
                continue;
            }

            switch (opcaoVeiculo) {
                case "1":
                    menuPesquisarVeiculo();
                    break;
                case "2":
                    cadastrarVeiculo();
                    break;
                case "3":
                    editarVeiculo();
                    break;
                case "4":
                    excluirVeiculo();
                    break;
                case "5":
                    voltar = true;
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção inválida.");
                    break;
            }
        }
    }

    private static void menuPesquisarVeiculo() {
        String opcaoPesquisaVeiculo = JOptionPane.showInputDialog(
                "PESQUISAR VEÍCULO\n" +
                        "1 Buscar por ID\n" +
                        "2 Pesquisar por Placa\n" +
                        "3 Pesquisar por Marca\n" +
                        "4 Pesquisar por Categoria\n" +
                        "5 Pesquisar por Câmbio\n" +
                        "6 Listar Todos os Veículos\n" +
                        "Escolha uma opção:");

        if (opcaoPesquisaVeiculo == null) {
            return;
        }

        switch (opcaoPesquisaVeiculo) {
            case "1":
                buscarVeiculoPorId();
                break;
            case "2":
                buscarVeiculoPorPlaca();
                break;
            case "3":
                pesquisarVeiculoPorMarca();
                break;
            case "4":
                pesquisarVeiculoPorCategoria();
                break;
            case "5":
                pesquisarVeiculoPorCambio();
                break;
            case "6":
                listarTodosVeiculos();
                break;
            default:
                JOptionPane.showMessageDialog(null, "Opção inválida.");
                break;
        }
    }

    private static void buscarVeiculoPorId() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do veículo:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            Veiculo veiculo = veiculoDAO.buscarPorId(id);
            if (veiculo != null) {
                JOptionPane.showMessageDialog(null, "Veículo encontrado:\n" + veiculo);
            } else {
                JOptionPane.showMessageDialog(null, "Veículo não encontrado.");
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        }
    }

    private static void buscarVeiculoPorPlaca() {
        String placa = JOptionPane.showInputDialog("Digite a placa do veículo:");
        if (placa == null) {
            return;
        }

        Veiculo veiculo = veiculoDAO.buscarPorPlaca(placa);
        if (veiculo != null) {
            JOptionPane.showMessageDialog(null, "Veículo encontrado:\n" + veiculo);
        } else {
            JOptionPane.showMessageDialog(null, "Veículo com placa " + placa + " não encontrado.");
        }
    }

    private static void pesquisarVeiculoPorMarca() {
        String marca = JOptionPane.showInputDialog("Digite a marca do veículo:");
        if (marca == null) {
            return;
        }

        List<Veiculo> veiculos = veiculoDAO.pesquisarPorMarca(marca);
        if (!veiculos.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            sb.append("Veículos encontrados da marca ").append(marca).append(":\n");
            for (Veiculo veiculo : veiculos) {
                sb.append(veiculo).append("\n");
            }
            JOptionPane.showMessageDialog(null, sb.toString());
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum veículo encontrado da marca " + marca);
        }
    }

    private static void pesquisarVeiculoPorCategoria() {
        String categoriaStr = JOptionPane.showInputDialog("Digite a categoria do veículo:");
        if (categoriaStr == null) {
            return;
        }

        try {
            CategoriaVeiculo categoria = CategoriaVeiculo.valueOf(categoriaStr.toUpperCase());
            List<Veiculo> veiculos = veiculoDAO.pesquisarPorCategoria(categoria);
            if (!veiculos.isEmpty()) {
                StringBuilder sb = new StringBuilder();
                sb.append("Veículos encontrados da categoria ").append(categoria).append(":\n");
                for (Veiculo veiculo : veiculos) {
                    sb.append(veiculo).append("\n");
                }
                JOptionPane.showMessageDialog(null, sb.toString());
            } else {
                JOptionPane.showMessageDialog(null, "Nenhum veículo encontrado da categoria " + categoria);
            }
        } catch (IllegalArgumentException e) {
            JOptionPane.showMessageDialog(null, "Categoria de veículo inválida.");
        }
    }

    private static void pesquisarVeiculoPorCambio() {
        String tipoCambioStr = JOptionPane.showInputDialog("Digite o tipo de câmbio do veículo (AUTOMATICO ou MANUAL):");
        if (tipoCambioStr == null) {
            return;
        }

        try {
            TipoTransmissao tipoCambio = TipoTransmissao.valueOf(tipoCambioStr.toUpperCase());
            List<Veiculo> veiculos = veiculoDAO.pesquisarPorCambio(tipoCambio);
            if (!veiculos.isEmpty()) {
                StringBuilder sb = new StringBuilder();
                sb.append("Veículos encontrados com câmbio ").append(tipoCambio).append(":\n");
                for (Veiculo veiculo : veiculos) {
                    sb.append(veiculo).append("\n");
                }
                JOptionPane.showMessageDialog(null, sb.toString());
            } else {
                JOptionPane.showMessageDialog(null, "Nenhum veículo encontrado com câmbio " + tipoCambio);
            }
        } catch (IllegalArgumentException e) {
            JOptionPane.showMessageDialog(null, "Tipo de câmbio inválido.");
        }
    }

    private static void listarTodosVeiculos() {
        List<Veiculo> veiculos = veiculoDAO.buscarTodos();
        if (!veiculos.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            sb.append("Lista de todos os veículos:\n");
            for (Veiculo veiculo : veiculos) {
                sb.append(veiculo).append("\n");
            }
            JOptionPane.showMessageDialog(null, sb.toString());
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum veículo cadastrado.");
        }
    }

    private static void cadastrarVeiculo() {
        String[] tiposVeiculo = {"Carro", "Caminhão", "Moto", "Ônibus"};
        String tipoVeiculo = (String) JOptionPane.showInputDialog(null,
                "Selecione o tipo de veículo:",
                "Cadastro de Veículo",
                JOptionPane.PLAIN_MESSAGE,
                null,
                tiposVeiculo,
                tiposVeiculo[0]);

        if (tipoVeiculo == null) {
            return;
        }

        switch (tipoVeiculo) {
            case "Carro":
                cadastrarCarro();
                break;
            case "Caminhão":
                cadastrarCaminhao();
                break;
            case "Moto":
                cadastrarMoto();
                break;
            case "Ônibus":
                cadastrarOnibus();
                break;
            default:
                JOptionPane.showMessageDialog(null, "Tipo de veículo inválido.");
                break;
        }
    }

    private static void cadastrarCarro() {
        String placa = obterPlaca();
        if (placa == null) {
            return;
        }

        String marca = JOptionPane.showInputDialog("Digite a marca do carro:");
        if (marca == null) {
            return;
        }

        String modelo = JOptionPane.showInputDialog("Digite o modelo do carro:");
        if (modelo == null) {
            return;
        }

        String cor = JOptionPane.showInputDialog("Digite a cor do carro:");
        if (cor == null) {
            return;
        }

        TipoTransmissao tipoCambio = selecionarTipoCambio();
        if (tipoCambio == null) {
            return;
        }

        Carro carro = new Carro(placa, marca, modelo, cor, tipoCambio);

        try {
            if (veiculoDAO.inserir(carro)) {
                JOptionPane.showMessageDialog(null, "Carro cadastrado com sucesso:\n" + carro);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível cadastrar o carro.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao cadastrar carro: " + e.getMessage());
        }
    }

    private static void cadastrarCaminhao() {
        String placa = obterPlaca();
        if (placa == null) {
            return;
        }

        String marca = JOptionPane.showInputDialog("Digite a marca do caminhão:");
        if (marca == null) {
            return;
        }

        String modelo = JOptionPane.showInputDialog("Digite o modelo do caminhão:");
        if (modelo == null) {
            return;
        }

        int capacidadeCarga = obterCapacidadeCarga();
        if (capacidadeCarga == -1) {
            return;
        }

        Caminhao caminhao = new Caminhao(placa, marca, modelo, capacidadeCarga);

        try {
            if (veiculoDAO.inserir(caminhao)) {
                JOptionPane.showMessageDialog(null, "Caminhão cadastrado com sucesso:\n" + caminhao);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível cadastrar o caminhão.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao cadastrar caminhão: " + e.getMessage());
        }
    }

    private static void cadastrarMoto() {
        String placa = obterPlaca();
        if (placa == null) {
            return;
        }

        String marca = JOptionPane.showInputDialog("Digite a marca da moto:");
        if (marca == null) {
            return;
        }

        String modelo = JOptionPane.showInputDialog("Digite o modelo da moto:");
        if (modelo == null) {
            return;
        }

        int cilindradas = obterCilindradas();
        if (cilindradas == -1) {
            return;
        }

        Moto moto = new Moto(placa, marca, modelo, cilindradas);

        try {
            if (veiculoDAO.inserir(moto)) {
                JOptionPane.showMessageDialog(null, "Moto cadastrada com sucesso:\n" + moto);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível cadastrar a moto.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao cadastrar moto: " + e.getMessage());
        }
    }

    private static void cadastrarOnibus() {
        String placa = obterPlaca();
        if (placa == null) {
            return;
        }

        String marca = JOptionPane.showInputDialog("Digite a marca do ônibus:");
        if (marca == null) {
            return;
        }

        String modelo = JOptionPane.showInputDialog("Digite o modelo do ônibus:");
        if (modelo == null) {
            return;
        }

        int capacidadePassageiros = obterCapacidadePassageiros();
        if (capacidadePassageiros == -1) {
            return;
        }

        Onibus onibus = new Onibus(placa, marca, modelo, capacidadePassageiros);

        try {
            if (veiculoDAO.inserir(onibus)) {
                JOptionPane.showMessageDialog(null, "Ônibus cadastrado com sucesso:\n" + onibus);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível cadastrar o ônibus.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao cadastrar ônibus: " + e.getMessage());
        }
    }

    private static String obterPlaca() {
        String placa = JOptionPane.showInputDialog("Digite a placa:");
        if (placa == null) {
            return null;
        }

        while (!Veiculo.validarPlaca(placa)) {
            JOptionPane.showMessageDialog(null, "Placa inválida. Formato esperado: AAA-0000.");
            placa = JOptionPane.showInputDialog("Digite a placa novamente:");
            if (placa == null) {
                return null;
            }
        }

        return placa;
    }

    private static TipoTransmissao selecionarTipoCambio() {
        String tipoCambioStr = JOptionPane.showInputDialog("Digite o tipo de câmbio (AUTOMATICO ou MANUAL):");
        if (tipoCambioStr == null) {
            return null;
        }

        try {
            return TipoTransmissao.valueOf(tipoCambioStr.toUpperCase());
        } catch (IllegalArgumentException e) {
            JOptionPane.showMessageDialog(null, "Tipo de câmbio inválido.");
            return null;
        }
    }

    private static int obterCapacidadeCarga() {
        String inputCapacidade = JOptionPane.showInputDialog("Digite a capacidade de carga:");
        if (inputCapacidade == null) {
            return -1;
        }

        try {
            return Integer.parseInt(inputCapacidade);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Capacidade de carga inválida. Digite um número inteiro.");
            return -1;
        }
    }

    private static int obterCilindradas() {
        String inputCilindradas = JOptionPane.showInputDialog("Digite as cilindradas:");
        if (inputCilindradas == null) {
            return -1;
        }

        try {
            return Integer.parseInt(inputCilindradas);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Cilindradas inválidas. Digite um número inteiro.");
            return -1;
        }
    }

    private static int obterCapacidadePassageiros() {
        String inputCapacidade = JOptionPane.showInputDialog("Digite a capacidade de passageiros:");
        if (inputCapacidade == null) {
            return -1;
        }

        try {
            return Integer.parseInt(inputCapacidade);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Capacidade de passageiros inválida. Digite um número inteiro.");
            return -1;
        }
    }

    private static void editarVeiculo() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do veículo que deseja editar:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            Veiculo veiculo = veiculoDAO.buscarPorId(id);
            if (veiculo == null) {
                JOptionPane.showMessageDialog(null, "Veículo não encontrado.");
                return;
            }

            String[] tiposVeiculo = {"Carro", "Caminhão", "Moto", "Ônibus"};
            String tipoVeiculo = (String) JOptionPane.showInputDialog(null,
                    "Selecione o tipo de veículo:",
                    "Edição de Veículo",
                    JOptionPane.PLAIN_MESSAGE,
                    null,
                    tiposVeiculo,
                    tiposVeiculo[0]);

            if (tipoVeiculo == null) {
                return;
            }

            switch (tipoVeiculo) {
                case "Carro":
                    if (!(veiculo instanceof Carro)) {
                        JOptionPane.showMessageDialog(null, "Tipo de veículo carro inválido.");
                        return;
                    }
                    editarCarro((Carro) veiculo);
                    break;
                case "Caminhão":
                    if (!(veiculo instanceof Caminhao)) {
                        JOptionPane.showMessageDialog(null, "Tipo de veículo caminhão inválido.");
                        return;
                    }
                    editarCaminhao((Caminhao) veiculo);
                    break;
                case "Moto":
                    if (!(veiculo instanceof Moto)) {
                        JOptionPane.showMessageDialog(null, "Tipo de veículo moto inválido.");
                        return;
                    }
                    editarMoto((Moto) veiculo);
                    break;
                case "Ônibus":
                    if (!(veiculo instanceof Onibus)) {
                        JOptionPane.showMessageDialog(null, "Tipo de veículo ônibus inválido.");
                        return;
                    }
                    editarOnibus((Onibus) veiculo);
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Tipo de veículo inválido.");
                    break;
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        }
    }

    private static void editarCarro(Carro carro) {
        String marca = JOptionPane.showInputDialog("Digite a marca:", carro.getMarca());
        if (marca == null) {
            return;
        }

        String modelo = JOptionPane.showInputDialog("Digite o modelo:", carro.getModelo());
        if (modelo == null) {
            return;
        }

        String cor = JOptionPane.showInputDialog("Digite a cor:", carro.getCor());
        if (cor == null) {
            return;
        }

        TipoTransmissao tipoCambio = selecionarTipoCambio();
        if (tipoCambio == null) {
            return;
        }

        carro.setMarca(marca);
        carro.setModelo(modelo);
        carro.setCor(cor);
        carro.setTipoCambio(tipoCambio);

        try {
            if (veiculoDAO.atualizar(carro)) {
                JOptionPane.showMessageDialog(null, "Carro atualizado com sucesso:\n" + carro);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível atualizar o carro.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao atualizar carro: " + e.getMessage());
        }
    }

    private static void editarCaminhao(Caminhao caminhao) {
        String marca = JOptionPane.showInputDialog("Digite a marca:", caminhao.getMarca());
        if (marca == null) {
            return;
        }

        String modelo = JOptionPane.showInputDialog("Digite o modelo:", caminhao.getModelo());
        if (modelo == null) {
            return;
        }

        int capacidadeCarga = obterCapacidadeCarga();
        if (capacidadeCarga == -1) {
            return;
        }

        caminhao.setMarca(marca);
        caminhao.setModelo(modelo);
        caminhao.setCapacidadeCarga(capacidadeCarga);

        try {
            if (veiculoDAO.atualizar(caminhao)) {
                JOptionPane.showMessageDialog(null, "Caminhão atualizado com sucesso:\n" + caminhao);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível atualizar o caminhão.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao atualizar caminhão: " + e.getMessage());
        }
    }

    private static void editarMoto(Moto moto) {
        String marca = JOptionPane.showInputDialog("Digite a marca:", moto.getMarca());
        if (marca == null) {
            return;
        }

        String modelo = JOptionPane.showInputDialog("Digite o modelo:", moto.getModelo());
        if (modelo == null) {
            return;
        }

        int cilindradas = obterCilindradas();
        if (cilindradas == -1) {
            return;
        }

        moto.setMarca(marca);
        moto.setModelo(modelo);
        moto.setCilindradas(cilindradas);

        try {
            if (veiculoDAO.atualizar(moto)) {
                JOptionPane.showMessageDialog(null, "Moto atualizada com sucesso:\n" + moto);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível atualizar a moto.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao atualizar moto: " + e.getMessage());
        }
    }

    private static void editarOnibus(Onibus onibus) {
        String marca = JOptionPane.showInputDialog("Digite a marca:", onibus.getMarca());
        if (marca == null) {
            return;
        }

        String modelo = JOptionPane.showInputDialog("Digite o modelo:", onibus.getModelo());
        if (modelo == null) {
            return;
        }

        int capacidadePassageiros = obterCapacidadePassageiros();
        if (capacidadePassageiros == -1) {
            return;
        }

        onibus.setMarca(marca);
        onibus.setModelo(modelo);
        onibus.setCapacidadePassageiros(capacidadePassageiros);

        try {
            if (veiculoDAO.atualizar(onibus)) {
                JOptionPane.showMessageDialog(null, "Ônibus atualizado com sucesso:\n" + onibus);
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível atualizar o ônibus.");
            }
        } catch (ParametroIncompativelException e) {
            JOptionPane.showMessageDialog(null, "Erro ao atualizar ônibus: " + e.getMessage());
        }
    }

    private static void excluirVeiculo() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do veículo que deseja excluir:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            Veiculo veiculo = veiculoDAO.buscarPorId(id);
            if (veiculo == null) {
                JOptionPane.showMessageDialog(null, "Veículo não encontrado.");
                return;
            }

            int confirmacao = JOptionPane.showConfirmDialog(null, "Tem certeza que deseja excluir o veículo:\n" + veiculo, "Confirmar Exclusão", JOptionPane.YES_NO_OPTION);
            if (confirmacao == JOptionPane.YES_OPTION) {
                if (veiculoDAO.excluir(veiculo)) {
                    JOptionPane.showMessageDialog(null, "Veículo excluído com sucesso.");
                } else {
                    JOptionPane.showMessageDialog(null, "Não foi possível excluir o veículo.");
                }
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        }
    }

    // Métodos para o menu de Contratos de Aluguel

    private static void menuContratosAluguel() {
        boolean voltar = false;
        while (!voltar) {
            String opcaoContrato = JOptionPane.showInputDialog(
                    "MENU CONTRATOS DE ALUGUEL\n" +
                            "1 Pesquisar Contrato de Aluguel\n" +
                            "2 Cadastrar Contrato de Aluguel\n" +
                            "3 Editar Contrato de Aluguel\n" +
                            "4 Excluir Contrato de Aluguel\n" +
                            "5 Voltar ao Menu Principal\n" +
                            "Escolha uma opção:");

            if (opcaoContrato == null) {
                voltar = true;
                continue;
            }

            switch (opcaoContrato) {
                case "1":
                    menuPesquisarContratoAluguel();
                    break;
                case "2":
                    cadastrarContratoAluguel();
                    break;
                case "3":
                    editarContratoAluguel();
                    break;
                case "4":
                    excluirContratoAluguel();
                    break;
                case "5":
                    voltar = true;
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção inválida.");
                    break;
            }
        }
    }

    private static void menuPesquisarContratoAluguel() {
        String opcaoPesquisaContrato = JOptionPane.showInputDialog(
                "PESQUISAR CONTRATO DE ALUGUEL\n" +
                        "1 Buscar por ID\n" +
                        "2 Pesquisar por Cliente\n" +
                        "3 Listar Todos os Contratos\n" +
                        "4 Voltar\n" +
                        "Escolha uma opção:");

        if (opcaoPesquisaContrato == null) {
            return;
        }

        switch (opcaoPesquisaContrato) {
            case "1":
                pesquisarContratoAluguelPorId();
                break;
            case "2":
                pesquisarContratoAluguelPorCliente();
                break;
            case "3":
                listarTodosContratosAluguel();
                break;
            case "4":
                break;
            default:
                JOptionPane.showMessageDialog(null, "Opção inválida.");
                break;
        }
    }

    private static void pesquisarContratoAluguelPorId() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do contrato de aluguel:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            ContratoAluguel contrato = contratoAluguelDAO.buscarPorId(id);
            if (contrato != null) {
                JOptionPane.showMessageDialog(null, "Contrato de Aluguel encontrado:\n" + contrato);
            } else {
                JOptionPane.showMessageDialog(null, "Contrato de Aluguel não encontrado.");
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        }
    }

    private static void pesquisarContratoAluguelPorCliente() {
        String inputNomeCliente = JOptionPane.showInputDialog("Digite o nome do cliente:");
        if (inputNomeCliente == null) {
            return;
        }

        List<ContratoAluguel> contratos = contratoAluguelDAO.buscarPorCliente(inputNomeCliente);
        if (!contratos.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            sb.append("Contratos de Aluguel encontrados para o cliente ").append(inputNomeCliente).append(":\n");
            for (ContratoAluguel contrato : contratos) {
                sb.append(contrato).append("\n");
            }
            JOptionPane.showMessageDialog(null, sb.toString());
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum contrato de aluguel encontrado para o cliente " + inputNomeCliente);
        }
    }

    private static void listarTodosContratosAluguel() {
        List<ContratoAluguel> contratos = contratoAluguelDAO.buscarTodos();
        if (!contratos.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            sb.append("Lista de todos os contratos de aluguel:\n");
            for (ContratoAluguel contrato : contratos) {
                sb.append(contrato).append("\n");
            }
            JOptionPane.showMessageDialog(null, sb.toString());
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum contrato de aluguel cadastrado.");
        }
    }

    private static void cadastrarContratoAluguel() {
        String[] tiposCliente = {"Pessoa Física", "Pessoa Jurídica"};
        String tipoCliente = (String) JOptionPane.showInputDialog(null,
                "Selecione o tipo de cliente:",
                "Cadastro de Contrato de Aluguel",
                JOptionPane.PLAIN_MESSAGE,
                null,
                tiposCliente,
                tiposCliente[0]);

        if (tipoCliente == null) {
            return;
        }

        switch (tipoCliente) {
            case "Pessoa Física":
                cadastrarContratoAluguelPessoaFisica();
                break;
            case "Pessoa Jurídica":
                cadastrarContratoAluguelPessoaJuridica();
                break;
            default:
                JOptionPane.showMessageDialog(null, "Tipo de cliente inválido.");
                break;
        }
    }

    private static void cadastrarContratoAluguelPessoaFisica() {
        String clienteStr = JOptionPane.showInputDialog("Digite o CPF do cliente:");
        if (clienteStr == null) {
            return;
        }

        Cliente cliente = clienteDAO.buscarPorCpf(clienteStr);
        if (cliente == null) {
            JOptionPane.showMessageDialog(null, "Cliente não encontrado.");
            return;
        }

        String veiculoStr = JOptionPane.showInputDialog("Digite o ID do veículo a ser alugado:");
        if (veiculoStr == null) {
            return;
        }

        try {
            int idVeiculo = Integer.parseInt(veiculoStr);
            Veiculo veiculo = veiculoDAO.buscarPorId(idVeiculo);
            if (veiculo == null) {
                JOptionPane.showMessageDialog(null, "Veículo não encontrado.");
                return;
            }

            String dataInicioStr = JOptionPane.showInputDialog("Digite a data de início (formato dd/MM/yyyy):");
            if (dataInicioStr == null) {
                return;
            }

            LocalDate dataInicio = LocalDate.parse(dataInicioStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

            String dataFimStr = JOptionPane.showInputDialog("Digite a data de término (formato dd/MM/yyyy):");
            if (dataFimStr == null) {
                return;
            }

            LocalDate dataFim = LocalDate.parse(dataFimStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

            ContratoAluguel contrato = new ContratoAluguel(cliente, veiculo, dataInicio, dataFim);

            try {
                if (contratoAluguelDAO.inserir(contrato)) {
                    JOptionPane.showMessageDialog(null, "Contrato de Aluguel cadastrado com sucesso:\n" + contrato);
                } else {
                    JOptionPane.showMessageDialog(null, "Não foi possível cadastrar o contrato de aluguel.");
                }
            } catch (ParametroIncompativelException e) {
                JOptionPane.showMessageDialog(null, "Erro ao cadastrar contrato de aluguel: " + e.getMessage());
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID do veículo inválido. Digite um número inteiro.");
        } catch (DateTimeParseException e) {
            JOptionPane.showMessageDialog(null, "Data em formato inválido. Use o formato dd/MM/yyyy.");
        }
    }

    private static void cadastrarContratoAluguelPessoaJuridica() {
        String clienteStr = JOptionPane.showInputDialog("Digite o CNPJ do cliente:");
        if (clienteStr == null) {
            return;
        }

        Cliente cliente = clienteDAO.buscarPorCnpj(clienteStr);
        if (cliente == null) {
            JOptionPane.showMessageDialog(null, "Cliente não encontrado.");
            return;
        }

        String veiculoStr = JOptionPane.showInputDialog("Digite o ID do veículo a ser alugado:");
        if (veiculoStr == null) {
            return;
        }

        try {
            int idVeiculo = Integer.parseInt(veiculoStr);
            Veiculo veiculo = veiculoDAO.buscarPorId(idVeiculo);
            if (veiculo == null) {
                JOptionPane.showMessageDialog(null, "Veículo não encontrado.");
                return;
            }

            String dataInicioStr = JOptionPane.showInputDialog("Digite a data de início (formato dd/MM/yyyy):");
            if (dataInicioStr == null) {
                return;
            }

            LocalDate dataInicio = LocalDate.parse(dataInicioStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

            String dataFimStr = JOptionPane.showInputDialog("Digite a data de término (formato dd/MM/yyyy):");
            if (dataFimStr == null) {
                return;
            }

            LocalDate dataFim = LocalDate.parse(dataFimStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

            ContratoAluguel contrato = new ContratoAluguel(cliente, veiculo, dataInicio, dataFim);

            try {
                if (contratoAluguelDAO.inserir(contrato)) {
                    JOptionPane.showMessageDialog(null, "Contrato de Aluguel cadastrado com sucesso:\n" + contrato);
                } else {
                    JOptionPane.showMessageDialog(null, "Não foi possível cadastrar o contrato de aluguel.");
                }
            } catch (ParametroIncompativelException e) {
                JOptionPane.showMessageDialog(null, "Erro ao cadastrar contrato de aluguel: " + e.getMessage());
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID do veículo inválido. Digite um número inteiro.");
        } catch (DateTimeParseException e) {
            JOptionPane.showMessageDialog(null, "Data em formato inválido. Use o formato dd/MM/yyyy.");
        }
    }

    private static void editarContratoAluguel() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do contrato de aluguel que deseja editar:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            ContratoAluguel contrato = contratoAluguelDAO.buscarPorId(id);
            if (contrato == null) {
                JOptionPane.showMessageDialog(null, "Contrato de Aluguel não encontrado.");
                return;
            }

            String dataInicioStr = JOptionPane.showInputDialog("Digite a nova data de início (formato dd/MM/yyyy):", contrato.getDataInicio().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")));
            if (dataInicioStr == null) {
                return;
            }

            LocalDate dataInicio = LocalDate.parse(dataInicioStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

            String dataFimStr = JOptionPane.showInputDialog("Digite a nova data de término (formato dd/MM/yyyy):", contrato.getDataFim().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")));
            if (dataFimStr == null) {
                return;
            }

            LocalDate dataFim = LocalDate.parse(dataFimStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

            contrato.setDataInicio(dataInicio);
            contrato.setDataFim(dataFim);

            try {
                if (contratoAluguelDAO.atualizar(contrato)) {
                    JOptionPane.showMessageDialog(null, "Contrato de Aluguel atualizado com sucesso:\n" + contrato);
                } else {
                    JOptionPane.showMessageDialog(null, "Não foi possível atualizar o contrato de aluguel.");
                }
            } catch (ParametroIncompativelException e) {
                JOptionPane.showMessageDialog(null, "Erro ao atualizar contrato de aluguel: " + e.getMessage());
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        } catch (DateTimeParseException e) {
            JOptionPane.showMessageDialog(null, "Data em formato inválido. Use o formato dd/MM/yyyy.");
        }
    }

    private static void excluirContratoAluguel() {
        String inputId = JOptionPane.showInputDialog("Digite o ID do contrato de aluguel que deseja excluir:");
        if (inputId == null) {
            return;
        }

        try {
            int id = Integer.parseInt(inputId);
            ContratoAluguel contrato = contratoAluguelDAO.buscarPorId(id);
            if (contrato == null) {
                JOptionPane.showMessageDialog(null, "Contrato de Aluguel não encontrado.");
                return;
            }

            int confirmacao = JOptionPane.showConfirmDialog(null, "Tem certeza que deseja excluir o contrato de aluguel:\n" + contrato, "Confirmar Exclusão", JOptionPane.YES_NO_OPTION);
            if (confirmacao == JOptionPane.YES_OPTION) {
                if (contratoAluguelDAO.excluir(contrato)) {
                    JOptionPane.showMessageDialog(null, "Contrato de Aluguel excluído com sucesso.");
                } else {
                    JOptionPane.showMessageDialog(null, "Não foi possível excluir o contrato de aluguel.");
                }
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "ID inválido. Digite um número inteiro.");
        }
    }

    // Métodos Auxiliares

    private static TipoTransmissao selecionarTipoCambio() {
        String[] tiposCambio = {"Manual", "Automático"};
        String tipoCambio = (String) JOptionPane.showInputDialog(null,
                "Selecione o tipo de câmbio:",
                "Edição de Veículo",
                JOptionPane.PLAIN_MESSAGE,
                null,
                tiposCambio,
                tiposCambio[0]);

        if (tipoCambio == null) {
            return null;
        }

        return TipoTransmissao.valueOf(tipoCambio.toUpperCase());
    }

    private static int obterCapacidadeCarga() {
        String inputCapacidade = JOptionPane.showInputDialog("Digite a capacidade de carga:");
        if (inputCapacidade == null) {
            return -1;
        }

        try {
            return Integer.parseInt(inputCapacidade);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Capacidade de carga inválida. Digite um número inteiro.");
            return -1;
        }
    }

    private static int obterCilindradas() {
        String inputCilindradas = JOptionPane.showInputDialog("Digite as cilindradas:");
        if (inputCilindradas == null) {
            return -1;
        }

        try {
            return Integer.parseInt(inputCilindradas);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Cilindradas inválidas. Digite um número inteiro.");
            return -1;
        }
    }

    private static int obterCapacidadePassageiros() {
        String inputCapacidade = JOptionPane.showInputDialog("Digite a capacidade de passageiros:");
        if (inputCapacidade == null) {
            return -1;
        }

        try {
            return Integer.parseInt(inputCapacidade);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Capacidade de passageiros inválida. Digite um número inteiro.");
            return -1;
        }
    }

    // Métodos para validação de placa de veículo

    private static boolean validarPlaca(String placa) {
        // Implementação da validação de placa de veículo
        // Considerando uma validação básica para o exemplo
        // Neste caso, a placa deve ter exatamente 7 caracteres alfanuméricos
        return placa.matches("[A-Z]{3}[0-9]{4}");
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == buttonCadastrarVeiculo) {
            cadastrarVeiculo();
        } else if (e.getSource() == buttonListarVeiculos) {
            listarTodosVeiculos();
        } else if (e.getSource() == buttonPesquisarVeiculo) {
            menuPesquisarVeiculo();
        } else if (e.getSource() == buttonEditarVeiculo) {
            editarVeiculo();
        } else if (e.getSource() == buttonExcluirVeiculo) {
            excluirVeiculo();
        } else if (e.getSource() == buttonCadastrarCliente) {
            menuClientes();
        } else if (e.getSource() == buttonCadastrarContrato) {
            menuContratosAluguel();
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Sistema de Locadora de Veículos");
        frame.setContentPane(new MenuPrincipal().panelMain);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
