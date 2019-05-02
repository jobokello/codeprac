//Okello Job Opiyo
//P15/37353/2016
//CSC 411
//Kerberos: KDC
import io.drone.Main;
import io.undertow.Handlers;
import io.undertow.Undertow;
import io.undertow.server.HttpServerExchange;
import io.undertow.util.Headers;
import io.undertow.util.StatusCodes;

import java.util.Deque;
import java.util.HashMap;

public class Kdc {

    private Undertow server;
    static HashMap<String, String> database;

    public Kdc(int port){
        init();
        server = Undertow.builder()
                .addHttpListener(port, "localhost")
                .setHandler(
                        Handlers.path()
                                .addPrefixPath("/get-ticket", new Tgt())
                                .addPrefixPath("/verify-ticket", new CheckTicketAuthenticity())
                ).build();
        server.start();
        Main.log("KDC Authentication Service started successfully. Waiting for requests...");
    }

    private void init(){
        database = new HashMap<>();
        database.put("registered_clients", "alice,bob");
        database.put("alice", "Xjh73dtEr3");
        database.put("bob", "eu87deTY343");
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

    static void send(HttpServerExchange exchange, String data){
        exchange.setStatusCode(StatusCodes.OK);
        exchange.getResponseHeaders().put(Headers.CONTENT_TYPE, "text/plain");
        exchange.getResponseSender().send(data);
    }

}
