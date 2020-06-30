//Sourabh Jamalapuram,November 12 2019,CS612,Program #3
//This program was designed to make it easier for students to organize and study practice questions for a test or class. This program gives students the option to enter new classes, display all questions, and display questions of a certain subject. The convinient part about this program is that it uses external files to store information so students can access questions whenever they want. A student could enter a couple questions and come back a few days later and the questions would still be there.
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

const int SIZE = 50; 


struct question{ //structure of questions containing question number, question subject, the actual question, and the date entered
    int num;
    char subject[SIZE];
    char question[SIZE];
    char date[SIZE];

};

void displayWelcomeMessage(); // Displays Welcome Message
void getQuestion(question myQuestion[]); //Gets The Question By Prompting The User To Enter subject,question, and date
void writeOut(question myQuestion[]); //Writes questions to external file
int readIn(question myquestion[]); //reads in all lines in external file 
void displayAll(question myquestion[],int numOfQuestions); //Displays all questions in external file
void displayBySubject(question myquestion[], int numOfQuestions); //Displays questions based on users choice of subject
int getUserOption(); //Gets what the user want to do either write,display all, display by subject
bool again(); //asks user if they wanna continue running program
int getLastNum(); //gets the last number in file

int main(){
    question writeQuestion[10]; //array of questions to writeout
    question readQuestion[SIZE]; //array of questions to readin
    int numOfQuestions = 0; //number of questions
    int userOption = 0; //user option
    bool proceed = false; //repeat program true or false

    displayWelcomeMessage();

    
    do{  
        userOption = getUserOption();
     
        if(userOption == 1){
            getQuestion(writeQuestion);
            writeOut(writeQuestion);
        }else if(userOption == 2){
            numOfQuestions = readIn(readQuestion);
            displayAll(readQuestion, numOfQuestions);
        }else if(userOption == 3){
            numOfQuestions = readIn(readQuestion);
            displayBySubject(readQuestion, numOfQuestions);
        }

        proceed = again();

    }while(proceed == true);



    




    return 0;
}





void displayWelcomeMessage(){
    cout<<"\nWelcome To The Computer Science Test Guide. This Program Was Designed For People To Enter Practice Questions That They Would Like To Study And Re Visit The Questions At Any Given Time"<<endl;
}

void getQuestion(question myQuestion[]){

    int lastNum = getLastNum();

    for(int i=0;i<10;i++){
        cout<<"\nEnter Question Number "<<(lastNum+i)<<endl;
        cout<<"_______________________"<<endl;
        myQuestion[i].num = lastNum + i;
        

        cout<<"Enter Question Subject"<<endl;
        cin.get(myQuestion[i].subject,SIZE,'\n');
        cin.ignore(100,'\n');

        cout<<"Enter The Question: "<<endl;
        cin.get(myQuestion[i].question,SIZE,'\n');
        cin.ignore(100,'\n');

        cout<<"Enter Date: "<<endl;
        cin.get(myQuestion[i].date,SIZE,'\n');
        cin.ignore(100,'\n');
    }


}


void writeOut(question myQuestion[]){
    ofstream out;

    out.open("questions.txt", ios :: app);


    if(out){
        for(int i=0;i<10;i++){
            out<<myQuestion[i].num<<"|"<<myQuestion[i].subject<<"|"<<myQuestion[i].question<<"|"<<myQuestion[i].date<<endl;
        }

    }

    out.close();
}

int readIn(question myquestion[]){
    ifstream infile;
    infile.open("questions.txt");

    int i = 0;

    if(infile){
        while(!infile.eof()){
            infile>>myquestion[i].num;
            infile.ignore(100,'|');

            infile.get(myquestion[i].subject,SIZE,'|');
            infile.ignore(100,'|');

            infile.get(myquestion[i].question,SIZE,'|');
            infile.ignore(100,'|');

            infile.get(myquestion[i].date,SIZE,'\n');
            infile.ignore(100,'\n');

            i = i+ 1;


        }
        
        infile.close();
        return i;
    }



}

void displayAll(question myquestion[], int numOfQuestions){

    for(int i=0;i<numOfQuestions;i++){
        cout<<myquestion[i].question<<endl;
    }

}

void displayBySubject(question myquestion[], int numOfQuestions){
    char userInput[SIZE];

    cout<<"Enter Subject: "<<endl;
    cin.get(userInput,SIZE,'\n');
    cin.ignore(100,'\n');

    cout<<"\n"<<endl;

    for(int i=0;i<numOfQuestions;i++){
        if(strcmp(userInput,myquestion[i].subject) == 0){
            cout<<myquestion[i].question<<endl;
        }
    }
}


int getUserOption(){
    int userInput;
    
    cout<<"\nEnter One Of The Following Options"<<endl;
    cout<<"1.Write New Questions"<<endl;
    cout<<"2.Display All Questions"<<endl;
    cout<<"3.Display Questions By Subject"<<endl;
    cout<<"______________________________"<<endl;

    cin>>userInput;
    cin.ignore(100,'\n');

    cout<<"\n"<<endl;
    
    if(userInput == 1){
        return 1;
    }else if(userInput == 2){
        return 2;
    }else if(userInput == 3){
        return 3;
    }else{
        return 0;
    }

}

bool again(){
    char input; 
    
    cout<<"\nWould You Like To Quit(Y/N): "<<endl;
    cin>>input;

    input = toupper(input);

    if(input == 'Y'){
        return false;
    }else{
        return true;
    }


}


int getLastNum(){
    ifstream infile;
    infile.open("questions.txt");

    if(infile.fail()){
        return 1;
    }

    int i = 0;

    if(infile){
        while(!infile.eof()){
            infile.ignore(100,'\n');
            i = i+ 1;
        }

        infile.close();
        return i;
    }

}
