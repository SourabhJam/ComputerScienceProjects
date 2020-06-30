
//CS202 Programming Systems, Sourabh Jamalapuram, Program #4
//FoodDelivery.java, contains class and function implementations specific to a Food Delivery
import java.io.FileWriter;
import java.io.IOException;

public class FoodDelivery extends Service {
	private int deliveryDistance; // Food Delivery distance

	// constructor to initialize private data members of Food Delivery and
	// invoke base class constructor
	FoodDelivery(String title, String description, double pay, int deliveryDistance) {
		super(title, description, pay);
		this.deliveryDistance = deliveryDistance;
	}

	// function to display a food Delivery
	public void display() {
		System.out.println("\n\nFood Delivery");
		System.out.println("________________________");
		System.out.println("Title: " + this.title);
		System.out.println("Description: " + this.description);
		System.out.println("Pay: $" + this.pay);
		System.out.println("Distance: " + deliveryDistance + " miles");

	}

	//function to write a food delievery to external data file
	public void writeOut(FileWriter myWriter) throws IOException {
		myWriter.append(
				"F|" + this.title + "|" + this.description + "|" + this.pay + "|" + this.deliveryDistance + "\n");

	}
}
