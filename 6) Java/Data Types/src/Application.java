
public class Application {

	public static void main(String[] args) {
		Car c1 = new Car();
		c1.Brand = "Tesla";
		c1.maxMph = 200;
		c1.acceleration = 300;
		c1.decceleration = 500;
		c1.Model = "T336T1";
		
		System.out.println(c1.Brand + " " + c1.Model + " is now traveling " + c1.maxMph + "Mph" );
		

	}

}
