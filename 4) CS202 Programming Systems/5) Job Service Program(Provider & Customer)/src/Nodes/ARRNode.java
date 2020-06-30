//CS202 Programming Systems, Sourabh Jamalapuram, Program #5
//ARRNode.java, contains the class and function implementations for a node in an array of linear linked list

package Nodes;

import java.io.FileWriter;
import java.io.IOException;

import Services.Service;

public class ARRNode {
	private Service data; //Service
	private ARRNode next; //Next Node

	// constructor to initialize private data members of ARRNode
	public ARRNode(Service data) {
		this.data = data;
		next = null;
	}

	//function to get node's next node
	public ARRNode getNext() {
		return this.next;
	}
	
	//function to get node's data
	public Service getData() {
		return this.data;
	}

	//function to set node's next node
	public void setNext(ARRNode temp) {
		this.next = temp;
	}

	//function to display service in node
	public void displayNode() {
		this.data.display();
	}

	//function to write data in node to external data file
	public void writeOut(FileWriter myWriter) throws IOException {
		this.data.writeOut(myWriter);
	}

}
