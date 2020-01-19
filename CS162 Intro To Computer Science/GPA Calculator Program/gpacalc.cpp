//Sourabh Jamalapuram, October 15 2019, CS162, Program #1
//This program was designed for Portland State University Students to input their expected grades for the current term and recieve their expected GPA for the current term. The program also allows userto provide their information from past terms and recieve a expected cumulative GPA.

#include <iostream>
#include<cctype>
using namespace std;

int main(){

    int numOfClasses; //Number Of Classes User Is Taking
    char gradeInput[5]; //Users Letter Grade
    float totalQualityPoints = 0; //Users Total Quality Points For Term
    float currentQualityPoints = 0; //Users Quality Points For One Entry
    int totalCreditHours = 0; //Users Total Credit Hours For Term
    int currentCreditHours = 0; //Users Credit Hours Of Single Class
    float currentTermGPA = 0; //Current Term GPA
    float pastTermQualityPoints = 0; //Total Quality Points From Previous Terms
    int pastCreditHours = 0; // Total Credit Hours From Previous Terms
    float cumulativeQualityPoints = 0; //Cumulative Quality Points
    int cumulativeCreditHours = 0; //Cumulative Credit Hours
    float cumulativeGPA = 0; //Cumulative GPA
    bool quit = false; //Repeat Program
    char userOption[5]; //If User Wants To Recalculate
    bool valid = false; //Valid Grade Checker
    
    
    cout<<"\nWelcome to the Portland State GPA Calculator. This program was designed for current PSU students to calculate and view their expected GPA for the current term and to calculate and view your overall cumulative GPA. In order to get started you will need to provide the follow information: \n"<<endl;
    cout<<"1. Expected Grades For Current Term "<<endl;
    cout<<"2. Credit Hours Of Current Terms Classes "<<endl;
    cout<<"3. Total Quality Points From Past Terms "<<endl;
    cout<<"4. Total Credit Hours From Past Terms \n"<<endl;

    do{ 
        cout<<"How many classes are you taking this term?"<<endl;

        cin>>numOfClasses;

            for(int i=1;i<=numOfClasses;i++){
               
               do{   
                cout<<"\nEnter Grade(A-F) For Class Number "<<i<<":"<<endl;
                cin>>gradeInput;
                gradeInput[0] = toupper(gradeInput[0]);

                if(gradeInput[0] == 'A'){
                    if(gradeInput[1] == '-' || gradeInput[1] == '\0'){

                        valid = true;
                    }

                }

                if(gradeInput[0] == 'B' || gradeInput[0]== 'C' || gradeInput[0]== 'D' || gradeInput[0] == 'F'){
                    if(gradeInput[1] == '+' || gradeInput[1] == '-' || gradeInput[1] == '\0'){
                        valid = true;
                    }
                }

                if(valid == false){
                    cout<<"Please Enter Valid Grade!"<<endl; 


                }
               }while(valid==false);

                if(gradeInput[0]=='A' && gradeInput[1]=='\0'){
                    cout<<"\nSuccessfully Submitted Grade Of: A"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 4 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='A'&& gradeInput[1]=='-'){
                    cout<<"\nSuccessfully Submitted Grade Of: A-"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 3.67 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='B' && gradeInput[1]=='+'){
                    cout<<"\nSuccessfully Submitted Grade Of: B+"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 3.33 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='B' && gradeInput[1]=='\0'){
                    cout<<"\nSuccessfully Submitted Grade Of: B"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 3 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='B' && gradeInput[1]=='-'){
                    cout<<"\nSuccessfully Submitted Grade Of: B-"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 2.67 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='C' && gradeInput[1]=='+'){
                    cout<<"\nSuccessfully Submitted Grade Of: C+"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 2.33 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='C' && gradeInput[1]=='\0'){
                    cout<<"\nSucessfully Submitted Grade Of : C"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 2 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='C' && gradeInput[1]=='-'){
                    cout<<"\nSuccessfully Submitted Grade Of: C-"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 1.67 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='D' && gradeInput[1]=='+'){
                    cout<<"\nSuccessfully Submitted Grade Of: D+"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 1.33 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='D' && gradeInput[1]=='\0'){
                    cout<<"\nSuccessfully Submitted Grade Of: D"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 1 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='D' && gradeInput[1]=='-'){
                    cout<<"\nSucessfully Submitted Grade Of D-"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 0.67 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
                else if(gradeInput[0]=='F' && gradeInput[1]=='\0'){
                    cout<<"\nSucessfully Submitted Grade Of F"<<endl;
                    cout<<"\nHow Many Credits Is This Class: "<<endl;
                    cin>>currentCreditHours;
                    totalCreditHours = totalCreditHours + currentCreditHours;

                    currentQualityPoints = 0 * currentCreditHours;
                    totalQualityPoints = totalQualityPoints + currentQualityPoints;
                }
        }

        currentTermGPA = totalQualityPoints/totalCreditHours;

        cout<<"GPA For Current Term Is: "<<currentTermGPA<<endl;


        cout<<"\nWe Will Now Calculate Cumulative GPA"<<endl;
        cout<<"What Is The Total Number Of Quality Points You Have Prior To Current Term"<<endl;
        cin>>pastTermQualityPoints;

        cout<<"\nWhat is The Total Number Of Credit Hours You Have Prior To Current Term"<<endl;
        cin>>pastCreditHours;

        cumulativeQualityPoints = pastTermQualityPoints + totalQualityPoints;
        cumulativeCreditHours = pastCreditHours + totalCreditHours;

        cumulativeGPA = cumulativeQualityPoints/cumulativeCreditHours;

        cout<<"\nYour Cumulative GPA Is: "<<cumulativeGPA<<endl;

        cout<<"\nWould You Like To Recalculate Your GPA(Y/N): "<<endl;
        cin>>userOption;
        userOption[0] = toupper(userOption[0]);

        if(userOption[0]=='Y'){
            quit = false;
        }else{
            quit = true;
        }

    }while(quit==false);



    

}


