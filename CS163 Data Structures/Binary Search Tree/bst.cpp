#include "bst.h"

//constructor to initialize all private data members to NULL
table::table(){

	root = NULL;

}

//destructor which calls the destructor function at end of program to deallocate all dynamic memory
table::~table(){
	
	deallocate(root);


}

//function to deallocate all dynamic memory used in the program
int table::deallocate(node * root){
	
	if (root == NULL){
        	return 0;
    	}

    	deallocate(root->left);
    	deallocate(root->right);

	delete [] root->info.mealName;
	delete [] root->info.venueName;
	delete [] root->info.review;
	delete [] root->info.venueType;

	delete root;
	root = NULL;
    	

}



//public function which the client can call to add new meal to binary search tree
int table::addNewMeal(char *mealName,char *venueName,int price, int rating, char *review, char *venueType){
	
	root = addNewMeal(root,mealName,venueName,price,rating,review,venueType);
 
        return 0;
}

//private function which adds meal info to the binary search tree
node * table::addNewMeal(node * root, char *mealName,char *venueName,int price, int rating, char *review, char *venueType){

	
	if(!root){
      		root = new node;
		
		root->info.mealName = new char[strlen(mealName) + 1];
        	strcpy(root->info.mealName,mealName);

		root->info.venueName = new char[strlen(venueName)+1];
		strcpy(root->info.venueName,venueName);

		root->info.price = price;

		root->info.rating = rating;

		root->info.review = new char[strlen(review) + 1];
        	strcpy(root->info.review,review);

        	root->info.venueType = new char[strlen(venueType) + 1];
        	strcpy(root->info.venueType,venueType);

		root->left = NULL;
		root->right = NULL;

    	}else if(strcmp(mealName,root->info.mealName) < 0){
		root->left = addNewMeal(root->left,mealName,venueName,price,rating,review,venueType);
    	}else{
		root->right = addNewMeal(root->right,mealName,venueName,price,rating,review,venueType);

    	} 
      
  
    	return root;
} 

//public function to display all meal information in order
int table::displayAll(){ 
    
	displayAll(root,0);
}

//private function that displays all information in order recursively
int table::displayAll(node *root, int level){
    
	if(!root){
		return 0;
	}   

	displayAll(root->left,level+1);	
	
	cout<<root->info.mealName<<"-->"<<root->info.venueName<<"-->"<<root->info.price<<"-->"<<root->info.rating<<"-->"<<root->info.review<<"-->"<<root->info.venueType<<endl;
	
	displayAll(root->right,level+1);
			
}

//public function which the client program can call to display all information based on matching meals
int table::displayMatches(char *key){

	displayMatches(root,key);
}


//private helper function to find matching meal names and display all information
int table::displayMatches(node *root,char *key){

	if(!root){
                return 0;
        }

	if(strcmp(key,root->info.mealName) == 0){
        	cout<<root->info.mealName<<"-->"<<root->info.venueName<<"-->"<<root->info.price<<"-->"<<root->info.rating<<"-->"<<root->info.review<<"-->"<<root->info.venueType<<endl;
        
	}
	
	displayMatches(root->left,key);
        displayMatches(root->right,key);

}

//public function to search for meal. function returns how many matches it has found and supplies information back through argument list
int table::searchMeal(char *key, mealInfo matches[]){

	int matchNum = searchMeal(root,key,matches,0);

}

//private function to search for how many times a meal appears in the data structure.
int table::searchMeal(node *root,char *key, mealInfo matches[], int currentMatchIndex){
	
        if(root == NULL){
                return 0;
	}else if(strcmp(root->info.mealName,key) == 0){

		matches[currentMatchIndex].mealName = root->info.mealName;
		matches[currentMatchIndex].venueName = root->info.venueName;
		matches[currentMatchIndex].price = root->info.price;
		matches[currentMatchIndex].rating = root->info.rating;
		matches[currentMatchIndex].review = root->info.review;
		matches[currentMatchIndex].venueType = root->info.venueType;

		++currentMatchIndex;	

		return 1+searchMeal(root->right,key,matches,currentMatchIndex);
		
				
	}else if(strcmp(key,root->info.mealName) < 0){
		return searchMeal(root->left,key,matches,currentMatchIndex);
	}

	return searchMeal(root->right,key,matches,currentMatchIndex);
}


//public function to remove a meal from the binary search tree. client program can call this function to remove.
int table::removeMeal(char *mealName, char *venueName){
	root = removeMeal(root,mealName,venueName);
}

//private remove function which cannot be accessed by client program
node * table::removeMeal(node *root, char *mealName, char *venueName){

	if(root == NULL){
		return root; 
		cout<<"root is empty"<<endl;
	}
  
	if(strcmp(mealName,root->info.mealName) < 0){
        	root->left = removeMeal(root->left, mealName, venueName);
	}else if (strcmp(mealName,root->info.mealName) > 0){
        	root->right = removeMeal(root->right, mealName, venueName);
	}else{ 
		
		if(strcmp(venueName,root->info.venueName) == 0){
			
			if (root->left == NULL){ 
				node *temp = root->right; 
				delete [] root->info.mealName;
        			delete [] root->info.venueName;
        			delete [] root->info.review;
        			delete [] root->info.venueType;

				delete root;
				return temp; 
			}else if (root->right == NULL){ 
				node *temp = root->left; 
				delete [] root->info.mealName;
                                delete [] root->info.venueName;
                                delete [] root->info.review;
                                delete [] root->info.venueType;

				delete root;
				return temp; 
			} 
 		
			node* temp = getIOS(root->right); 
 		
			strcpy(root->info.mealName,temp->info.mealName);
			strcpy(root->info.venueName,temp->info.venueName);	
			root->info.price = temp->info.price;
			root->info.rating = temp->info.rating;
			strcpy(root->info.review,temp->info.review);
			strcpy(root->info.venueType,temp->info.venueType);

			root->right = removeMeal(root->right, temp->info.mealName, temp->info.venueName);

		}

		root->right = removeMeal(root->right, mealName, venueName);
	} 
    
	return root; 
} 


//private function that gets the in order successor for when removing from the binary search tree
node * table::getIOS(node* root){

    node* current = root;
  
    while (current && current->left != NULL){
        current = current->left; 
	}
  
    return current; 
} 

//private function to find the height of the tree
int table::height(node * root){
	
	if(root == NULL){
		return 0;
    	}
    
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	if(leftHeight>rightHeight){
		return leftHeight + 1;
    	}else{
		return rightHeight + 1;
	}

}

//public function to find and return the height of the binary search tree
int table::height(){
	
	if(root == NULL){
		return 0;
	}

   	return height(root);

} 

//function to check if tree is efficient. returns true or false based on if the tree is effecient(balanced) or ineffcient(unbalanced)
bool table::isEfficient(){

	if(isEfficient(root) == 0){
		return true;
	}else{
		return false;
	}

}

//private function to check if tree is balanced. checks left height and right height and compares to see if the difference is 0,1,-1 meaning its balanced otherwise it is not
int table::isEfficient(node *root){
	
	if(root == NULL){
                return 1;
        }   

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	if(leftHeight-rightHeight == 1 || leftHeight-rightHeight==0 || leftHeight-rightHeight == -1){
		return 0;
	}
          	
}
