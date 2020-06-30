//Sourabh Jamalapuram
//string.cpp, function implementations for function prototypes declared in string class
#include "string.h"

//destructor to deallocate dynamic memory in string class
String::~String(){	
	if(str != NULL){
		delete [] str;
		str = NULL;
	}
}

//copy constructor to copy information of string
String::String(const String &toCopy){
	this->str = new char[toCopy.len + 1];
	strcpy(this->str,toCopy.str);
	this->len = toCopy.len;
}

//function to check if string is empty
bool String::isEmpty(){
	if(this->len == 0){
		return true;
	}else{
		return false;
	}

}

//assignment operator to assign one string to another
String& String::operator =(const String &s2){
	if(this == &s2){
		return *this;
	}

	if(this->str){
		delete [] this->str;
	}

	this->str = new char[s2.len + 1];
	strcpy(this->str,s2.str);
	this->len = s2.len;
	return *this;

}

//assignment operator to assign a character pointer to a string
String& String::operator =(const char *s2){

        if(this->str){
                delete [] this->str;
        }   

        this->str = new char[strlen(s2) + 1]; 
        strcpy(this->str,s2);
        this->len = strlen(s2);
        return *this;

}

//+= operator to add one string to another
String& String::operator += (const String & s2){

	char * temp = new char[len+s2.len+1];
	strcpy(temp, str);
	strcat(temp, s2.str);
	str = temp;
	return *this;
}

//output operator to print a string
ostream& operator <<(ostream &o, const String &s){
	o<<s.str;
	return o;
}

//input operator to read in a string
istream& operator >>(istream &in, String &s){
	char temp[100];
	in.get(temp,100,'\n');
	s.len = strlen(temp);
	s.str = new char[s.len + 1];
	strcpy(s.str,temp);
	return in;
}

//less than operator to compare string to character pointer
bool operator < (const String &s1, char *s2){
	if(strcmp(s1.str,s2) < 0){
		return true;
	}else{
		return false;
	}

}

//less than operator to compare character pointer to string
bool operator < (char *s1, const String &s2){

	if(strcmp(s1,s2.str) < 0){ 
                return true;
        }else{
                return false;
        } 
}

//less than operator to compare one string to another string
bool operator < (const String &s1, const String &s2){
	
	if(strcmp(s1.str,s2.str) < 0){ 
                return true;
        }else{
                return false;
        } 
}

//less than or equals to operator to compare one string to a character pointer
bool operator <= (const String &s1, char *s2){

	if(strcmp(s1.str,s2) <= 0){
                return true;
        }else{
                return false;
        }

}

//less than or equals to operator to compare chracter pointer to string
bool operator <= (char *s1, const String &s2){

	if(strcmp(s1,s2.str) <= 0){
                return true;
        }else{
                return false;
        }
}
                
//less than or equals to operator to compare string to another string
bool operator <= (const String &s1,const String &s2){

	if(strcmp(s1.str,s2.str) <= 0){
                return true;
        }else{
                return false;
        }
}

//greater than operator to compare a string to a character pointer
bool operator > (const String &s1, char *s2){

	if(strcmp(s1.str,s2) > 0){
                return true;
        }else{
                return false;
        }	
}

//greater than operator to compare character pointer to a string
bool operator > (char *s1, const String &s2){

	if(strcmp(s1,s2.str) > 0){
                return true;
        }else{
                return false;
        }
}
        
//greater than operator to compare a string to another string       
bool operator > (const String &s1, const String &s2){

	if(strcmp(s1.str,s2.str) > 0){
                return true;
        }else{
                return false;
        }
}

//greater than or equals to operator to compare string to character pointer
bool operator >= (const String &s1, char *s2){

	if(strcmp(s1.str,s2) >= 0){
                return true;
        }else{
                return false;
        }
}

//greater than or equals to operator to compare character pointer to string
bool operator >= (char *s1, const String &s2){
	
	if(strcmp(s1,s2.str) >= 0){
                return true;
        }else{
                return false;
        }
}

//greater than or equals to operator to compare string to another string
bool operator >= (const String &s1,const String &s2){

	if(strcmp(s1.str,s2.str) >= 0){
                return true;
        }else{
                return false;
        }
}

//comparison operator to compare one string to another string
bool operator ==(const String &s1, const String &s2){

	if(strcmp(s1.str,s2.str) == 0){
		return true;
	}else{
		return false;
	}
}

//comparison operator to compare one string to a character pointer
bool operator == (const String &s, char *s2){
	if(strcmp(s.str,s2) == 0){
		return true;
	}else{
		return false;
	}
}

//comparison operator to compare a character pointer to a string
bool operator == (char *s1, const String &s2){
	if(strcmp(s2.str,s1) == 0){
		return true;
	}else{
		return false;
	}
}

//not equals to operator to see if a string is not equals to another string
bool operator !=(const String &s1, const String &s2){

        if(strcmp(s1.str,s2.str)!= 0){
                return true;
        }else{
                return false;
        }   
}

//not equals to operator to see if a string is not equals to a character pointer
bool operator != (const String &s1, char *s2){

	if(strcmp(s1.str,s2) != 0){
		return true;
	}else{
		return false;
	}
}

//not equals to operator to see if a charatcer pointer is not equals to a string
bool operator != (char *s1, const String &s2){

        if(strcmp(s1,s2.str) != 0){ 
                return true;
        }else{
                return false;
        }   

}

