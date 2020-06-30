//Sourabh Jamalapuram, CS163 Data Structures
//The Following Program Uses A Hash Table To store information such as a meal name, venue name, the price, the rating, a review, and the venue type(restaurant or food cart). The Program Starts By Prompting the user to choose between five choices. (1) Add Restaurant will allow the user to add information about the restaurnat and the food, (2) remove by meal will remove all restaurants that serve that type of food. (3)remove by venue will remove all the items that the venue serves. (4)retrieve information will check to see if the meal is in the data structure.(5) Will display the information of a particular meal.

#include "table.h"

int main(){
	
	int userOption;
	char again;
	char mealName[50];
	char venueName[50];
	int price = 0;
	int rating = 0;
	char review[50];
	char venueType[50];

	table table;

	char key[10];
	strcpy(key,"F");

	do{

		cout<<"Select From One Of The Following Options"<<endl;
		cout<<"_______________________________________"<<endl;
		cout<<"(1)Add New Restaurant"<<endl;
		cout<<"(2)Remove By Meal"<<endl;
		cout<<"(3)Remove By Venue"<<endl;
		cout<<"(4)Retrieve Information"<<endl;
		cout<<"(5)Display Info Of Particular Meal"<<endl;
	
		cin>>userOption;
		cin.ignore(100,'\n');

		if(userOption == 1){	

			cout<<"\nEnter Meal Name: "<<endl;
                        cin.get(mealName,100,'\n');
                        cin.ignore(100,'\n');

			cout<<"\nEnter Venue Name: "<<endl;
        		cin.get(venueName,100,'\n');
        		cin.ignore(100,'\n');

			cout<<"\nEnter Price: "<<endl;
                        cin>>price;
                        cin.ignore(100,'\n');

			cout<<"\nEnter Rating: "<<endl;
                        cin>>rating;
                        cin.ignore(100,'\n');

			cout<<"\nEnter Review: "<<endl;
                        cin.get(review,100,'\n');
                        cin.ignore(100,'\n');

                        cout<<"\nEnter Venue Type: "<<endl;
                        cin.get(venueType,100,'\n');
                        cin.ignore(100,'\n');

			table.insert(mealName,venueName,price,rating,review,venueType);

		}else if(userOption == 2){
			cout<<"\nEnter Meal Name: "<<endl;
                        cin.get(mealName,100,'\n');
                        cin.ignore(100,'\n');

			table.removeByMeal(mealName);
		}else if(userOption == 3){
			cout<<"\nEnter Venue Name: "<<endl;
                        cin.get(venueName,100,'\n');
                        cin.ignore(100,'\n');

			table.removeByVenue(venueName);


		}else if(userOption == 4){
			cout<<"\nEnter Meal Name: "<<endl;
                        cin.get(mealName,100,'\n');
                        cin.ignore(100,'\n');

			bool found = table.retrieve(mealName,mealName,venueName,price,rating,review,venueType);

			if(found == true){
				cout<<"Found!!!"<<endl;
			}else{
				cout<<"Not Found!!!"<<endl;
			}


		}else if(userOption == 5){
			
			cout<<"\nEnter Meal Name: "<<endl;
                	cin.get(mealName,100,'\n');
                	cin.ignore(100,'\n');

			table.display(mealName);



                	
		}else{
			cout<<"coming soon!!!"<<endl;
		}


		cout<<"Would You Like To Continue(Y/N): "<<endl;
		cin>>again;
		cin.ignore(100,'\n');
		again = toupper(again);

	}while(again == 'Y');



	




	return 0;

}
