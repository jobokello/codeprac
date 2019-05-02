package io.elon.bob;

import io.elon.Main;
import io.undertow.server.HttpHandler;
import io.undertow.server.HttpServerExchange;

import java.util.HashMap;

public class SecuredResource implements HttpHandler {
    @Override
    public void handleRequest(HttpServerExchange exchange) {

        String ticket = Bob.getQueryParam(exchange, "ticket");
        String request = Bob.getQueryParam(exchange, "request");

        HashMap<String, String> params = new HashMap<>();
        params.put("ticket", ticket);
        Main.log("Verifying Ticket: "+ticket+" with KDC Auth Server at: http://localhost:45890/verify-ticket");
        String checkTicketResponse = Bob.get("http://localhost:45890/verify-ticket", params);

        if(checkTicketResponse == null){
            Main.log("Error verifying ticket from KDC Auth Server");
            return;
        }else{
            if(!checkTicketResponse.contains("ok")){
                Main.log("Ticket not authentic. Response from KDC Auth Server -> "+checkTicketResponse);
                return;
            }
        }

        Main.log("Sending secure resource (request="+request+") -> "+ Bob.database.get(request));
        Bob.send(exchange, Bob.database.get(request));
    }
}
