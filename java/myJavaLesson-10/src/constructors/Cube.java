package constructors;

public class Cube {
	int length;
	int height;
	int breadth;
	
	Cube(){
		length = 12;
		height = 14;
		breadth = 15;
	}
	
	Cube(int a, int b, int c){
		length = a;
		height = b;
		breadth = c;
	}
	
	public int getVolume() {
		return (length * height * breadth);
	}
}
