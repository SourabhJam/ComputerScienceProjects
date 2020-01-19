//Sourabh Jamalapuram,October 29 2019, CS162, Program #2
//This program was designed to make it easier for people to save phrases they often use when talking to other people and arrange the phrases in a way that they would like to use to communicate with whoever they want. Final output gives a sentence using phrases the user gives, order they want the phrases to be in, an ending signature they like, and finally their name.
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int SIZE = 131;


void displayWelcomeMessage(); //Displays Welcome Message
void getPhrase(char phrase[]); //Gets A Phrase From The User 
bool isPhraseValid(); //Checks To See If Phrase Is Valid
bool isPhraseEndValid(char phrase[]);  //Checks To See If Phrase Ends In Proper Punctuation
void capitalizePhrase(char phrase[]); //Capatalizes The First Letter Of The Phrase
void removeExtraSpaces(char phrase[]); //Removes Any Extra Spaces In The Phrase
void displayNext(); //Displays What The User Will Be Doing Next
void displayAllPhrases(char phrase1[],char phrase2[],char phrase3[], char phrase4[]); //Displays All The Phrases The User Entered
void getOrderPhrase(char phrase1[],char phrase2[], char phrase3[],char phrase4[], char skipLine[], int order, char finalPhrase[]); //Gets The Order In Which The User Would Like To See The Phrases
bool again(char confirmation); //Asks The User If They Would Like To Re Run The Program
void getSignature(char signature[]); //Gets The Users Desired Signature
void getName(char name[]); //Gets The Users Name


int main(){
    char phrase1[SIZE]; //phrase 1
    char phrase2[SIZE]; //phrase 2
    char phrase3[SIZE]; //phrase 3
    char phrase4[SIZE]; //phrase 4
    char skipLine[2]; //empty space

    int firstPhrase; //numberical value of first phrase in final sentence
    int secondPhrase; //numerical value of second phrase in final sentence
    int thirdPhrase; //numerical value of third phrase in final sentence
    int fourthPhrase; //numerical value of fourth phrase in final sentence

    char finalFirstPhrase[SIZE]; //first phrase in sentence
    char finalSecondPhrase[SIZE]; //second phrase in sentence
    char finalThirdPhrase[SIZE]; //third phrase in sentence
    char finalFourthPhrase[SIZE]; //fourth phrase in sentence
    char finalSkipLine[SIZE]; //skipped phrase in sentence

    bool finalConfirmation; //repeat program true or false
    char confirmation; //repeat program yes or no

    char signature[SIZE]; //users signature
    char name[SIZE]; //users name



    do{
        displayWelcomeMessage();

        getPhrase(phrase1);
        getPhrase(phrase2);
        getPhrase(phrase3);
        getPhrase(phrase4);
        skipLine[0] = ' ';


        displayNext();

        displayAllPhrases(phrase1,phrase2,phrase3,phrase4);

        cout<<"Which Phrase Would You Like To Be Placed 1st: "<<endl;
        cin>>firstPhrase;
        cin.ignore(100,'\n');

        cout<<"Which Phrase Would You Like To Be Placed 2nd: "<<endl;
        cin>>secondPhrase;
        cin.ignore(100,'\n');

        cout<<"Which Phrase Would You Like To Be Placed 3rd: "<<endl;
        cin>>thirdPhrase;
        cin.ignore(100,'\n');

        cout<<"Which Phrase Would You Like To Be Placed 4th: "<<endl;
        cin>>fourthPhrase;
        cin.ignore(100,'\n');


        getOrderPhrase(phrase1,phrase2,phrase3,phrase4,skipLine,firstPhrase,finalFirstPhrase);
        getOrderPhrase(phrase1,phrase2,phrase3,phrase4,skipLine,secondPhrase,finalSecondPhrase);
        getOrderPhrase(phrase1,phrase2,phrase3,phrase4,skipLine,thirdPhrase,finalThirdPhrase);
        getOrderPhrase(phrase1,phrase2,phrase3,phrase4,skipLine,fourthPhrase, finalFourthPhrase);

        getSignature(signature);
        getName(name);

        cout<<"\n"<<finalFirstPhrase<<"\n"<<finalSecondPhrase<<"\n"<<finalThirdPhrase<<"\n"<<finalFourthPhrase<<"\n"<<"\n"<<signature<<", "<<name<<endl;

        cout<<"\nWould You Like To Create A New Phrase(Y/N): "<<endl;
        cin>>confirmation;
        cin.ignore(100,'\n');

        finalConfirmation = again(confirmation);

    }while(finalConfirmation == true);
    


    return 0;
}


void displayWelcomeMessage(){
    cout<<"\nWelcome To The Easy Sentence Formatter. This Program Was Designed For People To Enter Their Four Most Commonly Used Phrases And Arrange Them In A Way That Simplifies The Process Of Retyping Commonly Used Phrases!\n"<<endl;
    cout<<"In This Program We Will Need The Following Information To Be Provided"<<endl;
    cout<<"1. Name"<<endl;
    cout<<"2. 4 Commonly Used Phrases By The User"<<endl;
    cout<<"3. Ending Signature Unique To The User\n"<<endl;
}

