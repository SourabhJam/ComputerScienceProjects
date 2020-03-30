//Sourabh Jamalapuram, CS163 Data Structures
//The following program uses a binary search tree to store information such as a meal name, venue name, the price, the rating, a review, and the venue type(restaurant or food cart). The Program Starts By Prompting the user to choose between seven choices.(1)Add new meal will allow the user to add information about the restaurnat and the food.(2) Search Meal will check the binary search tree for a meal and report back true if it finds a match and false if it doesn't find a match. The function also returns the matches through the arguments.(3) display matches will display all meal info based on meal matches.(4) remove meal will remove a meal from the BST.(5) height of tree will give the height of tree.(6) display all will display all meal info in sorted order.(7)IsEfficient will check to see if binary search tree is balanced or not.
#include "bst.h"


int main(){

	table BST;
	
	int userOption;
	char again;

	char mealName[50];
	char venueName[50];
	int price = 0;
	int rating = 0;
	char review[50];
	char venueType[50];

	mealInfo matches[5];

	do{

		cout<<"Select From One Of The Following Options"<<endl;
		cout<<"_______________________________________"<<endl;
		cout<<"(1)Add New Meal"<<endl;
		cout<<"(2)Search Meal"<<endl;
		cout<<"(3)Display Matches"<<endl;
		cout<<"(4)Remove Meal"<<endl;
		cout<<"(5)Height Of Tree"<<endl;
		cout<<"(6)Display All"<<endl;
		cout<<"(7)Is Efficient? "<<endl;

	
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

			BST.addNewMeal(mealName,venueName,price,rating,review,venueType);
			BST.displayAll();
		}else if(userOption == 2){
			
			cout<<"\nEnter Meal Name: "<<endl;
                        cin.get(mealName,100,'\n');
                        cin.ignore(100,'\n');
	
			int matchNum = BST.searchMeal(mealName,matches);
			cout<<"Found "<<matchNum<<" matches"<<endl;
		}else if(userOption == 3){
    
                        cout<<"\nEnter Meal Name: "<<endl;
                        cin.get(mealName,100,'\n');
                        cin.ignore(100,'\n');
    
                        BST.displayMatches(mealName);
                }else if(userOption == 4){
    
                        cout<<"\nEnter Meal Name: "<<endl;
                        cin.get(mealName,100,'\n');
                        cin.ignore(100,'\n');

			cout<<"\nEnter Venue Name: "<<endl;
                        cin.get(venueName,100,'\n');
                        cin.ignore(100,'\n');
    
                        BST.removeMeal(mealName,venueName);
			BST.displayAll();
                }else if(userOption == 5){
			int treeHeight = BST.height();
			cout<<"\nHeight Of Tree Is: "<<treeHeight<<endl;
		}else if(userOption == 6){
			BST.displayAll();
		}else if(userOption == 7){
			bool efficient= BST.isEfficient();
			if(efficient == true){
				cout<<"Tree Is Efficient!"<<endl;
			}else{
				cout<<"Tree Is Not Efficient!"<<endl;
			}
		}

		cout<<"Would You Like To Continue(Y/N): "<<endl;
		cin>>again;
		cin.ignore(100,'\n');
		again = toupper(again);

	}while(again == 'Y');

	return 0;

}
