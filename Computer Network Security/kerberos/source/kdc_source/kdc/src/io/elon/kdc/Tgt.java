package io.elon.kdc;

import io.elon.Encryption;
import io.elon.Main;
import io.elon.Ticket;
import io.undertow.server.HttpHandler;
import io.undertow.server.HttpServerExchange;

import java.security.SecureRandom;

public class Tgt implements HttpHandler {

    @Override
    public void handleRequest(HttpServerExchange exchange) {
        String client = Kdc.getQueryParam(exchange, "client");

        Main.log("/get-ticket request from client: "+client);

        if(!Kdc.database.get("registered_clients").contains(client)){
            Kdc.send(exchange, "Client not registered");
            Main.log("Client: "+client+" not registered");
            return;
        }

        String ticket = new Ticket(50, new SecureRandom()).nextString();
        long expiry = System.currentTimeMillis()+(3600*1000);

        Kdc.database.put("ticket", ticket+","+expiry);

        Kdc.send(exchange,
                Encryption.encrypt(ticket+","+expiry, Kdc.database.get(client)));
        Main.log("TGT for client: "+client+" -> "+
                Encryption.encrypt(ticket+","+expiry, Kdc.database.get(client)));
    }
}
