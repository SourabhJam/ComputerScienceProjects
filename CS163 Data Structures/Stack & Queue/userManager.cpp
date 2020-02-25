#include "userManager.h"

int userManager::getInfo(char streetName[],int length,char traffic[],char notes[], char city[]){
	
	cout<<"\nEnter Street Name: "<<endl;
	cin.get(streetName,100,'\n');
	cin.ignore(100,'\n');

	cout<<"Enter City: "<<endl;
	cin.get(city,100,'\n');
	cin.ignore(100,'\n');

	cout<<"Enter Length: "<<endl;
	cin>>length;
	cin.ignore(100,'\n');

	cout<<"Enter Traffic Update: "<<endl;
	cin.get(traffic,100,'\n');
	cin.ignore(100,'\n');

	cout<<"Enter Notes: "<<endl;
	cin.get(notes,100,'\n');
	cin.ignore(100,'\n');

	return length;


}

char userManager::again(){
	char again;	
	
	cout<<"\nContinue(Y/N): "<<endl;
	cin>>again;
	cin.ignore(100,'\n');
	again = toupper(again);

	return again;
}

int userManager::routeChoice(){
	int userOption = 0;	
	
	cout<<"Welcome To CS163 Maps. Please Input 1 Or 2 Depending On Which Route You Will Be Taking To Your Destination(The Alternate Route Will Be Stored For Backup): "<<endl;
	cin>>userOption;
	cin.ignore(100,'\n');

	while(userOption != 1 &&  userOption != 2){
		cout<<"Please Enter Either 1 Or 2: "<<endl;
		cin>>userOption;
		cin.ignore(100,'\n');
	}

	return userOption;

}



