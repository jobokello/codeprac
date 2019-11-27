package dateTime;

import java.util.Date;
import java.text.*;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Date date = new Date();
		
		System.out.println(date.toString());
		
		System.out.println(date.getTime());
		
		System.out.println(date.getMonth() + 1);
		
		SimpleDateFormat sdf = new SimpleDateFormat("E yyyy/mm/dd HH-mm-ss");
		
		System.out.println(sdf.format(date));

	}

}
