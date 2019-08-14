package hashSet;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		HashSet<String> names = new HashSet<String>();
		
		names.add("this");
		names.add("is");
		names.add("a");
		names.add("new");
		names.add("hashSet");
		
		Iterator<String> itr = names.iterator();
		
		while (itr.hasNext()) {
			
			System.out.println(itr.next());
		}

	}

}
