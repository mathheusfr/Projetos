
import java.util.List;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */

/**
 *
 * @author Lucas Henrique
 * @param <T>
 */
public interface GenericDAO<T> {
   
    boolean inserir(T obj)throws ParametroIncompativelException;

    /**
     *
     * @param obj
     * @return
     */
    boolean atualizar(T obj);
    boolean excluir(int id);
    T buscarPorId(int id);
    List<T> buscarTodos();
}



