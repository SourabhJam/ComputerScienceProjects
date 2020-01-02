#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

#include "question.h"

class array{

    public:
        array(); //constructor to initialize variables
        ~array(); //destructor to deallocate any dynamic memory
        int readIn(); //reads in information from external file
        void displayAll(); //displays all the questions
        void displayBySubject(); //displays questions based on user entered subject
        void getUserQuestions(); //gets questions from user if they want to add new questions
        int getUserOption(); //asks user if they would like to display all , display by subject, write new questions

    private:
        question *ptr[10]; //array of questions
        int numOfItems; //number of items in the file
        int arraySize; //size of array
        

};
