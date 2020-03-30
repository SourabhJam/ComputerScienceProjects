//Sourabh Jamalapuram, CS163 Data Structures, main.cpp
//The main program is the program that interacts with the user by prompting them if they want to add classes, add pre req's, display pre reqs, and display course pathway, and quit.

#include "graph.h"

int main(){

	table graph; //graph

	char vertex[50]; // used to add a vertex
	char preReq[50]; // used to add a pre req/edge
	int userInput; //for user input to see what they want to do
	
	do{
		cout<<"\n(1)Add Class"<<endl;
		cout<<"(2)Add Pre Req"<<endl;
		cout<<"(3)Display Pre Req's"<<endl;
		cout<<"(4)Display ALL Pre Req's(BFS)"<<endl;
		cout<<"(5)Quit"<<endl;
		cout<<"Select One Of The Following: "<<endl;
		cin>>userInput;
		cin.ignore(100,'\n');

		if(userInput == 1){
			cout<<"\nEnter Class Name: "<<endl;
			cin.get(vertex,100,'\n');
			cin.ignore(100,'\n');

			graph.insertVertex(vertex);
		}else if(userInput == 2){
			cout<<"\nEnter Class You Wish To Add Pre Req Too: "<<endl;
			cin.get(vertex,100,'\n');
			cin.ignore(100,'\n');

			cout<<"\nEnter Pre Req For Class: "<<endl;
			cin.get(preReq,100,'\n');
			cin.ignore(100,'\n');

			graph.insertEdge(vertex,preReq);
		}else if(userInput == 3){
			cout<<"\nEnter Class You Want To Take: "<<endl;
                        cin.get(vertex,100,'\n');
                        cin.ignore(100,'\n');

			graph.display(vertex);

		}else if(userInput == 4){
			cout<<"Enter Class You Want To Take: "<<endl;
			cin.get(vertex,100,'\n');
			cin.ignore(100,'\n');

			graph.BFS(vertex);

		}else if(userInput == 5){


		}else{

			cout<<"\nEnter Valid Input!!!"<<endl;
		}

	}while(userInput !=5);
	

	return 0;

}
