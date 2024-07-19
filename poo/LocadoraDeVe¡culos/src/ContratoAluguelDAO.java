/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */

/**
 *
 * @author Lucas Henrique
 */
import java.util.List;

public interface ContratoAluguelDAO extends GenericDAO<ContratoAluguel> {

    List<ContratoAluguel> buscarPorCliente(Cliente cliente);

    List<ContratoAluguel> buscarPorVeiculo(Veiculo veiculo);

}

