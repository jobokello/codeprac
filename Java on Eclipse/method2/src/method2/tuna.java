package method2;

public class tuna {
	
	private String girlName;
	
	public void setName(String name) {
		girlName = name;
	}
	
	public String getName() {
		return girlName;
	}
	
	public void saying() {
		System.out.printf("your first girl was %s", getName());
	}

}
