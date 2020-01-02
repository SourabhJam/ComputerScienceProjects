import java.util.Scanner;

public class Application {

	public static void main(String[] args) {
		System.out.println("Please Enter Your Age: ");

		Scanner s1 = new Scanner(System.in);
		int age = s1.nextInt();

		if (age >= 1 && age <= 13) {
			System.out.println("You are a Kid");
		} else if (age > 13 && age <= 19) {
			System.out.println("You are a Teen");
		} else if (age >= 20 && age < 60) {
			System.out.println("You are an Adult");
		} else if (age >= 60) {
			System.out.println("Senior Citizen");
		} else if (age <= 0) {
			System.out.println("Error/ Please Enter a Valid Age");
		}
	}

}
