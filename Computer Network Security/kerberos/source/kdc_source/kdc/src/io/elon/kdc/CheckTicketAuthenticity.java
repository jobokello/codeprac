package io.elon.kdc;

import io.elon.Main;
import io.undertow.server.HttpHandler;
import io.undertow.server.HttpServerExchange;

public class CheckTicketAuthenticity implements HttpHandler {
    @Override
    public void handleRequest(HttpServerExchange exchange) {

        String ticket = Kdc.getQueryParam(exchange, "ticket");

        Main.log("Checking authenticity of ticket: "+ticket);

        if(Kdc.database.get("ticket").contains(ticket)){
            long expiry = Long.parseLong(Kdc.database.get("ticket").split(",")[1]);
            if(System.currentTimeMillis() > expiry){
                Kdc.send(exchange, "Ticket expired");
                Main.log("Ticket: "+ticket+" expired");
            }else{
                Kdc.send(exchange, "Ticket ok");
                Main.log("Ticket: "+ticket+" is ok");
            }
        }else{
            Kdc.send(exchange, "Ticket not found");
            Main.log("Ticket: "+ticket+" not found");
        }
    }
}
