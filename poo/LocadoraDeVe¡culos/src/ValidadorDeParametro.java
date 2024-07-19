/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Lucas Henrique
 */
public class ValidadorDeParametro {

   // Valida se uma string está nula ou vazia
    static void validarString(String param) throws ParametroIncompativelException {
        if (param == null || param.isEmpty()) {
            throw new ParametroIncompativelException("Parâmetro incorreto para este campo: String nula ou vazia");
        }
    }

    // Valida se um número é 0 ou negativo
    static void validarNumero(int param) throws ParametroIncompativelException {
        if (param <= 0) {
            throw new ParametroIncompativelException("Parâmetro incorreto para este campo: Valor não pode ser 0 ou negativo");
        }
    }
}

