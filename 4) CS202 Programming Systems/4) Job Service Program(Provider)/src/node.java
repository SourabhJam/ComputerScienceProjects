
//CS202 Programming Systems, Sourabh Jamalapuram, Program #4
//node.java, contains the class and function implementations for node

import java.io.FileWriter;
import java.io.IOException;

public class node {
	private Service data; // Service
	private node left; // left Node
	private node right; // right Node
	int height; // height of node

	// constructor to initialize private data members of node
	node(Service data) {
		this.data = data;
		height = 1;
		left = null;
		right = null;
	}

	// function to get nodes data
	public Service getData() {
		return this.data;
	}

	// function to get height of node
	public int getHeight() {
		return this.height;
	}

	// function to get nodes left node
	public node getLeft() {
		return this.left;
	}

	// function to get nodes right node
	public node getRight() {
		return this.right;
	}

	// function to set nodes left node
	public void setLeft(node toSet) {
		this.left = toSet;
	}

	// function to set nodes left node
	public void setRight(node toSet) {
		this.right = toSet;
	}

	// function to set nodes height
	public void setHeight(int height) {
		this.height = height;
	}

	// function to display nodes contents
	public void displayNode() {
		this.data.display();
	}

	//// function to write data in node to external data file
	public void writeOut(FileWriter myWriter) throws IOException {
		this.data.writeOut(myWriter);
	}

}
