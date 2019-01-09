package io.elon.alice;

import io.elon.Main;
import io.undertow.server.HttpHandler;
import io.undertow.server.HttpServerExchange;

import java.util.HashMap;

public class SecuredResource implements HttpHandler {
    @Override
    public void handleRequest(HttpServerExchange exchange) {

        String ticket = Alice.getQueryParam(exchange, "ticket");
        String request = Alice.getQueryParam(exchange, "request");

        HashMap<String, String> params = new HashMap<>();
        params.put("ticket", ticket);
        Main.log("Verifying Ticket: "+ticket+" with KDC Auth Server at: http://localhost:45890/verify-ticket");
        String checkTicketResponse = Alice.get("http://localhost:45890/verify-ticket", params);

        if(checkTicketResponse == null){
            Main.log("Error verifying ticket from KDC Auth Server");
            return;
        }else{
            if(!checkTicketResponse.contains("ok")){
                Main.log("Ticket not authentic. Response from KDC Auth Server -> "+checkTicketResponse);
                return;
            }
        }

        Main.log("Sending secure resource (request="+request+") -> "+Alice.database.get(request));
        Alice.send(exchange, Alice.database.get(request));
    }
}
