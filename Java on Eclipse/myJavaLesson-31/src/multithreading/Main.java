package multithreading;

class MyClass extends Thread{

	public void run() {
		
		for(int i = 0; i < 10; i++) {
			
			System.out.println(Thread.currentThread().getId() + " Values if i is: " + i);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
			
		
	}
	
}

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		MyClass myClass = new MyClass();
		myClass.start();
		
		MyClass myClass1 = new MyClass();
		myClass1.start();

	}

}
