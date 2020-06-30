#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//node for linear linked list of accessories
struct list{
	char *name;
	char *category;
	char *status;
	list *next;
};

//node for linear linked list of rooms
struct node{
	char *name;
	node *next;
	list *listhead;
};


class CS_smart_home{

	public:
		CS_smart_home(); //constructor
		~CS_smart_home(); //destructor
		void displayRooms(); //displays rooms
		int addRoom(char roomName[]); //adds room to list of rooms
		int removeRoom(char roomName[]); //removes room from list of rooms
		int addAccessory(char roomName[],char accessoryName[],char category[],char status[]); //adds accessory to list of accessories within a room
		int removeAccessory(char roomName[],char accessoryName[]); //removes accessory from list of accessories within a room
		int displayRoomAccessories(char roomName[]); //displays accessories in particular room
		int displayAll(); //displays all accessories across all rooms

	private:
		node * head;
		
};
