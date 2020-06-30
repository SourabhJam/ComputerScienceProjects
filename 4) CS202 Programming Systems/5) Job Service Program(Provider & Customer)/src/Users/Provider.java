package Users;

//CS202 Programming Systems, Sourabh Jamalapuram, Program #5
//Provider.java, contains the root of the AVL tree and performs operations such as inserting, removing, retrieving from the tree 

import java.io.BufferedReader;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

import Nodes.BSTNode;
import Services.DogWalk;
import Services.FoodDelivery;
import Services.Service;
import Services.YardWork;

public class Provider {
	private BSTNode root; //root of AVL tree
	
	//build function. Customer cannot add or remove if the provider hasn't posted anything. For customer testing purposes this build function adds a couple job postings.
	public void build(){
		FoodDelivery f1 = new FoodDelivery("FoodDelivery1", "FoodDelivery1", 1, 1);
		insert(f1);
		
		FoodDelivery f2 = new FoodDelivery("FoodDelivery2", "FoodDelivery2", 2, 2);
		insert(f2);
		
		FoodDelivery f3 = new FoodDelivery("FoodDelivery3", "FoodDelivery3", 3, 3);
		insert(f3);
		
		YardWork y1 = new YardWork("YardWork1", "YardWork1", 1, 1);
		insert(y1);
		
		YardWork y2 = new YardWork("YardWork2", "YardWork2", 2, 2);
		insert(y2);
		
		YardWork y3 = new YardWork("YardWork3", "YardWork3", 3, 3);
		insert(y3);
		
		DogWalk d1 = new DogWalk("DogWalk1", "DogWalk1", 1, 1);
		insert(d1);
		
		DogWalk d2 = new DogWalk("DogWalk2", "DogWalk2", 2, 2);
		insert(d2);
		
		DogWalk d3 = new DogWalk("DogWalk3", "DogWalk3", 3, 3);
		insert(d3);
	}

	// function to find the max between two numbers
	public int findMax(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

	// function to rotate right side of tree to balance
	public BSTNode rotateRight(BSTNode current) {
		BSTNode leftTemp = current.getLeft();
		BSTNode rightTemp = leftTemp.getRight();

		leftTemp.setRight(current);
		current.setLeft(rightTemp);

		int left;
		int right;

		if (current.getLeft() == null) {
			left = 0;
		} else {
			left = current.getLeft().getHeight();
		}

		if (current.getRight() == null) {
			right = 0;
		} else {
			right = current.getRight().getHeight();
		}

		int currentHeight = 1 + findMax(left, right);
		current.setHeight(currentHeight);
		int leftHeight = 1 + findMax(leftTemp.getLeft().getHeight(), leftTemp.getRight().getHeight());

		leftTemp.setHeight(leftHeight);

		return leftTemp;
	}

	// function to rotate left side of tree to balance
	public BSTNode rotateLeft(BSTNode current) {
		BSTNode rightTemp = current.getRight();
		BSTNode leftTemp = rightTemp.getLeft();

		rightTemp.setLeft(current);
		current.setRight(leftTemp);

		int left;
		int right;

		if (current.getLeft() == null) {
			left = 0;
		} else {
			left = current.getLeft().getHeight();
		}

		if (current.getRight() == null) {
			right = 0;
		} else {
			right = current.getRight().getHeight();
		}

		int currentHeight = 1 + findMax(left, right);
		current.setHeight(currentHeight);

		int rightTempHeight = 1 + findMax(rightTemp.getLeft().getHeight(), rightTemp.getRight().getHeight());

		rightTemp.setHeight(rightTempHeight);

		return rightTemp;
	}

	// wrapper function to insert service into tree
	public void insert(Service toAdd) {
		if (root == null) {
			root = new BSTNode(toAdd);
			return;
		}

		BSTNode newRoot = insert(root, toAdd);
		this.root = newRoot;
	}

	// recursive function to insert Service into tree
	public BSTNode insert(BSTNode current, Service toAdd) {

		if (current == null) {
			current = new BSTNode(toAdd);
			return current;
		}

		if (toAdd.isLessThan(current.getData())) {
			current.setLeft(insert(current.getLeft(), toAdd));
		}

		if (toAdd.isGreaterThan(current.getData())) {
			current.setRight(insert(current.getRight(), toAdd));
		}

		else {
			return current;
		}

		int leftHeight;
		int rightHeight;

		if (current.getLeft() == null) {
			leftHeight = 0;
		} else {
			leftHeight = current.getLeft().getHeight();
		}

		if (current.getRight() == null) {
			rightHeight = 0;
		} else {
			rightHeight = current.getRight().getHeight();
		}

		int max = findMax(leftHeight, rightHeight);
		current.setHeight(1 + max);

		int balanceFactor = leftHeight - rightHeight;

		if (balanceFactor > 1 && toAdd.isLessThan(current.getLeft().getData())) {
			return rotateRight(current);
		}

		if (balanceFactor < -1 && toAdd.isGreaterThan(current.getRight().getData())) {
			return rotateLeft(current);
		}

		if (balanceFactor > 1 && toAdd.isGreaterThan(current.getLeft().getData())) {
			current.setLeft(rotateLeft(current.getLeft()));
			return rotateRight(current);
		}

		if (balanceFactor < -1 && toAdd.isLessThan(current.getRight().getData())) {
			current.setRight(rotateRight(current.getRight()));
			return rotateLeft(current);
		}

		return current;

	}

	// wrapper function to display contents of tree
	public void display() {
		if (root == null) {
			return;
		}

		display(root);
	}

	// recursive function to display contents of tree
	public void display(BSTNode current) {
		if (current == null) {
			return;
		}

		display(current.getLeft());
		current.displayNode();
		display(current.getRight());

	}

	// wrapper function to find height of a tree
	public int height() {

		if (root == null) {
			return 0;
		}

		return height(root);

	}

	// recursive function to find height of a tree
	public int height(BSTNode root) {

		if (root == null) {
			return 0;
		}

		int leftHeight = height(root.getLeft());
		int rightHeight = height(root.getRight());

		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		} else {
			return rightHeight + 1;
		}

	}

