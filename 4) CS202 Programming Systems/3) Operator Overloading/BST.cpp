//Sourabh Jamalapuram
//BST.cpp, function implementations of function prototypes declared in bst class and node class
#include "BST.h"

//default constructor
node::node(){
	data = NULL;
	left = NULL;
	right = NULL;
}

//constructor to intialize private data members of node
node::node(activity *data){
	this->data = data;

	left = NULL;
	right = NULL;

}

//assignment operator for node
node& node::operator =(const node &n1){

	 if(this == &n1){
                return *this;
        }   

        if(this->data != NULL){
                delete data;
        }   

        this->data = n1.data;
	this->left = n1.left;
	this->right = n1.right;
        return *this;

}

//copy constructor for node
node::node(const node &toCopy){
	this->data = toCopy.data;
	this->left = toCopy.left;
	this->right = toCopy.right;
}

//function to deallocate dynamic memory in node
node::~node(){
	delete data;
	data = NULL;
}


//function to insert activity 
int node::insert(activity &toAdd){
		
	if(toAdd < this->data){
		if(this->left == NULL){
			this->left = new node(&toAdd);
			return 0;	
		}

		this->left->insert(toAdd);
	}else{
		if(this->right == NULL){
			this->right = new node(&toAdd);	
			return 0;
		}
		
		this->right->insert(toAdd);
	}

}

//function to remove activity
node* node::remove(String name, node *parent, node *& root, int direction){

	if(this == NULL){
		return 0;
	}

  
	if(name < this->data){
        	node *toRemove = this->left->remove(name,this,root,0);
		
		if(toRemove != NULL){
		

			if(toRemove->left == NULL && toRemove->right == NULL){
                        	this->left = NULL;
                
			}else if(toRemove->left != NULL && toRemove->right == NULL){
				this->left = toRemove->left;
			}else if(toRemove->left == NULL && toRemove->right != NULL){
				this->right = toRemove->right;
			}

			delete toRemove;
			toRemove = NULL;

		}	
	}

	else if (name > this->data){
        	node *toRemove = this->right->remove(name, this,root,1);

		if(toRemove != NULL){
			if(toRemove->left == NULL && toRemove->right == NULL){
				this->right = NULL;
			}else if(toRemove->left != NULL && toRemove->right == NULL){
                                this->left = toRemove->left;
                        }else if(toRemove->left == NULL && toRemove->right != NULL){
                                this->right = toRemove->right;
                        }

			delete toRemove;
			toRemove = NULL;
		}
		
	}

	else{ 			

			if(this == root){
				if(root->left == NULL && root->right == NULL){
					delete root;
					root = NULL;
					return root;
				}

				if(root->right->left == NULL){
					node *temp = root;
					root = root->right;
					root->left = temp->left;
					delete temp;
					return root;
				}

				node *ios = findIOS(this->right,this->right);
                        	ios->right = root->right;
                        	ios->left = root->left;

                        	node *temp = root;
				root = ios;	
				delete temp;
				return root;
			}
				

			if(this->left == NULL && this->right == NULL){

				return this;
			}

			if (this->left == NULL){ 
				return this;
			}

			else if (this->right == NULL){ 
				parent->left = this->left;
				return this;
				
			} 
			
			
			if(this->right->left == NULL){
				if(direction == 0){
					parent->left = this->left;
					this->right->left = this->left;
						
				}else{
					parent->right = this->right;
					this->right->left = this->left;	

				}

				return this;
			}			
			
			node *ios = findIOS(this->right,this->right);
			ios->right = this->right;
			ios->left = this->left;

			if(direction == 0){
				parent->left = ios;
			}else{
				parent->right = ios;
			}

			return this;	

	} 
   
} 

//function to find in order successor for node with a left node and right node
node* node::findIOS(node *& current, node *&parent){

	if(current == NULL){
		return NULL;
	}


	if(current->left){
		return findIOS(current->left,current);
	}

	//moving everything below ios
	node *temp = current;
	parent->left = current->right;
	temp->right = NULL;
	temp->left = NULL;
	
	//return ios
	return temp;


}

//function to display nodes in data structure
int node::display(){

	if(this == NULL){
		return 0;
	}
	
	this->left->display();
	
	this->data->display();

	this->right->display();
}

