package jUnitTest;

import static org.junit.Assert.*;

import org.junit.Test;

public class ConCatTest {

	@Test
	public void ConCattest() {
		myJUnitClass junit = new myJUnitClass();
		String result = junit.conCat("hello", "world");
		assertEquals("helloworld", result);
	}

}