	// wrapper function to check if tree is balanced
	public void isEfficient() {
		isEfficient(root);
	}

	// recursive function to check if tree is balanced
	private void isEfficient(BSTNode root) {

		if (root == null) {
			return;
		}

		int leftHeight = height(root.getLeft());
		int rightHeight = height(root.getRight());

		System.out.println("\n\nLeft Height: " + leftHeight);
		System.out.println("Right Height: " + rightHeight);

	}

	// wrapper function to update tree contents to external data file
	public int updateFile() throws IOException {

		Path currentRelativePath = Paths.get("Services.txt");
		String filePath = currentRelativePath.toAbsolutePath().toString();
		
		FileWriter myWriter = new FileWriter(filePath, false);

		if (root == null) {
			return 0;
		}

		updateFile(root, myWriter);

		myWriter.close();

		return 0;
	}

	// recursive function to update tree contents to external data file
	private void updateFile(BSTNode current, FileWriter myWriter) throws IOException {
		if (current == null) {
			return;
		}

		updateFile(current.getLeft(), myWriter);
		current.writeOut(myWriter);
		updateFile(current.getRight(), myWriter);

	}

	// wrapper function to retrieve service from tree
	public Service retrieve(String title) {
		if (root == null) {
			return null;
		}

		Service found = retrieve(root, title);
		return found;
	}

	// recursive function to retrieve service from tree
	private Service retrieve(BSTNode current, String title) {
		if (current == null) {
			return null;
		}

		if (current.getData().isGreaterThan(title)) {
			return retrieve(current.getLeft(), title);
		}

		if (current.getData().isLessThan(title)) {
			return retrieve(current.getRight(), title);
		}

		return current.getData();
	}

	// function to load in data from external data file and insert it into
	// current running programs tree at start of the program
	public void loadData() throws IOException {

		Path currentRelativePath = Paths.get("Services.txt");
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

	// function to remove everything in tree
	public void removeAll() {
		if (root == null) {
			return;
		}

		root = null;
	}

	
}
