//Sourabh Jamalapuram,December 10 2019,CS162,Program #5
//This program was designed to simulate a to-do list. In this program u start out with 3 tasks(Program #5, CS Final, CS Final Proficiency Demo). With this list you can display what is in your do to list, add any new tasks to the list, view tasks based on the priority level, delete tasks from list, get the number of how many tasks you have, and finally delete the list itself as a whole.

#include "node.h"

int main(){
    
    node mynode;
    int userOption = 0;
    char again;

    node *head = NULL;

    mynode.build(head);

    cout<<"\nWelcome To The Task Manager. This Program Was Designed So Students Can Keep Track Of Any Assignments, Projects, Exams, & Classwork. You Will Start Out With 3 Tasks Consisting Of Your CS Program #5, CS Final, & CS Final Proficiency Demo. Each Task Consists Of A Title,Description,Priority Level, & Due Date. The Following Program Will Allow You To View Your Tasks, Add New Tasks, View Tasks Based On Priority Level, Delete Tasks, Count The Number Of Tasks, and Finally To Delete The List!"<<endl;

    do{


        userOption = mynode.getUserOption();

        if(userOption == 1){
            mynode.display(head);
        }else if(userOption == 2){
            mynode.addNew(head);
        }else if(userOption == 3){
            mynode.displayByPriority(head);
        }else if(userOption == 4){
            mynode.removeItem(head);
        }else if(userOption == 5){
            mynode.countList(head);
        }else if(userOption == 6){
            mynode.removeList(head);
            mynode.display(head);
        }

        cout<<"Would You Like To Re-Run The Program(Y/N): "<<endl;
        cin>>again;
        cin.ignore(100,'\n');

        again = toupper(again);

    }while(again=='Y');



    return 0;

}
