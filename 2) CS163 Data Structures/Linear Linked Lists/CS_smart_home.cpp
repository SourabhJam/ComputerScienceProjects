#include "CS_smart_home.h"


//constructor to intitialize private data members
CS_smart_home::CS_smart_home(){
	head = NULL;
}



//destructor to deallocate all dynamic memory
CS_smart_home::~CS_smart_home(){

	node * current = head;

	while(current){
		current = head->next;
		delete head;
		head = current;
	}
}


//adds room to linear linked list of rooms
int CS_smart_home::addRoom(char roomName[]){

	node *temp = new node;
	temp->name = new char[strlen(roomName)+1];
	strcpy(temp->name,roomName);
	temp->next = NULL;	

	if(!head){
		head = new node; 
		head = temp;
	}else{
		if(strcmp(temp->name,head->name) < 0){
			temp->next = head;
			head = temp;

	
		}else{

			node *previous = head;
			node *current = head->next;
			
			while(current && strcmp(temp->name,current->name) >0){
				previous = current;
				current = current->next;

	
			}
			
			node *newTemp = current;
			previous->next = temp;
			temp->next = newTemp;
		}
	}

	return 0;	
}

//displays all rooms in linear linked list
void CS_smart_home::displayRooms(){

	node *current = head;
	int count = 1;

	cout<<"\nRooms"<<endl;
	cout<<"_______________"<<endl;

	while(current){
		cout<<count<<". "<<current->name<<endl;	
		current = current->next;
		count = count + 1;
	}
}


//removes room from linear linked list
int CS_smart_home::removeRoom(char roomName[]){
	
	node *current = head;

	if(!head){
		return 1;
	}

	if(strcmp(head->name,roomName) == 0){
		node *temp = head->next;
		delete head;
		head = temp;

		return 0;
	}else{
		while(current->next->next != NULL){
			current = current->next;
		}

		if(strcmp(current->next->name,roomName) == 0){
			current->next = NULL;
			delete current->next;

			return 0;
		}

		current = head;

		while(current->next != NULL){
			if( strcmp(current->next->name,roomName) == 0){
				node *temp = current->next;	
				current->next = current->next->next;

				delete temp;

				return 0;
				
			}

			current = current->next;
		}

	}
		
	return 2;
}


//adds accessory to linear linked list of accessories within a room
int CS_smart_home::addAccessory(char roomName[],char accessoryName[],char category[],char status[]){

	node *current = head;
	
	while(current){
		if(strcmp(current->name,roomName) == 0){
			

			list *temp = new list;

			temp->name = new char[strlen(accessoryName)+1];
			strcpy(temp->name,accessoryName);
			
			temp->category = new char[strlen(category)+1];
			strcpy(temp->category,category);

			temp->status = new char[strlen(status)+1];
			strcpy(temp->status,status);

			temp->next = NULL;

			list *currentList;

			if(current->listhead == NULL){
				current->listhead = new list;
				current->listhead = temp;
			}else if(strcmp(temp->category,current->listhead->category) < 0){
				temp->next = current->listhead;
				current->listhead = temp;
			}else{	
				
				currentList = current->listhead->next;
				list *previous = current->listhead;

				while(currentList && strcmp(temp->category,currentList->category) >0){
					previous = currentList;
					currentList = currentList->next;
				}


				list *newTemp = currentList;
				previous->next = temp;
				temp->next = newTemp;

			}

			return 0;
		}
		
		current = current->next;

	}

	return 1;
}

//removes accessory from linear linked list of accessories within a room
int CS_smart_home::removeAccessory(char roomName[],char accessoryName[]){

	node *current = head;

	while(current){
		if(strcmp(current->name,roomName) == 0){
		
			list *currentList;

			if(strcmp(current->listhead->name,accessoryName) == 0){
				currentList = current->listhead;
				list *temp = current->listhead->next;
				delete current->listhead;
				current->listhead = temp;

				return 0;
				
			}else{
				currentList = current->listhead->next;
				list *previous = current->listhead;

				while(currentList){
					if(strcmp(currentList->name,accessoryName) == 0){
						previous->next = currentList->next;
						delete currentList;
					
						return 0;	
					}

					previous = currentList;
					currentList = currentList->next;	
				}
			}

		}
	
		current = current->next;
	}

	return 1;
}


//displays the accessories within a room
int CS_smart_home::displayRoomAccessories(char roomName[]){

	node *current = head;

	while(current){
		if(strcmp(current->name,roomName) == 0){

			list *currentList = current->listhead;
			
			cout<<"\nAccessories In "<<current->name<<"\n"<<endl;
			while(currentList){
				cout<<"Accessory:"<<currentList->name<<"    Category:"<<currentList->category<<"     Status:"<<currentList->status<<endl;
				currentList = currentList->next;
			}

			return 0;

		}

		current = current->next;
	}

	return 1;
}

//displays all accessories across all rooms
int CS_smart_home::displayAll(){
	
	node *current = head;

	cout<<"\nAll Accessories\n"<<endl;

	while(current){
		list *currentList = current->listhead;

		while(currentList){
			cout<<"Room: "<<current->name<<"|"<<"Accessory: "<<currentList->name<<endl;
			currentList = currentList->next;
		}

		current = current->next;
	}
}

