#include <iostream>
#include "CS_smart_home.h"


int main(){

	CS_smart_home smartHome; //smarthome
	char roomName[100]; //name of room
	char accessoryName[100]; //name of accessory
	char category[50]; //name of category
	char status[50]; //name of status
	int userOption; //user option
	char continueProg; //continue program
	bool again; //again


do{
	cout<<"\nWelcome To Your Smart Home. Select One Of The Following Options "<<endl;
	cout<<"1. Add New Room"<<endl;
	cout<<"2. Delete Room"<<endl;
	cout<<"3. Display Rooms"<<endl;
	cout<<"4. Add Accessory"<<endl;
	cout<<"5. Remove Accessory"<<endl;
	cout<<"6. Display Room Accessories"<<endl;
	cout<<"7. Display All Accessories"<<endl;
	cout<<"8. Quit"<<endl;
	cout<<"____________________________"<<endl;
	cin>>userOption;
	cin.ignore(100,'\n');

	if(userOption==1){
		cout<<"\nEnter Room Name: "<<endl;
		cin.get(roomName,100,'\n');
		cin.ignore(100,'\n');

		smartHome.addRoom(roomName);
	}else if(userOption == 2){
		cout<<"Enter Name Of Room You Would Like To Remove: "<<endl;
		cin.get(roomName,100,'\n');
		cin.ignore(100,'\n');

		int found = smartHome.removeRoom(roomName);

		if(found == 2){
			cout<<"\nRoom Not Found!!!"<<endl;
		}

	}else if(userOption==3){
		smartHome.displayRooms();
	}else if(userOption == 4){
		cout<<"\nEnter Name Of Room You Would Like To Add Accessory To: "<<endl;
		cin.get(roomName,100,'\n');
		cin.ignore(100,'\n');

		cout<<"\nEnter Name Of Accessory: "<<endl;
		cin.get(accessoryName,100,'\n');
		cin.ignore(100,'\n');

		cout<<"\nEnter Category Of Accessory: "<<endl;
		cin.get(category,100,'\n');
		cin.ignore(100,'\n');

		cout<<"\nEnter Status Of Accessory: "<<endl;
		cin.get(status,100,'\n');
		cin.ignore(100,'\n');

		int found = smartHome.addAccessory(roomName,accessoryName,category,status);

		if(found == 1){
			cout<<"\nRoom Not Found!!!"<<endl;
		}
		


	}else if(userOption==5){
		cout<<"\nEnter Name Of Room You Would Like To Remove Accessory From: "<<endl;
		cin.get(roomName,100,'\n');
		cin.ignore(100,'\n');

		cout<<"\nEnter Name Of Acessory You Would Like To Remove: "<<endl;
		cin.get(accessoryName,100,'\n');
		cin.ignore(100,'\n');

		int found = smartHome.removeAccessory(roomName,accessoryName);

		if(found == 1){
			cout<<"\nRoom/Accessory Not Found!!!"<<endl;
		}

	}else if(userOption==6){
		cout<<"\nWhich Room's Accessories Would You Like To View: "<<endl;
		cin.get(roomName,100,'\n');
		cin.ignore(100,'\n');

		int found = smartHome.displayRoomAccessories(roomName);

		if(found == 1){
			cout<<"\nRoom Not Found!!!"<<endl;
		}
	}else if(userOption==7){
		smartHome.displayAll();
	}else if(userOption<1 || userOption >8){
		cout<<"\nEnter Valid Command!!!"<<endl;
	}


	//cout<<"\nWould You Like To Continue(Y/N): "<<endl;
	//cin>>continueProg;
	//continueProg = toupper(continueProg);
	
	continueProg = 'Y';

	if(userOption == 8){
		continueProg = 'N';
	}

}while(continueProg == 'Y');


	return 0;
}
