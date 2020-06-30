//Sourabh Jamalapuram
//activity.cpp, used to implement the functions defined in activity.h

#include "activity.h"


//default constructor for activity
activity::activity(){
	title = NULL;
	priority = 0;
	length = 0;
	group = false;
}
	
//constructor to initialize private data members of activity
activity::activity(char *title,int priority,int length,bool group){
	this->title = new char[strlen(title) + 1];
	strcpy(this->title,title);

	this->priority = priority;

	this->length = length;

	this->group = group;

}

//copy constructor for activity
activity::activity(const activity &toCopy){
	
	this->title = new char[strlen(toCopy.title) + 1];
	strcpy(this->title,toCopy.title);

	this->priority = toCopy.priority;
	this->length = toCopy.length;
	this->group = group;
}

//destructor to deallocate dynamic memory in activity
activity::~activity(){
	delete []title;
}


//function to check if title the user entered matches with the title of the activity method
int activity::isMatch(char *title){
	if(strcmp(this->title,title) == 0){
		return 0;
	}else{
		return 1;
	}

}


//function to compare which of two titles are greater 
bool activity::isGreater(activity *a){
	
	if(strcmp(this->title,a->title) > 0){
		return false;
	}else{
		return true;
	}

}

//function to return the priority of the node
int activity::getPriority(){
	return this->priority;
}

//__________________________________________________________________________________________________________
//default constructor for movie
movie::movie(){
	rating = NULL;
}

//constructor to intialize the private data members of movie
movie::movie(char *title,int priority,int length,bool group, char *rating):activity(title,priority,length,group){
        this->rating = new char[strlen(rating) + 1]; 
        strcpy(this->rating,rating);

}

//copy constructor for movie
movie::movie(const movie &toCopy):activity(toCopy){
	this->rating = new char[strlen(toCopy.rating) + 1]; 
        strcpy(this->rating,toCopy.rating);
}

//destructor to deallocate all dynamic memory within movie
movie::~movie(){
	delete []rating;
}

//function to check if rating entered by user matches rating of movie
int movie::isRatingMatch(char *rating){
	if(strcmp(this->rating,rating) == 0){
		return 0;
	}else{
		return 1;
	}
}

//function to display a movie
void movie::display(){
	cout<<"\nMOVIE"<<endl;
	cout<<"________________________"<<endl;
	cout<<"Movie Name: "<<title<<endl;
	cout<<"Priority: "<<priority<<endl;
	cout<<"Length: "<<length<<endl;
	cout<<"Rating: "<<rating<<endl;
	
	if(group == true){
		cout<<"Group Activity: Yes"<<endl;
	}else{
		cout<<"Group Activity: No"<<endl;
	}
	
}

//function display movie and its rating
void movie::displayByRating(){
	cout<<"\nMOVIE"<<endl;
	cout<<"________________________"<<endl;
	cout<<"Movie Name: "<<title<<endl;
	cout<<"Rating: "<<rating<<endl;
}

//______________________________________________________________________________________________
//default constructor for hike
hike::hike(){
	length = 0;	
}

//constructor to initialize the private data members within hike
hike::hike(char *title,int priority,int length,bool group, int elevation):activity(title,priority,length,group){
        
	this->elevation = elevation;

}

//copy constructor for hike
hike::hike(const hike &toCopy):activity(toCopy){
	this->length = toCopy.elevation;
}

//destructor to deallocate all dynamic memory in hike
hike::~hike(){
	
}


//function to display a hike
void hike::display(){
	cout<<"\nHIKE"<<endl;
	cout<<"____________________"<<endl;
        cout<<"Hike Name: "<<title<<endl;
        cout<<"Priority: "<<priority<<endl;
	cout<<"Length: "<<length<<endl;
	cout<<"Elevation: "<<elevation<<endl;

	if(group == true){
                cout<<"Group Activity: Yes"<<endl;
        }else{
                cout<<"Group Activity: No"<<endl;
        } 
	
}

//________________________________________________________________________________________________
//default constructor for eat
eat::eat(){
	cuisine = NULL;
}

//constructor to initialize private data members of eat
eat::eat(char *title,int priority,int length,bool group, char *cuisine):activity(title,priority,length,group){
	this->cuisine = new char[strlen(cuisine) + 1];
	strcpy(this->cuisine,cuisine);
}

//copy constructor for eat
eat::eat(const eat &toCopy):activity(toCopy){
	this->cuisine = new char[strlen(toCopy.cuisine) + 1];
	strcpy(this->cuisine,toCopy.cuisine);	
}

//destructor for eat
eat::~eat(){
	delete []cuisine;
}

//function to display a eat
void eat::display(){
	cout<<"\nEAT"<<endl;
	cout<<"_________________________"<<endl;
        cout<<"Restaurant Name: "<<title<<endl;
	cout<<"Priority: "<<priority<<endl;
	cout<<"Length: "<<length<<endl;
	cout<<"Cuisine: "<<cuisine<<endl;

	if(group == true){
                cout<<"Group Activity: Yes"<<endl;
        }else{
                cout<<"Group Activity: No"<<endl;
        } 
}

