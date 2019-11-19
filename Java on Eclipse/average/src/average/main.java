package average;
import java.util.Scanner;

public class main {
	
	public static void main(String args[]) {
		
		Scanner input = new Scanner(System.in);
		
		int total = 0;
		int grade;
		int average;
		int counter = 0;
		
		while (counter < 10) {
			if (counter == 0) {
				
				System.out.println("enter 1st mumber: ");
				grade = input.nextInt();
				total = total + grade;
				counter++;	
			}else if (counter == 1) {
				
				System.out.println("enter 2nd nmumber: ");
				grade = input.nextInt();
				total = total + grade;
				counter++;	
			}else if (counter == 2) {
				
				System.out.println("enter 3rd mumber: ");
				grade = input.nextInt();
				total = total + grade;
				counter++;	
			}if (counter > 2) {
				
				System.out.println("enter " + (counter+1) + "th mumber: ");
				grade = input.nextInt();
				total = total + grade;
				counter++;	
			}
			
		}
		
		average = total/10;
		
		System.out.println("The avegare is " + average);
		
	}

}
