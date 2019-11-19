package listIterators;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArrayList<String> names = new ArrayList<String>();
		
		names.add("Job");
		names.add("Opiyo");
		names.add("Okello");
		names.add("Juma");
		names.add("Baraza");
		names.add("Clyde");
		
		
		ListIterator<String> itr = names.listIterator();
		
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		
		System.out.println();
		
		while(itr.hasPrevious()) {
			
			System.out.println(itr.previous());
		}
		
		

	}

}
