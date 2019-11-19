
public class methods {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String name = "jobokello5@gmail.com";
		
		int a = 10;
		int b = 20;
		int ans;
		
		myMethod(name);
		
		ans = add(a,b);
		
		System.out.println("the sum of the two from the function add is " + ans);
		
	}
	
	public static void myMethod(String name ){
		
		System.out.println("my email is " + name);
	}
	
	public static int add(int x, int y) {
		
		int result = x + y;
		
		System.out.println("the answer is " + result);
		
		return result;
	}

}
