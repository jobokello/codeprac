package recursion;

import java.util.Scanner;

public class Main {
	
	public static int factorial(int n) {
		
		if (n <= 1) {
			return 1;
		}
		else {
			return (n * factorial (n-1));
		}
		
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//int numbers;
		
		System.out.println("enter number to calculate factorial");
		
		Scanner n = new Scanner(System.in);
		
		int numbers = n.nextInt();
		
		System.out.println("the factorial is: " + factorial(numbers));
		
		//factorial(numbers);
		

	}

}
