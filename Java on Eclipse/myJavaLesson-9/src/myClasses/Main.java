package myClasses;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Student jobokello = new Student();
		
		jobokello.id = 9972;
		jobokello.age = 23;
		jobokello.name = "Job Okello";
		
		jobokello.printDetails();
		
		System.out.println("\n\n" + jobokello.name + " whose Number is " + jobokello.id + " is " + jobokello.age + " years old!!! From the main program");

	}

}
