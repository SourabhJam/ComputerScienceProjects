package Services;

//CS202 Programming Systems, Sourabh Jamalapuram, Program #5
//YardWork.java, contains class and function implementations specific to a Yard Work
import java.io.FileWriter;
import java.io.IOException;

public class YardWork extends Service {
	private int yardSize; // size of yard

	// constructor to initialize private data members of Yard Work and invoke
	// base class constructor
	public YardWork(String title, String description, double pay, int yardSize) {
		super(title, description, pay);
		this.yardSize = yardSize;
	}
	
	//default constructor
	public YardWork(){
		
	}

	// function to display a Yard Work service
	public void display() {
		System.out.println("\nYard Work");
		System.out.println("________________________");
		System.out.println("\nTitle: " + this.title);
		System.out.println("Description: " + this.description);
		System.out.println("Pay: $" + this.pay);
		System.out.println("Yard Size: " + this.pay + " Sq. Ft.");

	}

	// function to write a Yard Work service to external data file
	public void writeOut(FileWriter myWriter) throws IOException {
		myWriter.append("Y|" + this.title + "|" + this.description + "|" + this.pay + "|" + this.yardSize + "\n");

	}
}
