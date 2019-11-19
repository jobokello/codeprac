
import java.util.Scanner;

import methods.newTuna;

public class method {
	
	public static void main(String args[]) {
		
		Scanner input = new Scanner(System.in);
		newTuna newTunaObject = new newTuna();
		
		System.out.println("Enter your name here: ");
		String name = input.nextLine();
		
		newTunaObject.myMessage(name);
		
		
		
	}

}

