package arrayList;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int simpleArray[] = new int[5];
		
		ArrayList <Integer> myList = new ArrayList<Integer>(5);
		
		myList.add(1);
		myList.add(2);
		myList.add(7);
		myList.add(5);
		myList.add(22);
		myList.add(21);
		myList.add(12);
		
		for (Integer x: myList) {
			
			System.out.println(x);
		}
		
		System.out.println(myList.size());
		

	}

}
