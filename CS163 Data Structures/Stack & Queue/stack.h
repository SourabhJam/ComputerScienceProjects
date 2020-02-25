#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;



struct info{
	char *roadName;
	int length;
	char *traffic;
	char *notes;
	char *city;
};

struct Node{
	struct info *travelInfo;
	Node *next;
};



const int MAX = 5;


class stack{

	public:
		stack(); //initialize private data members
		~stack(); //deallocate all dynamic memory
		int push(char roadName[],int length,char traffic[],char notes[],char city[]); //push travel info on to stack
		int pop(); //remove travel information from stack
		int peek(); //view top of stack
		void display(); //display contents of the stack


	private:
		Node *head;
		int topIndex;


};
