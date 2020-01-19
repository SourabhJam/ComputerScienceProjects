#include "array.h"

array::array(){
    
    for(int i=0;i<10;i++){
        ptr[i] = NULL;
    }
    
    numOfItems = 0;
    arraySize = 0;
}



array::~array(){


    for(int i=0;i<numOfItems;i++){
        delete ptr[i];
    }
}



int array::readIn(){


    ifstream infile;
    infile.open("questions.txt");

    int num;
    char subject[SIZE];
    char text[SIZE];
    char date[SIZE];


    if(infile){
        while(!infile.eof()){

            num = 0;
            infile>>num;
            infile.ignore(100,'|');
            if(num == 0){
                break;
            }

            infile.get(subject,SIZE,'|');
            infile.ignore(100,'|');

            infile.get(text,SIZE,'|');
            infile.ignore(100,'|');

            infile.get(date,SIZE,'\n');
            infile.ignore(100,'\n');

            question *qtr = new question;
            qtr->setParameters(num,subject,text,date);
            ptr[numOfItems] = qtr;
             
            //ptr[i]->display();
            
            
            
            

            numOfItems = numOfItems + 1;

    
        }

        

        infile.close();


    

    }

}

void array::getUserQuestions(){
    for(int i=0;i<10;i++){

        question *q = new question;

        q->getQuestion();

        ptr[i] = q;

        numOfItems = numOfItems + 1;

        ptr[i]->writeOut(numOfItems);

    }
}





void array::displayAll(){

    

    for(int i=0;i<numOfItems;i++){
        ptr[i]->display();
    }


}


void array::displayBySubject(){

    char userInput[SIZE];
    bool match = false;




    cout<<"What Subject Would You Like To View: "<<endl;
    cin.get(userInput,SIZE,'\n');

    cout<<"\n"<<endl;

    for(int i=0;i<numOfItems;i++){

        match = ptr[i]->compare(userInput);

        if( match == true ){
            ptr[i]->display();
        }

    }
}

int array::getUserOption(){
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

