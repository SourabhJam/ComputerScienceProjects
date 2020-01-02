//Sourabh Jamalapuram,November 26 2019,CS162,Program #4
//This program was designed to make it easier for students to organize and study practice questions for a test or class. This program gives students the option to enter new practice questions, display all practice questions, and to display practice questions filtered by a specfic subject. The convienent part about this program is that it uses external files to store information so students can access their practice questions whenever they want to. A student could enter practice questions and come back a few days later and would still be able to access the questions created days ago.

#include "array.h"

int main(){

    cout<<"Welcome To The Computer Science Test Guide. This Program Was Designed For People To Enter Practice Questions That They Would Like To Study And Revisit The Questions At Any Given Time"<<endl;

    bool continueProgram = false;
    
    
    
   
    
    do{ 
    
        array questionArray;
        int userOption = 0;
        char quit;

        userOption = questionArray.getUserOption();

        questionArray.readIn();

        if(userOption == 1){
            questionArray.getUserQuestions();
        }else if(userOption == 2){
            questionArray.displayAll();
        }else if(userOption == 3){
            questionArray.displayBySubject();
        }else{
            cout<<"Please Enter Valid Option!!!"<<endl;
        }

        cout<<"\nWould You Like To Quit(Y/N): "<<endl;
        cin>>quit;
        cin.ignore(100,'\n');

        quit = toupper(quit);

        if(quit == 'Y'){
            continueProgram = false;
        }else{
            continueProgram = true;
        }

    }while(continueProgram == true);















    return 0;
}
