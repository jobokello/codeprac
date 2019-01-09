//Okello Job Opiyo
//P15/37353/2016
//CSC 411
//Kerberos: Alice 

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

public class Alice {

    private Undertow server;
    static HashMap<String, String> database;
    static String ticket;

    public Alice(int port){
        init();
        server = Undertow.builder()
                .addHttpListener(port, "localhost")
                .setHandler(
                        Handlers.path()
                                .addPrefixPath("/secure-resource", new SecuredResource())
                ).build();
        server.start();
        Main.log("Alice client online...");
    }

    private void init(){
        database = new HashMap<>();
        database.put("password", "Xjh73dtEr3");
    }

    public void startInteraction(){

        HashMap<String, String> params = new HashMap<>();
        params.put("client", "alice");

        Main.log("Requesting for ticket from KDC Auth Server at: http://localhost:45890/get-ticket...");

        String ticketResponse = get("http://localhost:45890/get-ticket", params);
        String clearText = Encryption.decrypt(ticketResponse, database.get("password"));

        Main.log("Response from KDC Auth Server: \n" +
                "Actual -> "+ticketResponse+"\n" +
                "Clear Text -> "+clearText);
        assert clearText != null;
        ticket = clearText.split(",")[0];

        Main.log("Using ticket to request for protected resource from bob at:" +
                " http://localhost:45892/secure-resource");

        params.put("ticket", ticket);
        params.put("request", "election_results");

        String response = get("http://localhost:45892/secure-resource", params);
        Main.log("Response from client bob -> "+response);

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
