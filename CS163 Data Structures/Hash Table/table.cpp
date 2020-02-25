#include "table.h"




table::table(int size){

	hashTable = new node *[size];
	
	for(int i= 0; i<size;++i){
        	hashTable[i] = NULL;
	}

	hashTableSize = size;




}

table::~table(){

	 for(int i=0;i<hashTableSize;++i){
		node *current = hashTable[i];
		
		while(current){
			delete [] current->info.mealName;
			delete [] current->info.venueName;
			delete [] current->info.review;
			delete [] current->info.venueType;

			node *temp = current;

			current = current->next;
			delete temp;
		}

	
	}

	 delete []hashTable;





}


int table::hash(char *key) const{

	int sum = 0;

	for(int i=0;i<strlen(key);i++){
		int val = (int)key[i];
		sum = sum + val;
	}

	int index = sum % 5;

	return index;
}

int table::insert(char *mealName,char *venueName,int price, int rating, char *review, char *venueType){

	int index = hash(mealName);

	node *temp = new node;

	temp->info.mealName = new char[strlen(mealName) + 1];
        strcpy(temp->info.mealName,mealName);

	temp->info.venueName = new char[strlen(venueName)+1];
	strcpy(temp->info.venueName,venueName);

	temp->info.price = price;

	temp->info.rating = rating;

	temp->info.review = new char[strlen(review) + 1];
        strcpy(temp->info.review,review);

        temp->info.venueType = new char[strlen(venueType) + 1];
        strcpy(temp->info.venueType,venueType);
	
	temp->next = NULL;	

	//cout<<"inserting @ index: "<<index<<endl;

	if(hashTable[index] == NULL){
		hashTable[index] = temp;
	}else{
		node *current = hashTable[index];
			
		while(current->next){
			current = current->next;
		}
			
		current->next = temp;
		//cout<<"added!!!"<<endl;
	}

	return 0;

}


bool table::retrieve(char *toFind, char mealName[], char venueName[], int price, int rating, char review[], char venueType[]){
	
	int index = hash(toFind);
	
	node *current = hashTable[index];

	while(current){
		
		if(strcmp(toFind,current->info.mealName) == 0){
			strcpy(mealName,current->info.mealName);
			strcpy(venueName,current->info.venueName);
			price = current->info.price;
			rating = current->info.rating;
			strcpy(review,current->info.review);
			strcpy(venueType,current->info.venueType);	
			
			
			
			return true;
		}

		current = current->next;

	}

	return false;
}



int table::display(char *key){

	int index = hash(key);

	node *current = hashTable[index];
	
	if(hashTable[index] == NULL){
		return 0;
	}

	while(current){

		if(strcmp(current->info.mealName,key) == 0){
		
			cout<<"Node is: "<<current->info.mealName<<"--->"<<current->info.venueName<<"--->"<<current->info.price<<"--->"<<current->info.rating<<"--->"<<current->info.review<<"--->"<<current->info.venueType<<endl;

		}
		
		current = current->next;
	}


}

int table::removeByMeal(char *mealName){


	int index = hash(mealName);
	

	node *current = hashTable[index];
	node *previous = NULL;

	while(current != NULL && strcmp(current->info.mealName,mealName) == 0){
		hashTable[index] = current->next;
		delete current;
		current = hashTable[index];
	}

	while(current != NULL){
		
		while(current != NULL && strcmp(current->info.mealName,mealName) == 0){
			previous->next = current->next;
			delete current;
			current = previous;
		}

		if(current == NULL){
			return 0;
		}

		previous = current;
		current = current->next;

	}
	



}

int table::removeByVenue(char *venueName){

	for(int i=0;i<hashTableSize;++i){

        	node *current = hashTable[i];
        	node *previous = NULL;

        	while(current != NULL && strcmp(current->info.venueName,venueName) == 0){
                	hashTable[i] = current->next;
                	delete current;
                	current = hashTable[i];
        	}

        	while(current != NULL){

                	while(current != NULL && strcmp(current->info.venueName,venueName) == 0){
                        	previous->next = current->next;
                        	delete current;
                        	current = previous;
                	}

                	if(current == NULL){
                        	return 0;
                	}

                	previous = current;
                	current = current->next;

        	}

	}
}
		
