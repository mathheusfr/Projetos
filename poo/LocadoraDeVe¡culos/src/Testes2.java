/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Lucas Henrique
 */
public class Testes2 {

    public static void main(String[] args) {

        // Criando um cliente físico
        ClienteFisico clienteFisico1 = new ClienteFisico("12345678901", null, "Lucas", "Rua A", "123456789", "lucas@email.com");
        ClienteFisico clienteFisico2 = new ClienteFisico("12345678910", null, "João Silva", "Rua dos Testes", "999-9999", "joao.silva@email.com");

        System.out.println("\n Cliente Físico 1: " + clienteFisico1);
        System.out.println("\n Cliente Físico 2: " + clienteFisico2);

        // Criando um cliente jurídico
        ClienteJuridico clienteJuridico1 = new ClienteJuridico("12345678901234", null, "Empresa XYZ", "Av. B", "987654321", "empresa@xyz.com");
        ClienteJuridico clienteJuridico2 = new ClienteJuridico("12345678910112", null, "Empresa XPTO", "Av. das Empresas", "888-8888", "empresa@xpto.com.br");

        System.out.println("\nCliente Jurídico 1: " + clienteJuridico1);
        System.out.println("\nCliente Jurídico 2: " + clienteJuridico2);
        
        /*
        // Criação de clientes físicos
        ClienteFisico clienteFisico1 = new ClienteFisico("12345678901", "Lucas", "Rua A", "123456789", "lucas@email.com");
        ClienteFisico clienteFisico2 = new ClienteFisico("12345678910", "João Silva", "Rua dos Testes", "999-9999", "joao.silva@email.com");

        try {
            // Teste do método inserir
            clienteDAO.inserir(clienteFisico1);
            clienteDAO.inserir(clienteFisico2);

            // Exibir os clientes inseridos
            System.out.println("\nClientes após inserção:");
            for (Cliente cliente : clienteDAO.buscarTodos()) {
                System.out.println(cliente);
            }

            // Atualizar cliente
            clienteFisico1.setNome("Lucas Henrique Atualizado");
            clienteDAO.atualizar(clienteFisico1);

            // Exibir os clientes após atualização
            System.out.println("\nClientes após atualização:");
            for (Cliente cliente : clienteDAO.buscarTodos()) {
                System.out.println(cliente);
            }

        } catch (ParametroIncompativelException e) {
            e.printStackTrace();
        }
    }
        */

    }

}