//function to update information in external data file
int node::updateFile(ofstream &out){
	if(this == NULL){
		return 0;
	}

	this->left->updateFile(out);
	        
	out<<*this->data;

	this->right->updateFile(out);


}

//function to retrieve information from node
bool node::retrieval(String name,activity **a){
	
	if(this == NULL){
		return false;
	}

	if(name < this->data){
		return this->left->retrieval(name,a);
	}

	if(name > this->data){
		return this->right->retrieval(name,a);
	}

	*a = this->data;
	return true;

}

//function to remove all nodes
int node::removeAll(){
	
	if(this->left != NULL){	
		this->left->removeAll();
		delete this->left;
		this->left = NULL;
		
	}

	if(this->right != NULL){
		this->right->removeAll();
		delete this->right;
		this->right = NULL;
	}

}

//___________________________________________________________________________________________________________________

//constructor to initialize private data members of BST
BST::BST(){
	root = NULL;
}

//copy constructor
BST::BST(const BST &toCopy){
	this->root = toCopy.root;
}

//destructor to deallocate all dynamic memory in BST
BST::~BST(){
	if(root != NULL){
		root->removeAll();
	}
}

//assignment operator for BST
BST& BST::operator =(const BST &b1){ 

	if(this == &b1){
                return *this;
        }   

        if(this->root != NULL){
                delete root;
        }   

        this->root = b1.root;
        return *this;	
}

//insert function to add activity to BST
int BST::insert(activity *toAdd){

	if(root == NULL){
		root = new node(toAdd);
		return 0;
	}else{
		root->insert(*toAdd);
	}

}

//function to display activities in BST
int BST::display(){
	
	if(root == NULL){
		return 0;
	}

	root->display();
}

//function to remove activity from BST
int BST::remove(String title){

	if(root == NULL){
		return 0;
	}

	root->remove(title,NULL,root,0);

}

//function to retrieve activity from BST
bool BST::retrieval(String title,activity **a){

	if(root == NULL){
		return 0;
	}

	bool found = root->retrieval(title,a);
	return found;
}

//function to remove all activities from BST
int BST::removeAll(){

	if(root == NULL){
		return 0;
	}

	root->removeAll();

	delete root;
	root = NULL;

}

//function to update information in BST to external data file
int BST::updateFile(){
	
	ofstream out;
	out.open("activities.txt");

	if(root == NULL){
		out.close();
		return 0;
	}
/*
	ofstream out;

	out.open("activities.txt");
*/

	root->updateFile(out);

	out.close();
}

//function to load data from external data file
int BST::loadData(){

	ifstream infile;
	infile.open("activities.txt");

	char type;

	char title[100];
	String stringTitle;

	char subject[100];
	String stringSubject;

	int priority;
	
	int ID;

	char startLocation[100];
	String stringStartLocation;
	char destination[100];
	String stringDestination;

	char method[100];
	String stringMethod;

	if(infile){
		while(!infile.eof()){

			infile>>type;
			infile.ignore(100,'|');

			infile.get(title,100,'|');
			infile.ignore(100,'|');
			stringTitle = title;

			infile.get(subject,100,'|');
			infile.ignore(100,'|');
			stringSubject = subject;

			infile>>priority;
			infile.ignore(100,'|');
		
			if(!stringTitle.isEmpty()){
				if(type == 'Z'){
					infile>>ID;
					infile.ignore(100,'\n');	

					zoom *z = new zoom(stringTitle,stringSubject,priority,ID);
					insert(z);
				}

				if(type == 'R'){

					infile.get(method,100,'\n');
					infile.ignore(100,'\n');
					stringMethod = method;

					restaurant *r = new restaurant(stringTitle,stringSubject,priority,stringMethod);
					insert(r);
				}


				if(type == 'T'){
					infile.get(startLocation,100,'|');
					infile.ignore(100,'|');
					stringStartLocation = startLocation;

				
					infile.get(destination,100,'\n');
					infile.ignore(100,'\n');	
					stringDestination = destination;

					travel *t = new travel(stringTitle,stringSubject,priority,stringStartLocation,stringDestination);	
					insert(t);

				}		

			}
				
		}

		infile.close();

	}

}

