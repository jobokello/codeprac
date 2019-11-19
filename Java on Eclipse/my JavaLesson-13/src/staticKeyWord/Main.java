package staticKeyWord;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		MyClass hello = new MyClass();
		String myHello1 = MyClass.doStatic("hello static");
		System.out.println(myHello1);
		
		
		MyClass hello2 = new MyClass();
		String myHello2 = hello2.doNoneStatic("hello non-static");
		System.out.println(myHello2);

	}

}
