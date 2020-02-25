
#include "common.h"

bool checkInput(char word[]){
	char userInput[20];
	char c;

	scanf("%10s",userInput);
	while((c=getchar()) != '\n' &&  c != EOF){
	};
	

	if(strcmp(userInput,word)==0){
		return true;
	}else{
		return false;
	}
}

void generateRandom(int wordNum[]){
	int i;
	int j;
	int temp;	
	
	for(int i=0;i<9;i++){
		wordNum[i] = i;
	}	

	for(int i=0;i<9;i++){
		j = (rand()% 8) + 1;
		temp = wordNum[i];
		wordNum[i] = wordNum[j];
		wordNum[j] = temp;
	}
}

void checkWord(char words[][10],int num){
	
	bool wordChecker;

		do{	
			printf("\nThe Word Is %s:\n",words[num]);
			wordChecker = checkInput(words[num]);
			if(wordChecker == false){
				printf("Incorrect! Please Try Again!\n");
			}
		}while(wordChecker == false);

}


