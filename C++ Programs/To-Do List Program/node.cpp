#include "node.h"






node::node(){

    title[0] = '\0';
    description[0] = '\0';
    priority = 0;
    date[0] = '\0';
    next = NULL;





}





void node::build(node * & head){

    node *second = NULL;
    node *third = NULL;

    head = new node;
    second = new node;
    third = new node;

    strcpy(head->title,"Program #5");
    strcpy(head->description,"Complete Program #5 for CS120");
    head->priority = 2;
    strcpy(head->date,"Dec10");
    head->next = second;

    strcpy(second->title,"CS Final");
    strcpy(second->description,"Study for CS12O Final. Final Consists Of Topics 1-6.");
    second->priority = 5;
    strcpy(second->date,"Dec12");
    second->next = third;

    strcpy(third->title,"CS Final Proficiency Demo");
    strcpy(third->description,"Practice for CS120 final proficiency demo. Demo will be on Linear Linked Lists. Practice Traversing through LLL, adding to LLL, removing from LLL...");
    third->priority = 10;
    strcpy(third->date,"Dec10");
    third->next = NULL;

}



void node::display(node *head){

    node* current = head;

    int count = 1;

    if(head == NULL){
        cout<<"List Is Empty"<<endl;
    }else{
    

    while(current->next != NULL){
        cout<<"\nTask "<<count<<endl;
        cout<<"________________"<<endl;
        cout<<current->title<<endl;
        cout<<current->description<<endl;
        cout<<current->priority<<endl;
        cout<<current->date<<endl;
        current = current->next;
        count = count + 1;

    }

    cout<<"\nTask "<<count<<endl;
    cout<<"_________________"<<endl;
    cout<<current->title<<endl;
    cout<<current->description<<endl;
    cout<<current->priority<<endl;
    cout<<current->date<<endl;

    cout<<endl;

    }

}


void node::addNew(node * &head){
    
    node *current = head;
    
    char title[SIZE];
    char description[SIZE];
    int priority;
    char date[SIZE];

    while(current->next != NULL){
        current = current->next;
    }

    cout<<"Enter Title Of Task: "<<endl;
    cin.get(title,SIZE,'\n');
    cin.ignore(100,'\n');

    cout<<"Enter Description Of Task: "<<endl;
    cin.get(description,SIZE,'\n');
    cin.ignore(100,'\n');

    cout<<"Enter Priority Of Task: "<<endl;
    cin>>priority;
    cin.ignore(100,'\n');

    cout<<"Enter Date Of Task: "<<endl;
    cin.get(date,SIZE,'\n');
    cin.ignore(100,'\n');

    node *temp = current;

    current = new node;

    strcpy(current->title,title);
    strcpy(current->description,description);
    current->priority = priority;
    strcpy(current->date,date);

    current->next = NULL;

    temp->next = current;

}

void node::displayByPriority(node *head){

    int priority;
    int count = 1;
    
    cout<<"Enter Priority You Would Like To View:"<<endl;
    cin>>priority;
    cin.ignore(100,'\n');

    node *current = head;

    while(current != NULL){
        
        if(current->priority == priority){
            cout<<"\nTask "<<count<<endl;
            cout<<"_________________"<<endl;
            cout<<current->title<<endl;
            cout<<current->description<<endl;
            cout<<current->priority<<endl;
            cout<<current->date<<endl;
        }

        current = current->next;

    }

}

void node::countList(node * &head){

    node * current = head;
    int total = 0;

    while(current != NULL){
        total = total + 1;
        current = current->next;
    }

    
    cout<<"You Have "<<total<<" Tasks In Your To-Do List"<<endl;


}

void node::removeItem(node * &head){

    char title[100];

    cout<<"Enter Title Of Item You Would Like To Remove: "<<endl;
    cin.get(title,100,'\n');
    cin.ignore(100,'\n');

    node *current = head;

    if( strcmp(head->title,title) == 0){
        head = head->next;
    }else{

        while(current->next->next != NULL){
            current = current->next;
        }

        if( strcmp(current->next->title,title) == 0){
            current->next = NULL;
        }


    
        current = head;
    while(current->next != NULL){
        
        if( strcmp(current->next->title,title) == 0){
            current->next = current->next->next;
        }

        current = current->next;
    }

    

    }

}

void node::removeList(node * &head){

    node *current = head;

    head = NULL;

    cout<<"Memory Has Been Released!!!"<<endl;

}







int node::getUserOption(){

    int userOption = 0;
    
    cout<<"\nSelect One Of The Following Options"<<endl;
    cout<<"1.Display Content"<<endl;
    cout<<"2.Add New Item"<<endl;
    cout<<"3.Display By Priority"<<endl;
    cout<<"4.Remove Item"<<endl;
    cout<<"5.Number Of Items In List"<<endl;
    cout<<"6.Release Memory"<<endl;
    cout<<"______________________________"<<endl;

    cin>>userOption;
    cin.ignore(100,'\n');

    if(userOption == 1){
        return 1;
    }else if(userOption == 2){
        return 2;
    }else if(userOption == 3){
        return 3;
    }else if(userOption == 4){
        return 4;
    }else if(userOption == 5){
        return 5;
    }else if(userOption == 6){
        return 6;
    }else{
        return 0;
    }





}








