//Sourabh Jamalapuram, CS163 Data Structures, graph.h
//file to define structures, table class, public and private function prototypes
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//structure containing class name and pointer to a head node
struct vertex{
	char *className;
	struct node *head;

};

//node structure containing pointer to a vertex and a pointer to next node
struct node{
	vertex *adjacent;
	node *next;
};

class table{
	

	public:
		table(int size=5); //constructor
		~table(); //destructor
		int insertVertex(char *className); //insert vertex
		int findLocation(char *className); //find location in table
		int insertEdge(char *firstVertex, char *secondVertex); //insert edge
		int display(char *key); //display pre req's
		int BFS(char *key); // breadth first traversal
		int build();


	private:
		vertex *adjacencyList; //vertexes for classes
		int listSize; //table size

		int display(char *key,node *head); //private function to display
		int BFS(char *key,vertex *vertex);//private function to do breadth first traversal

};
