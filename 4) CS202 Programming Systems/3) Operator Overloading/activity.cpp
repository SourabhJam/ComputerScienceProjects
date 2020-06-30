//Sourabh Jamalapuram
//activity.cpp, implementation of functions declared in activity.h for classes such as activity, zoom, travel, and restaurant
#include "activity.h"

//default constructor to initialize private data members of activity
activity::activity(){
	this->title = NULL;
	this->subject = NULL;
	this->priority = 0;
}

//constructor to initialize private data members of activity
activity::activity(String title, String subject, int priority){
	this->title = title;
	this->subject = subject;
	this->priority = priority;	

}

//destructor to deallocate dynamic memory
activity::~activity(){
	//delete title;
	//delete subject;
}

//assignment operator to copy one activity to another
activity& activity::operator =(const activity &a1){

	if(this == &a1){
                return *this;
        }

        if(this->title != NULL){
                delete &this->title;
		delete &this->subject;
		priority = 0;
        }

	this->title = a1.title;
        this->subject = a1.subject;
        this->priority = a1.priority;
        return *this;

}

//less than operator to compare activity to another activity
bool operator < (const activity &a1, const activity *a2){

	if(a1.title < a2->title){
                return true;
        }else{
                return false;
        } 
}


//less than operator to compare a string to activity title
bool operator < (const String s1, const activity *s2){


	if(s1 < s2->title){
                return true;
        }else{
                return false;
        }	
	

}
               
//less than operator to compare activity title to string 
bool operator < (const activity *s1, const String s2){

	if(s1->title < s2){
                return true;
        }else{
                return false;
        }
}

//less than or equals to operator to compare activity to activity
bool operator <= (const activity &a1,const activity *a2){

	if(a1.title <= a2->title){
                return true;
        }else{
                return false;
        }

}

//less than or equals to operator to compare string to activity title
bool operator <= (const String s1, const activity *s2){

	if(s1 <= s2->title){
                return true;
        }else{
                return false;
        } 

}
                
//less than or equals to operator to compare activity title to string
bool operator <= (const activity *s1, const String s2){

	if(s1->title <= s2){
                return true;
        }else{
                return false;
        } 

}


//greater than operator to compare activity title to another activity title 
bool operator > (const activity &a1, const activity *a2){

	if(a1.title > a2->title){
                return true;
        }else{
                return false;
        }
}

//greater than operator to compare string to activity title
bool operator > (const String s1, const activity *s2){

	if(s1 > s2->title){
                return true;
        }else{
                return false;
        }
}

//greater than operator to compare activity title to string
bool operator > (const activity *s1, const String s2){

	if(s1->title > s2){
                return true;
        }else{
                return false;
        }

}
            

//greater than or equal to operator to compare activity title to another activity title
bool operator >= (const activity &a1,const activity *a2){

	if(a1.title >= a2->title){
                return true;
        }else{
                return false;
        }
}

//greater than or equal to operator to compare string to activity title
bool operator >= (const String s1, const activity *s2){
	
	if(s1 >= s2->title){
                return true;
        }else{
                return false;
        }

}

//greater than or equal to operator to compare activity title to string
bool operator >= (const activity *s1, const String s2){
	
	if(s1->title >= s2){
		return true;
	}else{
		return false;
	}

}

//comparison operator to see if activity title and character pointer match
bool operator == (const activity &a1, char *a2){

	if( a1.title == a2){ 
                return true;
        }else{
                return false;
        }	

}
            
//comparison pointer to see if character pointer and activity title match 
bool operator == (char *a1, const activity &a2){

	if(a1 == a2.title){ 
                return true;
        }else{
                return false;
        }
}
                
//comparison operator to see if titles of two activities match
bool operator ==(const activity &a1, const activity &a2){

	if( a1.title == a2.title){ 
                return true;
        }else{
                return false;
        }

}

              
//not equals to operator to see if activity title is not equal to character pointer 
bool operator != (const activity &a1, char *a2){

	if( a1.title != a2){ 
                return true;
        }else{
                return false;
        }

}
               
//not equals to operator to see if character pointer is not equals to activity title 
bool operator != (char *a1, const activity &a2){

	if( a1 != a2.title){ 
                return true;
        }else{
                return false;
        }

}
               
//not equals to operator to see if activity title is not equals to activity title 
bool operator !=(const activity &a1, const activity &a2){

	if( a1.title != a2.title){
                return true;
        }else{
                return false;
        }

}

//output operator to write activity to external file
ofstream& operator <<(ofstream& out, const activity &a1){
	
	a1.writeOut(out);
	return out;

}

