package tryCatchFinally;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(retInt());
		
	}
	
	public static int retInt() {
		int a = 100;
		try {
			a = a/0;
			return a;
			
		}
		
		catch(Exception e){
			
			System.out.println("catch called");
			System.out.println(e);
			return a;
			
		}
		
		finally{
			a = 5000;
			System.out.println("final blocked called");
			return a;
		}

	}

}
