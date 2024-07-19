package com.apicorreios;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import org.json.JSONArray;
import org.json.JSONObject;

public class RequestAPI {
    private final String user;
    private final String token;

    public RequestAPI(String user, String token) {
        this.user = user;
        this.token = token;
    }
    
    public List<String> runRequest(String code) throws Exception {
        List<String> detailsEvent = new ArrayList<>();

        try {
            // Montar a URL da API
            String apiUrl = "https://api.linketrack.com/track/json?user=" + user + "&token=" + token + "&codigo=" + code;

            // Fazer a requisição HTTP
            URL url = new URL(apiUrl);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("GET");

            // Ler a resposta
            try (BufferedReader responseReader = new BufferedReader(new InputStreamReader(connection.getInputStream()))) {
                StringBuilder response = new StringBuilder();
                String line;

                while ((line = responseReader.readLine()) != null) {
                    response.append(line);
                }

                // Processar a resposta JSON
                JSONObject jsonResponse = new JSONObject(response.toString());

                // Extrair o primeiro evento
                JSONArray events = jsonResponse.getJSONArray("eventos");
                if (events.length() > 0) {
                    JSONObject firstEvent = events.getJSONObject(0);

                    // Adicionar detalhes do primeiro evento ao ArrayList
                    detailsEvent.add(firstEvent.getString("data"));
                    detailsEvent.add(firstEvent.getString("hora"));
                    detailsEvent.add(firstEvent.getString("local"));
                    detailsEvent.add(firstEvent.getString("status"));
                } else {
                    detailsEvent.add("Código não encontrado.");
                }
            }
        } catch (Exception e) {
            throw new Exception("Erro na realização da requisição", e);
        }

        return detailsEvent;
    }
}
