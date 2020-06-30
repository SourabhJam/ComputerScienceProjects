//Sourabh Jamalapuram
//main.cpp, this is where the program starts by prompting the user if they would like to insert, remove, display, retrieve, remove all, save to file, or quit program
#include "string.h"
#include "activity.h"
#include "BST.h"

int main(){
	
	BST tree; //binary search tree

	int userInput; //user input for choices
	int activityChoice; //user input for activity choice

	String title; //activity title
	String subject; //activity subject
	int priority; //activity priority

	int ID; //zoom ID
	String startLocation; //travel starting location
	String destination; //travel destination
	String method; //restaurant delievery method

	tree.loadData(); //function to load data from external data file

	do{
		cout<<"\n(1)Insert Activity"<<endl;	
		cout<<"(2)Display"<<endl;
		cout<<"(3)Remove"<<endl;
		cout<<"(4)Retrieve"<<endl;
		cout<<"(5)Remove All"<<endl;
		cout<<"(6)Save To File"<<endl;
		cout<<"(0)Quit"<<endl;
		cout<<"What Would You Like To Do: ";
		cin>>userInput;
		cin.ignore(100,'\n');

		if(userInput == 1){
			do{
				cout<<"\n(1)Zoom"<<endl;
				cout<<"(2)Travel"<<endl;
				cout<<"(3)Restaurant"<<endl;
				cout<<"Which Activity Would You Like To Insert: ";
				cin>>activityChoice;
				cin.ignore(100,'\n');
				
				if(activityChoice<1 || activityChoice > 3){
					cout<<"\nPlease Enter Valid Number!"<<endl;
				}

			}while(activityChoice < 1 || activityChoice > 3);


			if(activityChoice == 1){
				cout<<"\nEnter Zoom Title: ";
				cin>>title;
				cin.ignore(100,'\n');

				cout<<"Enter Subject Of Zoom Meeting(Ex|Work,School,Recreation): ";
				cin>>subject;
				cin.ignore(100,'\n');
				
				cout<<"Enter Priority Of Zoom Meeting(1-5): ";
				cin>>priority;
				cin.ignore(100,'\n');

				cout<<"Enter Zoom ID: ";
				cin>>ID;
				cin.ignore(100,'\n');

				zoom *z = new zoom(title,subject,priority,ID);
				tree.insert(z);

			}


			if(activityChoice == 2){
				cout<<"\nEnter Travel Title: ";
                                cin>>title;
                                cin.ignore(100,'\n');

                                cout<<"Enter Subject Of Travel(Ex|Work,School,Recreation): ";
                                cin>>subject;
                                cin.ignore(100,'\n');
    
                                cout<<"Enter Priority Of Travel(1-5): ";
                                cin>>priority;
                                cin.ignore(100,'\n');

                                cout<<"Enter Start Location: ";
                                cin>>startLocation;
                                cin.ignore(100,'\n');

				cout<<"Enter Destination: ";
				cin>>destination;
				cin.ignore(100,'\n');

                                travel *t = new travel(title,subject,priority,startLocation,destination);
                                tree.insert(t);

			}

			if(activityChoice == 3){
				cout<<"\nEnter Restaurant Name: ";
                                cin>>title;
                                cin.ignore(100,'\n');

                                cout<<"Enter Subject Of Restaurant Visit(Ex|Work,School,Recreation): ";
                                cin>>subject;
                                cin.ignore(100,'\n');
    
                                cout<<"Enter Priority Of Going To Restaurant(1-5): ";
                                cin>>priority;
                                cin.ignore(100,'\n');

                                cout<<"Enter Restaurant Delivery Method(Ex|Delivery,Take Out,Curb Side Pickup): ";
                                cin>>method;
                                cin.ignore(100,'\n');

                                restaurant *r = new restaurant(title,subject,priority,method);
                                tree.insert(r);

			}

		}

		if(userInput == 2){
			tree.display();
		}

		if(userInput == 3){
			cout<<"Enter Name Of Activity You Would Like To Remove: ";
			cin>>title;
			tree.remove(title);
		}

		if(userInput == 4){

			activity *pa;

			cout<<"Enter Name Of Activity You Would Like To Retrieve: ";
			cin>>title;
			bool found = tree.retrieval(title,&pa);

			if(found == true){
				cout<<"\nActivity Found!"<<endl;
			}else{
				cout<<"\nActivity NOT Found!"<<endl;
			}

		}

		if(userInput == 5){
			tree.removeAll();
		}

		if(userInput == 6){
			tree.updateFile();
		}


	}while(userInput != 0);



	
	tree.removeAll();	


}
