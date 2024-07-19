/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package com.apicorreios;

/**
 *
 * @author santo
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Index {

    public static void main(String[] args) throws Exception {
        int option = -1;
        String user = "08220202@aluno.osorio.ifrs.edu.br";
        String token = "fe20ada9459a20a737b8d20b945008af1ad65ce5500f57fd543b150419bce3d8";
        
        while(option != 0){
            System.out.println("Menu Principal");
            Scanner scanner = new Scanner(System.in);
            System.out.println("Digite a opção desejada: ");
            option = scanner.nextInt();
            switch(option){
                case 1: 
                    try {
                        // Receber o código do usuário
                        System.out.println("Digite o código de rastreamento: ");
                        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                        String code = reader.readLine();
                        
                        // Crie uma instância da classe RequestAPI
                        RequestAPI apiRequest = new RequestAPI(user, token);
        
                        // Realize a requisição e obtenha os detalhes do primeiro evento
                        List<String> detalhesEvento = apiRequest.runRequest(code);

                        // Imprima os detalhes do primeiro evento
                        if (!detalhesEvento.isEmpty()) {
                            System.out.println("\nDetalhes do Primeiro Evento:");
                            System.out.println("Data: " + detalhesEvento.get(0));
                            System.out.println("Hora: " + detalhesEvento.get(1));
                            System.out.println("Local: " + detalhesEvento.get(2));
                            System.out.println("Status: " + detalhesEvento.get(3));
                        } else {
                            System.out.println("Código não encontrado.");
                        }
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    
                case 2:
            }
        }
    }
}
