package constructors;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Cube cube1 = new Cube();
		
		System.out.println("the volume is " + cube1.getVolume());
		
		Cube cube2 = new Cube(10,20,30);
		
		System.out.println("the volume of cube after constructor overloading is  " + cube2.getVolume());

	}

}
