import java.util.Scanner;

public class getInput {

	public static void main(String[] args) {
		Scanner scan = new Scanner (System.in);
		System.out.println("Enter a number");
		int userInput = scan.nextInt();
		
		System.out.print("the value is: ");
		System.out.println(userInput);
		
		Scanner scan2 = new Scanner (System.in);
		System.out.println("Enter a string");
		String userString = scan2.nextLine();
		
		System.out.print("the string is: ");
		System.out.println(userString);
	}

}
