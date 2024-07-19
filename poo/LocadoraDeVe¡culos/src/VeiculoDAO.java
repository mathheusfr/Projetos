
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Lucas Henrique
 */
public interface VeiculoDAO extends GenericDAO<Veiculo>{
    
   Veiculo buscarPorPlaca(String placa);
   List<Veiculo> buscarPorMarca(String marca);
   List<Veiculo> buscarPorCategoria(CategoriaCarro categoria);
   List<Veiculo> buscarPorCambio (TipoTransmissao transmissao);
   
}