//input operator to read in activity from external data file
ifstream& operator >>(ifstream& infile, const activity &a1){

	a1.readIn(infile);
	return infile;

}




//_____________________________________________________________________________________________________________

//desfault constructor to initialzie private data members for zoom
zoom::zoom(){
	ID = 0;
}

//constructor to initialize private data members for zoom
zoom::zoom(String title,String subject,int priority,int ID):activity(title,subject,priority){

	this->ID = ID;

}

//destructor to deallocate dynamic memory
zoom::~zoom(){


}

//function to write zoom activity to external data file
void zoom::writeOut(ofstream& out) const {

	if(out){
		out<<"Z|"<<this->title<<"|"<<this->subject<<"|"<<this->priority<<"|"<<this->ID<<endl;
	}

}

//function to read in zoom activity from external data file
void zoom::readIn(ifstream& infile) const{
	
	char type;
	String title;
	String subject;
	int priority;
	int ID;

	if(infile){
		infile>>type;
		infile.ignore(100,'|');

		infile>>title;
		infile.ignore(100,'|');

		infile>>subject;
		infile.ignore(100,'|');

		infile>>priority;
		infile.ignore(100,'|');

		infile>>ID;
		infile.ignore(100,'\n');
	}			


}

//function to display zoom activity
void zoom::display(){
	cout<<"\nZoom"<<endl;
	cout<<"_____________________________"<<endl;
	cout<<"Title: "<<title<<endl;
	cout<<"Subject: "<<subject<<endl;
	cout<<"Priority: "<<priority<<endl;
	cout<<"Zoom ID: "<<ID<<endl;

}

//_____________________________________________________________________________________________________________

//default constructor to initialize private data members for travel
travel::travel(){
	startLocation = NULL;
	destination = NULL;
}

//constructor to initialize private data members of travel
travel::travel(String title,String subject, int priority, String startLocation, String destination):activity(title,subject,priority){

	this->startLocation = startLocation;
	this->destination = destination;

}

//destructor to deallocate dynamic memory in travel
travel::~travel(){
	
}

//function to write travel activity to external data file
void travel::writeOut(ofstream &out) const{

	if(out){
		out<<"T|"<<this->title<<"|"<<this->subject<<"|"<<this->priority<<"|"<<this->startLocation<<"|"<<this->destination<<endl;
	}

}

//function to read in travel activity from external data file
void travel::readIn(ifstream& infile) const{
    
        char type;
        String title;
        String subject;
        int priority;
        String startLocation;
	String destination;

        if(infile){
                infile>>type;
                infile.ignore(100,'|');

                infile>>title;
                infile.ignore(100,'|');

                infile>>subject;
                infile.ignore(100,'|');

                infile>>priority;
                infile.ignore(100,'|');

                infile>>startLocation;
                infile.ignore(100,'|');

		infile>>destination;
		infile.ignore(100,'\n');
        }    

}

//function to display travel activity
void travel::display(){
	
	cout<<"\nTravel"<<endl;
        cout<<"_____________________________"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"Priority: "<<priority<<endl;
        cout<<"Staring Location: "<<startLocation<<endl;
	cout<<"Destination: "<<destination<<endl;
}

//_____________________________________________________________________________________________________________

//default constructor to initialize private data members for restaurant
restaurant::restaurant(){
	method = NULL;
}

//constructor to initialize private data members of restaurant
restaurant::restaurant(String title,String subject, int priority, String method):activity(title,subject,priority){

	this->method = method;

}


//destructor to deallocate all dynamic memory in restaurant
restaurant::~restaurant(){

}

//function to write restaurant activity to external data file
void restaurant::writeOut(ofstream &out) const{

	if(out){
		out<<"R|"<<this->title<<"|"<<this->subject<<"|"<<this->priority<<"|"<<this->method<<endl;
	}

}

//function to read in restaurant activity from external data file
void restaurant::readIn(ifstream& infile) const{
    
        char type;
        String title;
        String subject;
        int priority;
        String method;

        if(infile){
                infile>>type;
                infile.ignore(100,'|');

                infile>>title;
                infile.ignore(100,'|');

                infile>>subject;
                infile.ignore(100,'|');

                infile>>priority;
                infile.ignore(100,'|');

                infile>>method;
                infile.ignore(100,'\n');
        }    
}

//function to display restaurant activity
void restaurant::display(){
	cout<<"\nRestaurant"<<endl;
        cout<<"_____________________________"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"Priority: "<<priority<<endl;
        cout<<"Method Of Delivery: "<<method<<endl;        

}
