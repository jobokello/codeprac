import java.util.Scanner;

public class jobson {
	
	public static void main(strings args[]) {
		Scanner jobson = new Scanner(System.in);
		double num1, num2, answer;
		
		System.out.println("Enter first number: ");
		num1 = jobson.nextDouble();
		
		System.out.println("Enter second number: ");
		num2 = jobson.nextDouble();
		
		answer = num1 + num2;
		
		System.out.print("The sum of the two numbers is: ");
		System.out.println(answer);	
	}

}