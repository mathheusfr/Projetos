
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


public interface ClienteDAO extends GenericDAO<Cliente> {

    Cliente buscarPorCpf(String cpf);
    Cliente buscarPorCnpj(String cnpj);
    List<Cliente> pesquisarPorNome(String nome);
    
}
