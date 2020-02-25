#include "queue.h"


queue::queue(){
	
	front = NULL;
	rear = NULL;
}

queue::~queue(){

	node *current = front;

	if(front == NULL){
		cout<<"Nothing In Queue"<<endl;
	}else{	
		while(current != rear){
			node *temp = current->next;
			delete current;

			current = temp;
		}

		delete current;

	}

	front = NULL;
	rear = NULL;
}

node::~node(){

	if(travelInfo.streetName){
		delete [] travelInfo.streetName;
	}

	if(travelInfo.city){
		delete [] travelInfo.city;
	}

	if(travelInfo.traffic){
		delete [] travelInfo.traffic;
	}

	if(travelInfo.notes){
		delete [] travelInfo.notes;
	}

}

void queue::enqueue(char streetName[],int length,char traffic[], char notes[], char city[]){

    node *temp = new node;
 
    temp->travelInfo.streetName = new char[strlen(streetName) + 1];
    strcpy(temp->travelInfo.streetName,streetName);

    temp->travelInfo.length = length;
 

    temp->travelInfo.traffic = new char[strlen(traffic) + 1];
    strcpy(temp->travelInfo.traffic,traffic);

    temp->travelInfo.notes = new char[strlen(notes) + 1];
    strcpy(temp->travelInfo.notes,notes);

    temp->travelInfo.city = new char[strlen(city) + 1];
    strcpy(temp->travelInfo.city,city);
	
    if (front == NULL){
        front = temp;
    }else{
        rear->next = temp;
    }
  
    rear = temp; 
    rear->next = front; 

}

int queue::dequeue(){
	
	if(front == NULL){
		return 1;
	}else if(front == rear){
		delete front;
		delete rear;
		front = NULL;
	}else{
		node *temp = front;
		front = front->next;
		rear->next = front;
		delete temp;
	}

	return 0;
}	

void queue::peek(){

		
	if(front == NULL){
		cout<<"\nFirst In The Queue Is Nothing!"<<endl;
	}else{	
		cout<<"\n(PEEK) On The Way There Start By Taking\n"<<front->travelInfo.streetName<<"-->"<<front->travelInfo.city<<"-->"<<front->travelInfo.length<<"-->"<<front->travelInfo.traffic<<"-->"<<front->travelInfo.notes<<endl;
	}


}


void queue::display(){
	 
	node *current = front;

	
	cout<<"\nOn The Way To Your Desired Destination, Take The Following Directions "<<endl;
	cout<<"______________________________________________________________________"<<endl;

	if(front == NULL){
		cout<<"Nothing In Queue"<<endl;
	}else{
		
		while(current->next != front){
			cout<<current->travelInfo.streetName<<"-->"<<current->travelInfo.city<<"-->"<<current->travelInfo.length<<"-->"<<current->travelInfo.traffic<<"-->"<<current->travelInfo.notes<<"\n"<<endl;
			current = current->next;
		}

		cout<<current->travelInfo.streetName<<"-->"<<current->travelInfo.city<<"-->"<<current->travelInfo.length<<"-->"<<current->travelInfo.traffic<<"-->"<<current->travelInfo.notes<<"\n"<<endl;

	}

}
