package Nodes;

//CS202 Programming Systems, Sourabh Jamalapuram, Program #5
//BSTNode.java, contains the class and function implementations for a balanced tree node

import java.io.FileWriter;
import java.io.IOException;

import Services.Service;

public class BSTNode {
	private Service data; // Service
	private BSTNode left; // left Node
	private BSTNode right; // right Node
	int height; // height of node

	// constructor to initialize private data members of node
	public BSTNode(Service data) {
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
	public BSTNode getLeft() {
		return this.left;
	}

	// function to get nodes right node
	public BSTNode getRight() {
		return this.right;
	}

	// function to set nodes left node
	public void setLeft(BSTNode toSet) {
		this.left = toSet;
	}

	// function to set nodes left node
	public void setRight(BSTNode toSet) {
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
