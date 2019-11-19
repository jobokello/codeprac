package linkedList;

import java.util.LinkedList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		LinkedList<String> name = new LinkedList<String>();
		
		name.add("Yvonne");
		name.add("Ivy");
		name.add("Sylvia");
		name.add("Onserio");
		name.addFirst("job");
		name.addLast("Okello");
		
		name.add(1,"I love you");
		name.remove(3);
		
		name.set(4,"hun");
		

		
		
		for (String x : name) {
			System.out.println(x);
		}

	}

}
