
//CS202 Programming Systems, Sourabh Jamalapuram, Program #4
//DogWalk.java, contains class and function implementations specific to a Dog Walk Service

import java.io.FileWriter;
import java.io.IOException;

public class DogWalk extends Service {
	private int numDogs; // number of dogs to walk

	// constructor to initialize private data members of dog walk and to invoke
	// base class constructor
	DogWalk(String title, String description, double pay, int numDogs) {
		super(title, description, pay);
		this.numDogs = numDogs;
	}

	// function to display a dog walk service
	public void display() {
		System.out.println("\nDog Walk");
		System.out.println("________________________");
		System.out.println("\nTitle: " + this.title);
		System.out.println("Description: " + this.description);
		System.out.println("Pay: $" + this.pay);
		System.out.println("# Of Dogs: " + numDogs);
	}

	// function to write a dog walk service to external data file
	public void writeOut(FileWriter myWriter) throws IOException {
		myWriter.append("D|" + this.title + "|" + this.description + "|" + this.pay + "|" + this.numDogs + "\n");

	}
}
