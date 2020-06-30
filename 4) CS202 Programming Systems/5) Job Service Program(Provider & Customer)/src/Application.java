
//CS202 Programming Systems, Sourabh Jamalapuram, Program #5
//Application.java, this is where the program starts from. Starts by welcoming the user and asking if they are a customer or a provider
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import Services.DogWalk;
import Services.FoodDelivery;
import Services.YardWork;
import Users.Provider;
import Users.UserInterface;
import Users.Customer;

public class Application {

	public static void main(String[] args) throws IOException {

		UserInterface UI = new UserInterface(); //UI For Program
		Provider p = new Provider(); // Provider Object
		Customer c = new Customer(); //Customer Object

		Scanner input = new Scanner(System.in); // Scanner object to input data

		String User; //User Running Program
		System.out.println("Welcome To The PSU Job Finder. You Will Login As Either A Provider(Program #4) Or A Customer(Program #5).");
		System.out.println("Provider: As A Provider You Will Be Able To Perform Operations Such As Post Jobs.");
		System.out.println("Customer: As A Customer You Will Then Be Able To Perform Operations Such As View All Avaliable Job Postings And Take Up Open Job Postings.");

		do {
			
			System.out.println("\nAre You A Provider Or Customer(P/C): ");
			System.out.println("Quit(Q) ");
			System.out.println("____________________________________");
			User = input.next();
			User = User.toUpperCase();
			

			if (User.compareTo("P") == 0) {
				UI.runAsProvider(p);
			}

			if (User.compareTo("C") == 0) {
				UI.runAsCustomer(c);
			}

		} while (User.compareTo("Q") != 0);

		System.out.println("\nThank You For Using PSU Job Service! ");

	}
}
