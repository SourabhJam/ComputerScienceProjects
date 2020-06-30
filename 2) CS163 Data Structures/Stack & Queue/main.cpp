//Sourabh Jamalapuram, CS163 Data Structures
//The Following Program Uses Two Instances Of Queue and one instance of a stack to store information such as streetname,city,length,traffic, and notes about each leg of the trip to a destination. The queue is used to store the information for directions there while the stack reverses it and gives you the directions back. The program will start by prompting the user to choose between route 1 and route 2. the route chosen will be saved as the primary while the other one will be saved as backup. Then the user is prompted to add information for both route 1 and route 2



#include "stack.h"
#include "queue.h"
#include "userManager.h"




int main(){

	userManager user;

	queue route1; //queue instance 1
	queue route2; //queue instance 2
	stack stack1; //stack instance 1

	char streetName[50]; //userInput street name
	char city[50]; //user input city
	int length = 0; //user length of leg
	char traffic[50]; //user input of traffic of leg
	char notes[50]; //user input of notes 
	char again; 

	int routeChoice = user.routeChoice();



	cout<<"\nRoute 1 Info Input"<<endl;
	cout<<"_________________"<<endl;
	
	do{
				
		length = user.getInfo(streetName,length,traffic,notes,city);
		
		if(routeChoice == 1){
			stack1.push(streetName,length,traffic,notes,city);
		}
		
		route1.enqueue(streetName,length,traffic,notes,city);

		again = user.again();

	
	}while(again == 'Y');


	cout<<"\nRoute 2 Info Input"<<endl;
	cout<<"_________________"<<endl;
	
	do{

		length = user.getInfo(streetName,length,traffic,notes,city);

		if(routeChoice == 2){
			stack1.push(streetName,length,traffic,notes,city);
		}

		route2.enqueue(streetName,length,traffic,notes,city);

		again = user.again();

	
	}while(again == 'Y');


	if(routeChoice == 1){
		route1.display();
		stack1.display();
		route1.peek();
		stack1.peek();
	}else{
		route2.display();
		stack1.display();
		route2.peek();
		stack1.peek();
	}
	
	return 0;

}
