package multithreading;

public class Main2 {

	private static int count = 0;
	
	public static synchronized void inccount() {
		
		count++;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Thread t1 = new Thread (new Runnable() {

			@Override
			public void run() {
				// TODO Auto-generated method stub
				for (int i = 0; i< 10000; i++) {
					inccount();
				}
				
			}
			
		});
		
		Thread t2 = new Thread (new Runnable() {

			@Override
			public void run() {
				// TODO Auto-generated method stub
				for (int i = 0; i< 10000; i++) {
					inccount();
				}
				
			}
			
		});
		
		t1.start();
		t2.start();
		
		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Value : " + count);

	}

}
