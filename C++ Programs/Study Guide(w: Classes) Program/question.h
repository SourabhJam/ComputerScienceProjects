#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE = 50;

class question{
    
    public:
        question(); //constructor to initialize variables
        ~question(); //destructor to deallocate dynamic memory
        void getQuestion(); //gets one question from the user
        void display(); //displays a single questions
        bool compare(char* userInput); //compares user entered subject to subjects in file
        void setParameters(int newNum, char *newSubject, char *newText, char *newDate); //sets parameters of each variable
        void writeOut(int lastNum); //writes question information to file


    private:
        int num; //question number
        char *subject; //question subject
        char *text; //question text
        char *date; //question date



};
