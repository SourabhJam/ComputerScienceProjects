
//CS202 Programming Systems, Sourabh Jamalapuram, Program #4
//Service.java, abstract base class to hold derived classes together by common base class 

import java.io.FileWriter;
import java.io.IOException;

public abstract class Service {
	protected String title; // Service title
	protected String description; // Service description
	protected double pay; // Service payment

	// constructor to initialize private data members of service
	Service(String title, String description, double pay) {
		this.title = title;
		this.description = description;
		this.pay = pay;
	}

	// function to check if current services title is less than another services
	// title
	public boolean isLessThan(Service data) {
		if (this.title.compareTo(data.title) < 0) {
			return true;
		} else {
			return false;
		}
	}

	// function to check if current services title is less than a string title
	public boolean isLessThan(String title) {
		if (this.title.compareTo(title) < 0) {
			return true;
		} else {
			return false;
		}
	}

	// function to check if current services title is greater than another
	// services title
	public boolean isGreaterThan(Service data) {
		if (this.title.compareTo(data.title) > 0) {
			return true;
		} else {
			return false;
		}
	}

	// function to check if current services title is greater than a string
	// title
	public boolean isGreaterThan(String title) {
		if (this.title.compareTo(title) > 0) {
			return true;
		} else {
			return false;
		}
	}

	// abstract function to display service
	abstract public void display();

	// abstract function to write service to external data file
	abstract public void writeOut(FileWriter myWriter) throws IOException;

}