void getPhrase(char phrase[]){
    bool isValid;
    bool isEndValid;
    char puncMark;

    cout<<"\nEnter A Phrase: "<<endl;
    cin.get(phrase,SIZE,'\n');

    isValid = isPhraseValid();
        while(isValid == false){
        cin.ignore(100,'\n');
        cout<<"Please Re-enter A Phrase With Less Than "<<SIZE<<" characters"<<endl;
        cin.get(phrase,SIZE,'\n');

        isValid = isPhraseValid();


    }

    cin.ignore(100,'\n');

    isEndValid = isPhraseEndValid(phrase);   

    if(isEndValid == false){
        cout<<"Phrase Needs One Of The Following Punctuation Mark: . ! ?"<<endl;
        cout<<"Which Punctuation Mark Would You Like To Add To The End Of Your Phrase: "<<endl;
        cin>>puncMark;
        cin.ignore(100,'\n');
        strncat(phrase,&puncMark,1);
    }



    removeExtraSpaces(phrase);
    capitalizePhrase(phrase); 
}

bool isPhraseValid(){
    char peek;
    peek = cin.peek();

    if(peek != '\n'){
        return false;
    }else{
        return true;
    }

}


bool isPhraseEndValid(char phrase[]){
    int puncMarkPos = 0;
    puncMarkPos = strlen(phrase) - 1;

    if( phrase[puncMarkPos] != '?' && phrase[puncMarkPos] != '.' && phrase[puncMarkPos] != '!' ){
        return false;
    }else{
        return true;
    }

}


void capitalizePhrase(char phrase[]){
    phrase[0] = toupper(phrase[0]);
    cout<<"New Phrase Is: "<<phrase<<endl;

}

void removeExtraSpaces(char phrase[]){
    int phraseLength = strlen(phrase);
    int nextBox = 1;

    for(int currentBox=0; currentBox<phraseLength; currentBox++){
        if(phrase[currentBox]== ' ' && phrase[nextBox] == ' '){
            for(int slideBox= currentBox; slideBox<phraseLength; slideBox++){
                phrase[slideBox] = phrase[slideBox+1];

            }
        }
        nextBox++;
    }
}

void displayNext(){
    cout<<"\nWe Will Now Move On To The Next Step.\nYou Will Now Be Able To View Your Inputed Phrases And Prompted In Which Order You Would Like These Phrases To Be Placed!\n"<<endl;
}

void displayAllPhrases(char phrase1[], char phrase2[], char phrase3[], char phrase4[]){
    cout<<"Here Are Your Inputed Phrases:\n 1. "<<phrase1<<"\n 2. "<<phrase2<< "\n 3. "<<phrase3<< "\n 4. "<<phrase4<<"\n\nIf You Would Like To Skip A Phrase Please Enter 0\n"<<endl;
}

void charCopy(char source[], char destination[]){

    int len = strlen(source);

    for(int i=0; i<len; i++){
        destination[i] = source[i];
    }

    destination[len] = '\0' ;



}

void getOrderPhrase(char phrase1[], char phrase2[], char phrase3[], char phrase4[],char skipLine[], int phraseNum, char finalPhrase[]){
    
    if(phraseNum == 1){
        charCopy(phrase1,finalPhrase);
    }else if(phraseNum == 2){
        charCopy(phrase2, finalPhrase);
    }else if(phraseNum == 3){
        charCopy(phrase3, finalPhrase);
    }else if(phraseNum == 4){
        charCopy(phrase4, finalPhrase);
    }else if(phraseNum == 0){
        charCopy(skipLine, finalPhrase);
    }

}

bool again(char confirmation){
    confirmation = toupper(confirmation);

    if(confirmation == 'Y'){
        return true;
    }else{
        return false;
    }
}

void getSignature(char signature[]){

    cout<<"\nPlease Enter Desired Signature(Ex: Sincerely, Thank You, Regards)"<<endl;
    cin.get(signature,SIZE,'\n');
    cin.ignore(100,'\n');

    int sigLen = strlen(signature);
    
    for(int i=0;i<sigLen;i++){
        if(signature[i] == ' '){
            signature[i+1] = toupper(signature[i+1]);
        }
    }

        signature[0] = toupper(signature[0]);


}


void getName(char name[]){

    cout<<"\nPlease Enter Your Full Name: "<<endl;
    cin.get(name,SIZE,'\n');
    cin.ignore(100,'\n');

    int nameLen = strlen(name);

   for(int i=0;i<nameLen;i++){
        if(name[i] == ' '){
            name[i+1] = toupper(name[i+1]);
        }

    }

   name[0] = toupper(name[0]);
}
