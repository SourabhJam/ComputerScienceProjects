
//CS202 Programming Systems, Sourabh Jamalapuram, Program #4
//Application.java, this is where the program starts from a provider perspective the provider can choose to post a job, display all jobs, search for a job, 
//delete all jobs, or save jobs to external data file. Depending on the option they choose the program performs the desired operation 
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Application {

	public static void main(String[] args) throws IOException {

		Provider p = new Provider(); // Provider Object

		Scanner input = new Scanner(System.in); // Scanner object to input data

		int userOption; // User Option
		int serviceChoice; // Number Corresponding To Service Choice

		String title; // Service Title
		String description; // Service Description
		double pay; // Service Pay Rate
		int distance; // Delivery Distance
		int yardSize; // Size Of Yard
		int numOfDogs; // Number Of Dogs

		try {
			p.loadData();
		} catch (FileNotFoundException e) {

		}

		do {
			System.out.println("\nWelcome To The PSU Job Finder!");
			System.out.println("User: Provider");
			System.out.println("(1)Post Job(Insert)");
			System.out.println("(2)Display Jobs(Display)");
			System.out.println("(3)Search Job(Retrieve)");
			System.out.println("(4)Delete All Job Posts(Remove All)");
			System.out.println("(5)Save Jobs(Update File)");
			System.out.println("(0)Quit");
			System.out.print("Choose One Of The Following Options: ");

			userOption = input.nextInt();

			if (userOption == 1) {
				System.out.println("\n(1)Food Delievery");
				System.out.println("(2)Yard Work");
				System.out.println("(3)Dog Walk");
				System.out.print("Choose Which Service You Would Like To Add:  ");

				serviceChoice = input.nextInt();

				if (serviceChoice == 1) {
					System.out.print("\nEnter Job Title: ");
					title = input.next();

					System.out.print("\nEnter Job Description: ");
					description = input.next();

					System.out.print("\nEnter Job Payment($): ");
					pay = input.nextDouble();

					System.out.print("\nEnter Delivery Distance(miles): ");
					distance = input.nextInt();

					FoodDelivery f = new FoodDelivery(title, description, pay, distance);
					p.insert(f);
				} else if (serviceChoice == 2) {
					System.out.print("\nEnter Job Title: ");
					title = input.next();

					System.out.print("\nEnter Job Description: ");
					description = input.next();

					System.out.print("\nEnter Job Payment($): ");
					pay = input.nextDouble();

					System.out.print("\nEnter Yard Size(Sq Ft): ");
					yardSize = input.nextInt();

					YardWork y = new YardWork(title, description, pay, yardSize);
					p.insert(y);
				} else if (serviceChoice == 3) {
					System.out.print("\nEnter Job Title: ");
					title = input.next();

					System.out.print("\nEnter Job Description: ");
					description = input.next();

					System.out.print("\nEnter Job Payment($): ");
					pay = input.nextDouble();

					System.out.print("\nEnter Number Of Dogs To Walk: ");
					numOfDogs = input.nextInt();

					DogWalk d = new DogWalk(title, description, pay, numOfDogs);
					p.insert(d);
				} else {
					System.out.println("Invalid Service Choice!");
				}

			}

			else if (userOption == 2) {
				p.display();
			}

			else if (userOption == 3) {

				System.out.print("\nEnter Title Of Service You Would Like To Find: ");
				title = input.next();

				boolean found = p.retrieve(title);

				if (found == true) {
					System.out.println("Service Found!");
				} else {
					System.out.println("Service NOT Found!");
				}

			}

			else if (userOption == 4) {
				p.removeAll();
			}

			else if (userOption == 5) {
				p.updateFile();
			}

		} while (userOption != 0);

		System.out.print("\nThank You For Using The PSU Job Finder ");

	}

}
