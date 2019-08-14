package methodOverloading;

public class MyClass {
	public void add(int a, int b) {
		System.out.println("the sum is " + (a+b));
	}
	
	public void add(String a, String b) {
		System.out.println("the name is " + a + " " + b);
	}
}
