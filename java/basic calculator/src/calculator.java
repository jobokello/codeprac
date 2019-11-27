import java.util.Scanner;

public class calculator {
	public static void main(String args[]) {
		Scanner calc = new Scanner(System.in);
		double num1, num2, answer;
		
		System.out.println("Enter first number: ");
		num1 = calc.nextDouble();
		
		System.out.println("Enter second number: ");
		num2 = calc.nextDouble();
		
		answer = num1 + num2;
		
		System.out.print("The sum of the two numbers is: ");
		System.out.println(answer);	
	}

}




