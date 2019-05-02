//Okello Job Opiyo
//P15/37353/2016
//CSC 411
//Kerberos: Bob Code
import io.drone.Encryption;
import io.drone.Main;
import io.undertow.Handlers;
import io.undertow.Undertow;
import io.undertow.server.HttpServerExchange;
import io.undertow.util.Headers;
import io.undertow.util.StatusCodes;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class Bob {

    private Undertow server;
    static HashMap<String, String> database;
    static String ticket;

    public Bob(int port){
        init();
        server = Undertow.builder()
                .addHttpListener(port, "localhost")
                .setHandler(
                        Handlers.path()
                                .addPrefixPath("/secure-resource", new SecuredResource())
                ).build();
        server.start();
        Main.log("Bob client online...");
    }

    private void init(){
        database = new HashMap<>();
        database.put("password", "eu87deTY343");
        database.put("election_results", "Trump=40,56,09,45,50,50|Bush=89,99,98,98,89|Obama=98,89,209,98,829");
        database.put("exam_results", "SCI=908823412|MED=9492345234|ENG=834521234");
    }

    public void stopServer(){
        server.stop();
    }

    static String getQueryParam(HttpServerExchange exchange, String key){
        Deque<String> param = exchange.getQueryParameters().get(key);
        String paramStr = null;

        if(param != null && !param.getFirst().equals(""))
            paramStr = param.getFirst();

        return paramStr;
    }

    private static String getParametersString(HashMap<String, String> params){
        StringBuilder result = new StringBuilder();
        boolean first = true;
        for(Map.Entry<String, String> entry : params.entrySet()){
            if (first)
                first = false;
            else
                result.append("&");
            try{
                result.append(URLEncoder.encode(entry.getKey(), "UTF-8"));
                result.append("=");
                result.append(URLEncoder.encode(entry.getValue(), "UTF-8"));
            }catch (UnsupportedEncodingException e){
                e.printStackTrace();
            }
        }
        return result.toString();
    }

    static String get(String url, HashMap<String, String> params){
        StringBuilder response = new StringBuilder();
        HttpURLConnection connection = null;
        BufferedReader in = null;
        int responseCode = -1;

        try {
            connection = (HttpURLConnection)
                    new URL(url+"?"+getParametersString(params)).openConnection();

            //Set Request Method
            connection.setRequestMethod("GET");
            System.out.println(connection.getURL().toString());
            responseCode = connection.getResponseCode();
            if (responseCode == HttpURLConnection.HTTP_OK) {

                in = new BufferedReader(
                        new InputStreamReader(connection.getInputStream()));

                String inputLine;

                while ((inputLine = in.readLine()) != null) {
                    response.append(inputLine);
                }
                in.close();
            }else{
                return connection.getResponseMessage();
            }

            return response.toString();

        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    static void send(HttpServerExchange exchange, String data){
        exchange.setStatusCode(StatusCodes.OK);
        exchange.getResponseHeaders().put(Headers.CONTENT_TYPE, "text/plain");
        exchange.getResponseSender().send(data);
    }

}
