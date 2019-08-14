package inheritance;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Rectangle rec = new Rectangle();
		Triangle tri = new Triangle();
		
		rec.setValues(10, 20);
		tri.setValues(10, 20);
		
		System.out.println("area of Rectangle is : " + rec.area());
		System.out.println("area of Triangle is : " + tri.area());

	}

}
