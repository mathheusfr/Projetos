
import java.util.ArrayList;
import java.util.List;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Lucas Henrique
 */
public class ClienteDAOImpl implements ClienteDAO {

    ArrayList<Cliente> cadastro = new ArrayList<>();

    // Implementação dos métodos do GenericDAO
    /**
     *
     * @param cliente
     * @return
     * @throws ParametroIncompativelException
     */
    @Override
    public boolean inserir(Cliente cliente) throws ParametroIncompativelException {
        // Verifica o tipo do cliente

        if (cliente instanceof ClienteFisico) {
            // Se o cliente for do tipo ClienteFisico
            String cpf = ((ClienteFisico) cliente).getCpf();
            // Obtém o CPF desse cliente específico

            for (Cliente c : cadastro) {
                // Percorre a lista de clientes já cadastrados
                if (c instanceof ClienteFisico && ((ClienteFisico) c).getCpf().equals(cpf)) {
                    // Se encontrar um cliente físico com o mesmo CPF
                    throw new ParametroIncompativelException("Cliente físico com CPF duplicado: " + cpf);
                }
            }
        } else if (cliente instanceof ClienteJuridico) {
            // Se o cliente for do tipo ClienteJuridico
            String cnpj = ((ClienteJuridico) cliente).getCnpj();
            // Obtém o CNPJ desse cliente específico

            for (Cliente c : cadastro) {
                // Percorre a lista de clientes já cadastrados
                if (c instanceof ClienteJuridico && ((ClienteJuridico) c).getCnpj().equals(cnpj)) {
                    // Se encontrar um cliente jurídico com o mesmo CNPJ
                    throw new ParametroIncompativelException("Cliente jurídico com CNPJ duplicado: " + cnpj);
                }
            }
        }

        // Se não encontrou duplicações, adiciona o cliente à lista
        cadastro.add(cliente);
        return true;
    }

    @Override
    public boolean atualizar(Cliente cliente) {
        // Percorre a lista de clientes já cadastrados
        for (int i = 0; i < cadastro.size(); i++) {
            Cliente clienteExistente = cadastro.get(i);

            // Verifica se o ID do cliente existente é igual ao ID do cliente atualizado
            if (clienteExistente.getId() == cliente.getId()) {
                // Se encontrar um cliente com o mesmo ID, atualiza os dados
                cadastro.set(i, cliente);
                return true;
            }
        }
        // Retorna falso se o cliente não foi encontrado
        return false;
    }

    @Override
    public boolean excluir(int id) {
        for (Cliente cliente : cadastro) {
            if (cliente.getId() == id) {
                cadastro.remove(cliente);
                return true;
            }
        }
        return false;
    }

    @Override
    public Cliente buscarPorId(int id) {
        for (Cliente cliente : cadastro) {
            if (cliente.getId() == id) {
                return cliente;
            }
        }
        return null;
    }

    @Override
    public List<Cliente> buscarTodos() {
        return cadastro;
    }

    // Implementação dos métodos do ClienteDAO
    @Override
    public Cliente buscarPorCpf(String cpf) {
        for (Cliente cliente : cadastro) {
            if (cliente instanceof ClienteFisico && ((ClienteFisico) cliente).getCpf().equals(cpf)) {
                return cliente;
            }
        }
        return null;
    }

    @Override
    public Cliente buscarPorCnpj(String cnpj) {
        for (Cliente cliente : cadastro) {
            if (cliente instanceof ClienteJuridico && ((ClienteJuridico) cliente).getCnpj().equals(cnpj)) {
                return cliente;
            }
        }
        return null;
    }

    /**
     *
     * @param nome
     * @return
     */
    @Override
    public List<Cliente> pesquisarPorNome(String nome) {
        List<Cliente> resultados = new ArrayList<>();
        for (Cliente cliente : cadastro) {
            if (cliente.getNome().equalsIgnoreCase(nome)) {
                resultados.add(cliente);
            }
        }
        return resultados;
    }

}
