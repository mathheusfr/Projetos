/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package com.apicorreios;

/**
 *
 * @author santo
 */

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;


public class TestAPICorreios {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            // Receber o código do usuário
            System.out.println("Digite o código de rastreamento: ");
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String codigo = reader.readLine();

            // Montar a URL da API
            String apiUrl = "https://api.linketrack.com/track/json?user=08220202@aluno.osorio.ifrs.edu.br&token=fe20ada9459a20a737b8d20b945008af1ad65ce5500f57fd543b150419bce3d8&codigo=" + codigo;

            // Fazer a requisição HTTP
            URL url = new URL(apiUrl);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("GET");

            // Ler a resposta
            BufferedReader responseReader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            StringBuilder response = new StringBuilder();
            String line;

            while ((line = responseReader.readLine()) != null) {
                response.append(line);
            }
            responseReader.close();

            // Fechar a conexão
            connection.disconnect();

            // Processar a resposta JSON
            JSONObject jsonResponse = new JSONObject(response.toString());

            // Extrair e formatar os eventos
            JSONArray eventos = jsonResponse.getJSONArray("eventos");
            System.out.println("\nEventos:");
            
            if(eventos.length() >= 0){
                for (int i = 0; i < eventos.length(); i++) {
                    JSONObject evento = eventos.getJSONObject(i);
                    System.out.println("Data: " + evento.getString("data"));
                    System.out.println("Hora: " + evento.getString("hora"));
                    System.out.println("Local: " + evento.getString("local"));
                    System.out.println("Status: " + evento.getString("status"));
                    System.out.println("------------------------------");
                }
            } else System.out.println("Código não encontrado.");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}
