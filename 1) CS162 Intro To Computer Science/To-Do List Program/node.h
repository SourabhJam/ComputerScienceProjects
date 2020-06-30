#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


int const TITLE = 50;
int const SIZE = 200;
int const DATE = 10;



class node{


    public:
        node();
        void build(node * &head); //builds the initial list
        void display(node *head); //displays the list
        int getUserOption(); //asks user what they would like to do
        void addNew(node * &head); //adds new item to list
        void displayByPriority(node *head); //displays tasks by priority level
        void countList(node * &head); //counts the number of nodes in the list
        void removeList(node *head); //deletes the list
        void removeItem(node * &head); //removes a task from the list









    private:
        char title[TITLE];
        char description[SIZE];
        int priority;
        char date[DATE];

        node *next;

















};
