#include "question.h"

question::question(){

    num = 0;
    subject = NULL;
    text = NULL;
    date = NULL;

}

question::~question(){
    delete subject;
    delete text;
    delete date;
    





}

void question::getQuestion(){

        char userSubject[50];
        char userText[100];
        char userDate[20];
    
        cout<<"\nEnter Question Number "<<endl;
        cout<<"_______________________"<<endl;

        cout<<"Enter Question Subject: "<<endl;
        cin.get(userSubject,SIZE,'\n');
        subject = new char[strlen(userSubject)+1];
        strcpy(subject,userSubject);
        cin.ignore(100,'\n');

        cout<<"Enter Question: "<<endl;
        cin.get(userText,SIZE,'\n');
        text = new char[strlen(userText)+1];
        strcpy(text,userText);
        cin.ignore(100,'\n');

        cout<<"Enter Date: "<<endl;
        cin.get(userDate,SIZE,'\n');
        date = new char[strlen(userDate)+1];
        strcpy(date,userDate);
        cin.ignore(100,'\n');


}

void question::display(){

    cout<<text<<endl;



}

bool question::compare(char* userInput){


    if(strcmp(userInput,subject)==0){
        return true;
    }else{
        return false;
    }
}

void question::setParameters(int newNum, char *newSubject, char *newText, char *newDate){

    num = newNum;

    subject = new char[strlen(newSubject)+1];
    strcpy(subject,newSubject);

    text = new char[strlen(newText)+1];
    strcpy(text,newText);

    date = new char[strlen(newDate)+1];
    strcpy(date,newDate);



}

void question::writeOut(int lastNum){
    ofstream out;

    out.open("questions.txt", ios :: app);

    if(out){
        out<<lastNum<<"|"<<subject<<"|"<<text<<"|"<<date<<endl;

    }

    out.close();
}





