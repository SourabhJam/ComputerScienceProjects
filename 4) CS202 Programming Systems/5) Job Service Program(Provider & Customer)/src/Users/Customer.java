//CS202 Programming Systems, Sourabh Jamalapuram, Program #5
//Customer.java, contains the heads of the array of linear linked lists and performs operations such as inserting, removing, retrieving from the array of linear linked lists

package Users;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

import Nodes.ARRNode;
import Nodes.BSTNode;
import Services.DogWalk;
import Services.FoodDelivery;
import Services.Service;
import Services.YardWork;

public class Customer {
	private ARRNode[] head = new ARRNode[3]; // array of linear linked list

	// public wrapper function to insert data into array of linear linked list
	public void insert(Service data) {

		try {
			FoodDelivery f = new FoodDelivery();
			f = (FoodDelivery) data;

			if (head[0] == null) {
				head[0] = new ARRNode(data);
				return;
			}

			insert(f, head[0]);
		} catch (ClassCastException e) {

			try {
				YardWork y = new YardWork();
				y = (YardWork) data;

				if (head[1] == null) {
					head[1] = new ARRNode(data);
					return;
				}

				insert(y, head[1]);
			} catch (ClassCastException e2) {

				try {
					DogWalk d = new DogWalk();
					d = (DogWalk) data;

					if (head[2] == null) {
						head[2] = new ARRNode(data);
						return;
					}

					insert(d, head[2]);
				} catch (ClassCastException e3) {
					System.out.println("IT IS NONE OF THE ABOVE");
				}
			}
		}

	}

	// private recursive function to insert service into array of linear linked
	// list
	private void insert(Service toAdd, ARRNode current) {

		if (current.getNext() == null) {
			ARRNode temp = new ARRNode(toAdd);
			current.setNext(temp);
			return;
		}

		insert(toAdd, current.getNext());

	}

	// public wrapper function to display customers jobs
	public void display() {
		displayARR(0);
	}

	// private recursive function to traverse/display the array part of data
	// structure
	private void displayARR(int index) {
		if (index == head.length) {
			return;
		}

		displayList(head[index]);
		displayARR(index + 1);

	}

	// private recursive function to traverse/display the linear linked list
	// part of data structure
	private void displayList(ARRNode current) {

		if (current == null) {
			return;
		}

		current.displayNode();
		displayList(current.getNext());

	}

	/*
	 * public void build() { FoodDelivery f = new FoodDelivery("num1", "num1",
	 * 1, 1); insert(f);
	 * 
	 * FoodDelivery f1 = new FoodDelivery("num2", "num2", 2, 2); insert(f1);
	 * 
	 * FoodDelivery f2 = new FoodDelivery("num3", "num3", 3, 3); insert(f2);
	 * 
	 * YardWork y = new YardWork("num4", "num4", 4, 4); insert(y);
	 * 
	 * DogWalk d = new DogWalk("num5", "num5", 5, 5); insert(d);
	 * 
	 * }
	 */

	// public wrapper function to find/retrieve service from data structure
	public boolean retrieve(String title) {
		boolean found = retrieveARR(title, 0);
		return found;

	}

	// private recursive function to retrieve the array part of data structure
	private boolean retrieveARR(String title, int index) {
		if (index == head.length) {
			return false;
		}

		boolean found = retrieveList(title, head[index]);
		if (found == true) {
			return true;
		}

		return retrieveARR(title, index + 1);
	}

	// private recursive function to retrieve the linear linked list part of
	// data structure
	private boolean retrieveList(String title, ARRNode current) {

		if (current == null) {
			return false;
		}

		if (current.getData().isEqualTo(title)) {
			return true;
		}

		return retrieveList(title, current.getNext());
	}

	// public wrapper function to remove service from data structure
	public void remove(String title) {
		removeARR(title, 0);
	}

	// private recursive function to remove from the array part of data
	// structure
	private void removeARR(String title, int index) {
		if (index == head.length) {
			return;
		}

		head[index] = removeList(title, head[index], head[index], null);
		removeARR(title, index + 1);

	}

	// private recursive function to remove from the linear linked list part of
	// data structure
	private ARRNode removeList(String title, ARRNode head, ARRNode current, ARRNode prev) {

		if (current == null) {
			return head;
		}

		if (current.getData().isEqualTo(title)) {
			if (current == head) {
				return current.getNext();
			}
			prev.setNext(current.getNext());
			current.setNext(null);
			return head;
		}

		return removeList(title, head, current.getNext(), current);
	}

	// public wrapper function to remove all in data structure
	public void removeAll() {
		removeAll(0);
	}

	// private recursive function to remove all data in data structure
	private void removeAll(int index) {
		if (index == head.length) {
			return;
		}

		head[index] = null;
		removeAll(index + 1);
	}

	// public wrapper function to update data structure to file
	public int updateFile() throws IOException {

		FileWriter myWriter = new FileWriter("MyJobs.txt", false);

		updateFileARR(0, myWriter);

		myWriter.close();

		return 0;
	}

	// private recursive function to traverse the array part of the data
	// structure
	private void updateFileARR(int index, FileWriter myWriter) throws IOException {
		if (index == head.length) {
			return;
		}

		updateFileList(head[index], myWriter);
		updateFileARR(index + 1, myWriter);

	}

	// private recursive function to update the linear linked list part of the
	// data structure
	private void updateFileList(ARRNode current, FileWriter myWriter) throws IOException {
		if (current == null) {
			return;
		}

		current.writeOut(myWriter);
		updateFileList(current.getNext(), myWriter);
	}

	// public function to load data from file
	public void loadData() throws IOException {

		Path currentRelativePath = Paths.get("MyJobs.txt");
		String filePath = currentRelativePath.toAbsolutePath().toString();

		File file = new File(filePath);
		Scanner sc = new Scanner(file);

		String title;
		String description;
		double pay;

		while (sc.hasNextLine()) {
			String line = sc.nextLine();
			String[] splitLine = line.split("\\|");

			if (splitLine[0].compareTo("F") == 0) {
				title = splitLine[1];
				description = splitLine[2];
				pay = Double.parseDouble(splitLine[3]);
				int distance = Integer.parseInt(splitLine[4]);

				FoodDelivery f = new FoodDelivery(title, description, pay, distance);
				insert(f);
			}

			if (splitLine[0].compareTo("Y") == 0) {
				title = splitLine[1];
				description = splitLine[2];
				pay = Double.parseDouble(splitLine[3]);
				int yardSize = Integer.parseInt(splitLine[4]);

				YardWork y = new YardWork(title, description, pay, yardSize);
				insert(y);
			}

			if (splitLine[0].compareTo("D") == 0) {
				title = splitLine[1];
				description = splitLine[2];
				pay = Double.parseDouble(splitLine[3]);
				int numOfDogs = Integer.parseInt(splitLine[4]);

				DogWalk d = new DogWalk(title, description, pay, numOfDogs);
				insert(d);
			}
		}

	}

}
