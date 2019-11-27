package method2;
import java.util.Scanner;

public class myMain {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		
		tuna tunaObject = new tuna();
		
		System.out.println("Enter a names here: ");
		String tempName = input.nextLine();
		
		tunaObject.setName(tempName);
		
		tunaObject.saying();
		
		
	}

}
