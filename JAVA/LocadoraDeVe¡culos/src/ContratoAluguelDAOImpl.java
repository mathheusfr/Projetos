/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Lucas Henrique
 */
import java.util.ArrayList;
import java.util.List;

public class ContratoAluguelDAOImpl implements ContratoAluguelDAO {

    private final ArrayList<ContratoAluguel> contratosAluguel = new ArrayList<>();

    @Override
    public boolean inserir(ContratoAluguel contrato) {
        contratosAluguel.add(contrato);
        System.out.println("Contrato de aluguel inserido com sucesso: " + contrato);
        return true;
    }

    @Override
    public boolean atualizar(ContratoAluguel contrato) {
        for (int i = 0; i < contratosAluguel.size(); i++) {
            if (contratosAluguel.get(i).getId() == contrato.getId()) {
                contratosAluguel.set(i, contrato);
                System.out.println("Contrato de aluguel atualizado com sucesso: " + contrato);
                return true;
            }
        }
        System.out.println("Contrato de aluguel não encontrado para atualização.");
        return false;
    }

    @Override
    public boolean excluir(int id) {
        for (int i = 0; i < contratosAluguel.size(); i++) {
            if (contratosAluguel.get(i).getId() == id) {
                contratosAluguel.remove(i);
                System.out.println("Contrato de aluguel removido com sucesso. ID: " + id);
                return true;
            }
        }
        System.out.println("Contrato de aluguel não encontrado para exclusão. ID: " + id);
        return false;
    }

    @Override
    public ContratoAluguel buscarPorId(int id) {
        for (ContratoAluguel contrato : contratosAluguel) {
            if (contrato.getId() == id) {
                return contrato;
            }
        }
        return null; // Retornar null se não encontrar o contrato com o ID especificado
    }

    @Override
    public List<ContratoAluguel> buscarTodos() {
        return new ArrayList<>(contratosAluguel); // Retorna uma cópia da lista de contratos
    }

    @Override
    public List<ContratoAluguel> buscarPorCliente(Cliente cliente) {
        List<ContratoAluguel> contratosPorCliente = new ArrayList<>();
        for (ContratoAluguel contrato : contratosAluguel) {
            if (contrato.getCliente().equals(cliente)) {
                contratosPorCliente.add(contrato);
            }
        }
        return contratosPorCliente;
    }

    @Override
    public List<ContratoAluguel> buscarPorVeiculo(Veiculo veiculo) {
        List<ContratoAluguel> contratosPorVeiculo = new ArrayList<>();
        for (ContratoAluguel contrato : contratosAluguel) {
            if (contrato.getVeiculo().equals(veiculo)) {
                contratosPorVeiculo.add(contrato);
            }
        }
        return contratosPorVeiculo;
    }

}
