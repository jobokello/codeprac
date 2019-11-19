package exceptionHandling;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int b[] = new int[2];
		try {
			//int a = 100/0;
			
			System.out.println("Value of b = " + b[3]);
		}catch (ArithmeticException e) {
			System.out.println(e);
		}catch (Exception e) {
			System.out.println(e);
		}
		
		System.out.println("---------------------------");

	}

}
