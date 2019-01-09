/**
 * Name: Derek Prince Mutende
 * Adm No.: P15/1724/2016
 */
package io.elon;

import io.elon.bob.Bob;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Main {

    public static void main(String[] args) {
        // Start Client bob
        new Bob(45892);
    }

    public static void log(String log){
        System.out.println("\n");
        System.out.println(">> Bob (Client):\n");
        System.out.println(log);
        System.out.println("Timestamp: "+
                new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSSS").format(new Date()));
    }
}
