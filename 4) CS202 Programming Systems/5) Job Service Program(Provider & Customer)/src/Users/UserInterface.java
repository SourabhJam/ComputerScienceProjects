//CS202 Programming Systems, Sourabh Jamalapuram, Program #5
//UserInterface.java, class to implement functions and UI for a provider or a customer

package Users;

import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

import Services.DogWalk;
import Services.FoodDelivery;
import Services.Service;
import Services.YardWork;

public class UserInterface {

	//function to run the program as a provider
	public void runAsProvider(Provider p) throws IOException {

		Scanner input = new Scanner(System.in);

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

				System.out.print("\nEnter Title Of Service You Would Like To Find: ");
				title = input.next();

				Service found = p.retrieve(title);

				if (found != null) {
					System.out.println("\nService Found!");
				} else {
					System.out.println("\nService NOT Found!");
				}

			}

			else if (userOption == 4) {
				p.removeAll();
			}

			else if (userOption == 5) {
				p.updateFile();
			}

		} while (userOption != 0);

		System.out.print("\nLogging Off As Provider... ");

	}

	//function to run the program as a customer
	public void runAsCustomer(Customer c) throws IOException {

		Provider p = new Provider();
		Scanner input = new Scanner(System.in);

		int userOption;
		boolean noDataProvider = true;
		boolean noDataCustomer = true;

		p.build();
		p.updateFile();

		String title;

		try {
			p.loadData();
		} catch (FileNotFoundException e) {
			noDataProvider = false;
		}
		
		try {
			c.loadData();
		} catch (FileNotFoundException e) {
			noDataCustomer = false;
		}

		do {

			try {
				System.out.println("\nWelcome To The PSU Job Finder!");
				System.out.println("User: Customer");
				System.out.println("\n(1)View Avaliable Job Postings(Display All BST)");
				System.out.println("(2)Search Current Job Postings(Retrieve BST)");
				System.out.println("_____________________________________________");
				System.out.println("(3)Add Job To My List(Insert ARR)");
				System.out.println("(4)Remove My Job(Remove ARR)");
				System.out.println("(5)Display My Jobs(Display ARR)");
				System.out.println("(6)Search My Jobs(Retrieve ARR)");
				System.out.println("(7)Submit Changes (Update File)");
				System.out.println("(8)Remove All My Jobs(Remove All ARR)");
				System.out.println("_____________________________________________");
				System.out.println("(0)Quit");
				System.out.print("\nChoose One Of The Following Options: ");

				String userOption1 = input.nextLine();
				userOption = Integer.parseInt(userOption1);

				if (userOption == 1) {

					if (noDataProvider == false) {
						System.out.println("\nNo Current Jobs Avaliable!");
					} else {
						System.out.println("\nCurrent Job Openings!");
						System.out.println("_______________________");
						p.display();
					}
				}

				if (userOption == 2) {

					System.out.print("\nEnter Title Of Service You Would Like To Find: ");
					title = input.nextLine();

					Service found = p.retrieve(title);

					if (found != null) {
						System.out.println("\nService Found!");
					} else {
						System.out.println("\nService NOT Found!");
					}
				}

				if (userOption == 3) {

					System.out.print("\nEnter Title Of Service You Would Like To Add: ");
					title = input.nextLine();

					Service found = p.retrieve(title);

					if (found != null) {
						System.out.println("\nService Found!");
						c.insert(found);
					} else {
						System.out.println("\nService NOT Found!");
					}

				}

				if (userOption == 4) {
					System.out.print("\nEnter Title Of Job You Would Like To Remove: ");
					title = input.nextLine();

					c.remove(title);

				}

				if (userOption == 5) {
					System.out.println("\nMY JOBS");
					System.out.println("________________________________________________");
					c.display();

				}

				if (userOption == 6) {
					System.out.print("\nEnter Title Of Service You Would Like To Find From Your Job List: ");
					title = input.nextLine();

					boolean found = c.retrieve(title);

					if (found == true) {
						System.out.println("\nJob Found!");
					} else {
						System.out.println("\nJob NOT Found!");
					}
				}

				if (userOption == 7) {
					c.updateFile();
					System.out.println("\nChanges Submitted!");
				}

				if (userOption == 8) {
					c.removeAll();
				}
				
				if (userOption == 9) {
					System.out.println("Enter Valid Option!");
				}

			} catch (NumberFormatException e) {
				System.out.println("\nEnter Valid Option!");
				userOption = 9;
				
			}

		} while (userOption != 0);
		
		System.out.print("\nLogging Off As Customer... ");

	}

}
