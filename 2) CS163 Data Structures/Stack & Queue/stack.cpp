#include "stack.h"


stack::stack(){

	head = NULL;
	topIndex = 0;


}

stack::~stack(){

	Node *current = head;
	int tempTop = topIndex;

	while(current){
		for(int i=tempTop;i>=0;--i){
			delete [] current->travelInfo[i].roadName;
			delete [] current->travelInfo[i].traffic;
			delete [] current->travelInfo[i].notes;
			delete [] current->travelInfo[i].city;
			delete [] current->travelInfo;
		}

		Node *temp = current;
		current = current->next;

		delete temp;

		tempTop = MAX - 1;
	}

	head = NULL;



}

int stack::push(char roadName[],int length,char traffic[],char notes[],char city[]){

            if(!head){
                head = new Node;
                info *travelInfo = new info[MAX];
                head->travelInfo = travelInfo;

        	head->travelInfo[topIndex].roadName = new char[strlen(roadName) + 1];
        	strcpy(head->travelInfo[topIndex].roadName,roadName);
		
		head->travelInfo[topIndex].length = length;

		head->travelInfo[topIndex].traffic = new char[strlen(traffic) + 1];
        	strcpy(head->travelInfo[topIndex].traffic,traffic);

		head->travelInfo[topIndex].notes = new char[strlen(notes) + 1];
        	strcpy(head->travelInfo[topIndex].notes,notes);

		head->travelInfo[topIndex].city = new char[strlen(city) + 1];
		strcpy(head->travelInfo[topIndex].city,city);
		
		
               return -1;
            
	    }
           

	    if(topIndex == MAX-1){
           

               	topIndex = 0;
                Node *temp = new Node;
               	info *travelInfo = new info[MAX];
                temp->travelInfo = travelInfo;
                
		temp->travelInfo[topIndex].roadName = new char[strlen(roadName)+1];
		strcpy(temp->travelInfo[topIndex].roadName,roadName);

		temp->travelInfo[topIndex].length = length;

		temp->travelInfo[topIndex].traffic = new char[strlen(traffic) + 1];
        	strcpy(temp->travelInfo[topIndex].traffic,traffic);

		temp->travelInfo[topIndex].notes = new char[strlen(notes) + 1];
        	strcpy(temp->travelInfo[topIndex].notes,notes);

		temp->travelInfo[topIndex].city = new char[strlen(city) + 1];
		strcpy(temp->travelInfo[topIndex].city,city);
		
		


                temp->next = head;
                head = temp;

                
            }else{
               

		++topIndex;

        	head->travelInfo[topIndex].roadName = new char[strlen(roadName) + 1];
        	strcpy(head->travelInfo[topIndex].roadName,roadName);
		
		head->travelInfo[topIndex].length = length;

		head->travelInfo[topIndex].traffic = new char[strlen(traffic) + 1];
        	strcpy(head->travelInfo[topIndex].traffic,traffic);

		head->travelInfo[topIndex].notes = new char[strlen(notes) + 1];
        	strcpy(head->travelInfo[topIndex].notes,notes);

		head->travelInfo[topIndex].city = new char[strlen(city) + 1];
		strcpy(head->travelInfo[topIndex].city,city);
		

             

                return 1;
            }

 

}

int stack::pop(){
         cout<<"starting top: "<<topIndex<<endl; 
	if(!head){
		cout<<"head is null"<<endl;
                return 0;
	}
	
	if(topIndex == 0){

                cout<<"in if top index= "<<topIndex<<endl;
                Node *temp = head->next;

                delete [] head->travelInfo;
                delete head;

                head = temp;

                topIndex = MAX - 1;

                return 1;
	
	}else{

                cout<<"in else top index= "<<topIndex<<endl;
                delete head->travelInfo[topIndex].roadName;
		delete head->travelInfo[topIndex].city;
		delete head->travelInfo[topIndex].traffic;
		delete head->travelInfo[topIndex].notes;
		--topIndex;


                return 1;

            }
}

int stack::peek(){
	if(!head){
		return -1;
		cout<<"Nothing In List"<<endl;
	}

	cout<<"\n(PEEK) On The Way Back Start By Taking\n"<<head->travelInfo[topIndex].roadName<<"-->"<<head->travelInfo[topIndex].city<<"-->"<<head->travelInfo[topIndex].length<<"-->"<<head->travelInfo[topIndex].traffic<<"-->"<<head->travelInfo[topIndex].notes<<endl;
	return 0;

}




void stack::display(){
	
	Node *current = head;
	int tempTop = topIndex;

	cout<<"On The Way Back From Your Desired Destination, Take The Following Directions "<<endl;
	cout<<"____________________________________________________________________________"<<endl;

	while(current){
		for(int i=tempTop;i>=0;--i){
			cout<<current->travelInfo[i].roadName<<"--->"<<current->travelInfo[i].city<<"-->"<<current->travelInfo[i].length<<"--->"<<current->travelInfo[i].traffic<<"--->"<<current->travelInfo[i].notes<<endl;
		}

		current = current->next;
		tempTop = MAX - 1;
	}

}
