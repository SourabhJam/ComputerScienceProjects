#include "library.h"

//default constructor for node
node::node(){
	table = new activity*[5];

	for(int i=0;i<5;++i){
		table[i] = NULL;
	}

	next = NULL;
	previous = NULL;
}

//constructor to initialize all private data members within node
node::node(activity *data){

	table = new activity*[5];

	table[0] = data;
	
	for(int i=1;i<5;++i){
		table[i] = NULL;
	}

	next = NULL;
	previous = NULL;

	topIndex = 1;

	priority = data->getPriority();
}

node::node(const node &toCopy){
	this->table = toCopy.table;
	this->next = toCopy.next;
	this->previous = toCopy.previous;
	this->priority = toCopy.priority;
	this->topIndex = topIndex;

}


//destructor to deallocate all dynamic memory within a node
node::~node(){
	
}


//function to return the next node
node* node::getNext(){
	return this->next;
}


//function to add node based on priority
node* node::addNode(activity *toAdd, node *prev){

	int priority = toAdd->getPriority();
	

	if(priority == this->priority){
		addActivity(toAdd,0);
	}

        if(priority > this->priority){
		if(this->next == NULL){
			prev = this;
			node *temp = new node(toAdd);
			prev->next = temp;
			temp->previous = prev;	
			temp->next = NULL;
		}else{
			this->next->addNode(toAdd,this);
		}
	}


	if(priority < this->priority){
		
		if(this->previous == NULL){
			node *temp = new node(toAdd);
			temp->next = this;
			this->previous = temp;	
			return temp;
		}
		
		node * temp = new node(toAdd);
		prev->next = temp;
		temp->previous = prev;
		temp->next = this;
		this->previous = temp;
	}

	return this;

}

//test function to display the nodes in the DLL
/*
int node::displayNodes(){

	if(this == NULL){
		return 0;
	}

	cout<<"node is: "<<this->priority<<endl;
	cout<<"_______________"<<endl;
	this->display(0);
	this->next->displayNodes();
	
}
*/

//function to display activities based on specific priorties
int node::displayByPriority(int userPriority){
	if(this == NULL){
		return 0;
	}

	if(this->priority == userPriority){		
		this->display(0);
		return 0;
	}

	this->next->displayByPriority(userPriority);	


}

//function to add an activity 
int node::addActivity(activity *toAdd, int index){


	if(table[index] == NULL){
		table[index] = toAdd;
		topIndex = topIndex + 1;

		if(topIndex % 5 == 0){ 
                        activity **newTable = new activity *[topIndex + 5]; 
                        for(int i=0;i<topIndex;++i){
                                newTable[i] = table[i];
                        }   

                        delete []table;
                        table = newTable;
                }  
		return 0;
	}	
		
	bool isGreater = this->table[index]->isGreater(toAdd);

	if(isGreater == false){
		for(int i=topIndex;i>=index + 1;--i){
			table[i] = table[i - 1];
		}

                	table[index] = toAdd;
                	topIndex = topIndex + 1;

                if(topIndex % 5 == 0){
                        activity **newTable = new activity *[topIndex + 5];
                        for(int i=0;i<topIndex;++i){
                                newTable[i] = table[i];
                        }

                        delete []table;
                        table = newTable;
                }
	

		return 0;
	}

	addActivity(toAdd, index += 1);



}

//function to remove an activity 
int node::removeActivity(char *title){

	if(this == NULL){
		return 0;
	}	

	for(int i=0;i<topIndex;++i){
		int match = this->table[i]->isMatch(title);
		
		if(match == 0){
			delete this->table[i];	

			for(int j = i; j<topIndex-1; ++ j){
				table[j] = table[j+1];	
			}
			
			table[topIndex-1] = NULL;
			topIndex = topIndex - 1;
			
			return 0;
		}
	}

	this->next->removeActivity(title);	
}

	
//function to remove all activites
void node::removeAll(int index){
	
	if(this->table[index] == NULL){
		delete []table;
	}else{
		delete this->table[index];
		return removeAll(index += 1);
	}

	if(this->next == NULL){
		return;
	}

	this->next->removeAll(0);
	delete this->next;
	this->next = NULL;

}	


//function to display activites in one node
void node::display(int index){
			
	if(table[index] == NULL){
		return;
	}

	table[index]->display();	

	if(index == topIndex - 1){
		return;
	}

	return display(index += 1);
}

//function to display activities across all nodes
void node::displayAll(){

	if(this == NULL){
		return;
	}

	this->display(0);
	this->next->displayAll();

}

//function to display movies by rating, uses RTTI
void node::displayMoviesByRating(char *rating, int index){
	
	if(this == NULL){
		return;
	}
	
	if(this->table[index] != NULL){
		movie *pm = dynamic_cast<movie*> (this->table[index]);
	
		if(pm != NULL){
			int match = pm->isRatingMatch(rating);
			if(match == 0){
				pm->displayByRating();
			}
		}
		
		displayMoviesByRating(rating, index += 1);
	}else{
		 this->next->displayMoviesByRating(rating,0);

	}
}

//function to check if activity exists and retrieve it
bool node::retrieve(char *title,activity **a, int index){

	if(this == NULL){
		return false;
	}

	if(this->table[index] != NULL){
		int match = this->table[index]->isMatch(title);

		if(match == 0){
			*a = this->table[index];
			return true;
		}else{
			retrieve(title,a,index += 1);
		}

	}else{
		this->next->retrieve(title,a,0);
	}
}

//_________________________________________________________________________________________

//constructor to initialize all private data members within the library
library::library(){
	head = NULL;	
}

//copy constructor for library
library::library(const library &toCopy){
	this->head = toCopy.head;

}

//destructor for library
library::~library(){
	if(head == NULL){
		return;
	}

	head->removeAll(0);
	delete head;
}

//function to add activity to DLL
void library::addActivity(activity *toAdd){
		
	if(head == NULL){
		head = new node(toAdd);
	}else{

		head = head->addNode(toAdd, NULL);
	}
}

//test function to display nodes in DLL
/*
void library::displayNodes(){
	if(head == NULL){
		return;
	}

	head->displayNodes();
}
*/

//function to display all activities in DLL
void library::display(){
	 if(head == NULL){
                return;
        }   

        head->displayAll();
}

//function to display activities based on priority
void library::displayByPriority(int userPriority){

	if(head == NULL){
		return;
	}

	head->displayByPriority(userPriority);


}

//function to remove activity from DLL
void library::remove(char *title){
	if(head == NULL){
		return;
	}

	head->removeActivity(title);
}

//function to remove all activities in DLL
void library::removeAll(){
	if(head == NULL){
		return;
	}

	head->removeAll(0);
	delete head;

}

//function to retrieve activity from DLL
bool library::retrieve(char *name,activity **a){

	if(head == NULL){
		return false;
	}

	bool found = head->retrieve(name,a,0);

	return found;
}	

//function to display movies by rating entered by user
void library::displayMoviesByRating(char *rating){

	if(head == NULL){
		return;
	}

	head->displayMoviesByRating(rating,0);
}

//function to display activities that are of top priority
void library::displayTopPriority(){
	if(head == NULL){
		return;
	}

	head->display(0);
}

