#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


struct travelInfo{
	char *streetName;
	char *city;
	int length;
	char *traffic;
	char *notes;
};

struct node{
	struct travelInfo travelInfo;
	node * next;

	~node();
};




class queue{

	public:
		queue(); //initialize private data members
		~queue(); //deallocate all dynamic memory
		void enqueue(char streetName[],int length,char traffic[],char notes[],char city[]); //add travel information to circular linked list 
		int dequeue(); //take out travel information from CLL 
		void peek(); //display top travel information in queue
		void display(); //display CLL


	private:
		node *front;
		node *rear;


};
