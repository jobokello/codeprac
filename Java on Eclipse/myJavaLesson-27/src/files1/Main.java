package files1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			File myFile = new File("filename.txt");
			
			if (!myFile.exists()) {
				myFile.createNewFile();
			}
			
			PrintWriter pw = new PrintWriter(myFile);
			pw.println("Job Okello has created a new file");
			pw.println(9972);
			pw.close();
			
			System.out.println("done");
		}
		
		catch (IOException e) {
			
			e.printStackTrace();
		}
		
		

	}

}
