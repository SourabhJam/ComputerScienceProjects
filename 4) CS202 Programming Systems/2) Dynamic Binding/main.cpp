//Sourabh Jamalapuram
//main.cpp, where the program starts. Starts by asking the user if they want to add, remove, display, or retrieve an activity and calls the respective functions based on the user input
#include "library.h"
#include "activity.h"

int main(){


	library lib;
	

	char title[50]; //input title
	char rating[50]; //rating of movie
	char cuisine[50]; //cuisine of food
	int priority; //priority
	int length; //length of activity
	char group; // is group activity or not
	bool isGroup; //is group activity or not
	int elevation; //elevation

	int userInput; //user input
	int activityChoice; //which activity input



	do{
		cout<<"\n(1)Add Activity"<<endl;
		cout<<"(2)Remove Activity"<<endl;
		cout<<"(3)Display All Activities(Prioritized)"<<endl;
		cout<<"(4)Retrieve Activity"<<endl;
		cout<<"(5)Display Top Priority Activities"<<endl;
		cout<<"(6)Remove All"<<endl;
		cout<<"(7)Display Movies By Rating"<<endl;
		cin>>userInput;
		cin.ignore(100,'\n');

		if(userInput == 1){
			cout<<"\n(1)Hike"<<endl;
			cout<<"(2)Movie"<<endl;
			cout<<"(3)Eat"<<endl;
			cout<<"What Activity Would You Like To Add: "<<endl;
			cin>>activityChoice;
			cin.ignore(100,'\n');

			if(activityChoice == 1){
				cout<<"Enter Name Of Hike: "<<endl;
				cin.get(title,100,'\n');
				cin.ignore(100,'\n');
				
				do{	
					cout<<"Enter Priority 1(High Priority) - 5(Low Priority): "<<endl;
					cin>>priority;
					cin.ignore(100,'\n');
				}while(priority<1 || priority >5);

				cout<<"Enter Time Estimated(minutes): "<<endl;
				cin>>length;
				cin.ignore(100,'\n');

				cout<<"Is This A Group Activity(Y/N): "<<endl;
				cin>>group;
				cin.ignore(100,'\n');
				group = toupper(group);
	
				if(group == 'Y'){
					isGroup = true;
				}else{
					isGroup = false;
				}

				cout<<"Enter Elevation: "<<endl;
                                cin>>elevation;
                                cin.ignore(100,'\n');

				hike *h = new hike(title,priority,length,isGroup,elevation);
				lib.addActivity(h);
				
				
			}
		
			else if(activityChoice == 2){
				cout<<"Enter Name Of Movie: "<<endl;
				cin.get(title,100,'\n');
				cin.ignore(100,'\n');
				
				do{
					cout<<"Enter Priority 1(High Priority) - 5(Low Priority): "<<endl;
                                	cin>>priority;
                                	cin.ignore(100,'\n');
				}while(priority<1 || priority>5);

				cout<<"Enter Time Estimated(minutes): "<<endl;
                                cin>>length;
                                cin.ignore(100,'\n');

				cout<<"Is This A Group Activity(Y/N): "<<endl;
                                cin>>group;
                                cin.ignore(100,'\n');
                                group = toupper(group);
    
                                if(group == 'Y'){
                                        isGroup = true;
                                }else{
                                        isGroup = false;
                                } 

				cout<<"Enter Movie Rating(G,PG,PG13,R,NC17): "<<endl;
                                cin.get(rating,100,'\n');
                                cin.ignore(100,'\n');
				
				movie *m = new movie(title,priority,length,isGroup,rating);
				lib.addActivity(m);
				
			}else if(activityChoice == 3){
				cout<<"Enter Name Of Restaurant: "<<endl;
                                cin.get(title,100,'\n');
                                cin.ignore(100,'\n');
				
				do{
                                	cout<<"Enter Priority 1(High Priority) - 5(Low Priority): "<<endl;
                                	cin>>priority;
                                	cin.ignore(100,'\n');
				}while(priority<1 || priority>5);

                                cout<<"Enter Time Estimated(minutes): "<<endl;
                                cin>>length;
                                cin.ignore(100,'\n');

                                cout<<"Is This A Group Activity(Y/N): "<<endl;
                                cin>>group;
                                cin.ignore(100,'\n');
                                group = toupper(group);

                                if(group == 'Y'){
                                        isGroup = true;
                                }else{
                                        isGroup = false;
                                }

                                cout<<"Enter Cuisine Served At Restaurant: "<<endl;
                                cin.get(cuisine,100,'\n');
                                cin.ignore(100,'\n');

				eat *e = new eat(title,priority,length,isGroup,cuisine);
				lib.addActivity(e);
			}

		

			else{
				cout<<"Invalid Activity!!!"<<endl;
			}
		}else if(userInput == 2){
				cout<<"Enter The Name Of The Activity You Would Like To Remove: "<<endl;
				cin.get(title,100,'\n');
				cin.ignore(100,'\n');

				lib.remove(title);
		}else if(userInput == 3){
			lib.display();
		}


		else if(userInput == 4){
			activity *pa;
			bool found;

			cout<<"Enter Name Of Activity You Would Like To Find: "<<endl;
			cin.get(title,100,'\n');
			cin.ignore(100,'\n');

			found = lib.retrieve(title,&pa);
			
			if(found == true){
				cout<<"FOUND!!!"<<endl;
			}else{
				cout<<"NOT FOUND!!!"<<endl;
			}

		}else if(userInput == 5){
			lib.displayTopPriority();
		}

		else if(userInput == 6){
			lib.removeAll();

		}

		else if(userInput == 7){
			cout<<"Which Rating Movies Would You Like To See: "<<endl;
			cin.get(rating,100,'\n');
			cin.ignore(100,'\n');

			lib.displayMoviesByRating(rating);

		}	

		else{
			cout<<"Enter Valid Option!!!"<<endl;
		}

	}while(userInput != 0);

	return 0;

}
