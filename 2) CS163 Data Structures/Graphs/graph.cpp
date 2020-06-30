//Sourabh Jamalapuram, CS163 Data Structures, graph.cpp
//The purpose of graph.cpp is to implement the functions. This file contains the implementation for the constructore,destrcutor, add vertex, add edge, display, and BFS.

#include "graph.h"

//constructor to initialize private data members
table::table(int size){
	
	adjacencyList = new vertex[size];
	
	for(int i=0;i<size;++i){
		adjacencyList[i].className = NULL;
		adjacencyList[i].head = NULL;
	}

	listSize = size;
}

//destructor to deallocate all dynamically allocated memory
table::~table(){

	for(int i=0;i<listSize;++i){

		node *current = adjacencyList[i].head;
    
        	while(current){
                	node *temp = current->next;
                	delete current;
                	current = temp;
        	}   


                delete adjacencyList[i].className;             
        }   

	delete adjacencyList;

}

			
//function to insert vertex/class. INPUT: class name OUPUT: integer value based on success or failure to insert
int table::insertVertex(char *className){
	
	int i = 0;

	while(adjacencyList[i].className && i<listSize){
		i = i + 1;
	}

	if(i >= listSize){
		cout<<"\nSorry Cannot Insert: "<<className<<endl;
		return 1;
	}
	

	adjacencyList[i].className = new char[strlen(className) + 1];
	strcpy(adjacencyList[i].className,className);


}

//function to find location of class in table. INPUT: class name OUTPUT: integer value based on location in table
int table::findLocation(char *className){	
	for(int i=0;i<listSize;++i){
		if(adjacencyList[i].className == NULL){
			return -1;
		}

		if(strcmp(adjacencyList[i].className,className) == 0){
			return i;
		}

		
	}
	return -1;

}


//function to insert edge to a vertex. INPUT: class name and pre req name OUTPUT: integer value based on success or failure of insertion
int table::insertEdge(char *firstVertex, char *secondVertex){
	
	int connection1 = findLocation(firstVertex);
	int connection2 = findLocation(secondVertex);
	
	if(connection1 == -1 || connection2 == -1){
		cout<<"\nInvalid Classes!!!"<<endl;
		return 1;
	}

	if(adjacencyList[connection1].head == NULL){
		adjacencyList[connection1].head = new node;
		adjacencyList[connection1].head->adjacent = &adjacencyList[connection2];
		adjacencyList[connection1].head->next = NULL;
	}else{

		node *temp = new node;
		temp->adjacent = &adjacencyList[connection2];
		temp->next = adjacencyList[connection1].head;
		adjacencyList[connection1].head = temp;
		
	}
}


//public member function to call private display function. INPUT: class name OUTPUT:integer value based on success or failure upon finding the class.
int table::display(char *key){

	int startLocation = findLocation(key);

	if(startLocation == -1){
		cout<<"\nCannot Find Class!!!"<<endl;
		return 1;
	}

	cout<<"\nIn Order To Take "<<adjacencyList[startLocation].className<<endl;	
	cout<<"___________________"<<endl;
	display(key,adjacencyList[startLocation].head);
}


//private function to display pre reqs for a class. INPUT: class name and head of edge list OUTPUT: integer value based on success or failure upon finding the class
int table::display(char *key,node *head){

	if(!head){
		return 0;
	}

	display(key,head->next);
 	if(head->adjacent){
                        cout<<"You Have To Take "<<head->adjacent->className<<endl;
        }   


}

//public member function to call the private BFS function. INPUT: class name OUTPUT: integer value based on success or failure upon finding the class.
int table::BFS(char *key){

	int startLocation = findLocation(key);

        if(startLocation == -1){
                cout<<"\nCannot Find Class!!!"<<endl;
                return 1;
        }   
	
	cout<<"\nHere Are List Of ALL Pre Req's"<<endl;
	cout<<"___________________________________"<<endl;
        BFS(key,&adjacencyList[startLocation]);

} 



//private function to do a breadth first traversal and display contents given a vertex. INPUT: class name and vertex OUTPUT: integer value based on success or failure upon finding the class.
int table::BFS(char *key, vertex *vertex){
	
	
	node *current = vertex->head;
	

	display(key,current);

	while(current){

		if(!vertex){
			return 1;
		}

		if(!vertex->head){
			return 1;
		}       

		BFS(current->adjacent->className,current->adjacent);

		current = current->next;

	}

	
}



