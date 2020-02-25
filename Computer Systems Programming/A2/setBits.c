#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//function to print the set value in binary
void printInBinary(unsigned int number){
	int bits[sizeof(unsigned int)*8];
	
	for(int i=0;i<sizeof(unsigned int)*8;i++){		
		bits[i] = number & 1;
		number = number>>1;
	}

	for(int i=15;i>=0;i--){
		printf("%d",bits[i]);

		if(i % 4 == 0){
			printf(" ");
		}

	}

	printf("\n");

}

//function to check if value is set in command line
int validInputs(int num){
	
	if(num<2){
		printf("No Value Is Set\n");
		//printInBinary(0);
		return -1;
	}
}


int main(int argc, char *argv[]){
	
	validInputs(argc);

	unsigned int *numbers; //numbers to set
	int count = argc -1; //count value
	int y = 1; //value of 1 to set to set value
	unsigned short original = 0x0; //starting value

	numbers = (int *) malloc(sizeof(unsigned int)*count);

	for(int i=1;i<argc;i++){
		numbers[i-1]= strtoul(argv[i],NULL,0);

		if(numbers[i-1] < 0 || numbers[i-1] > 15){
			printf("\nError! Please Enter Number Within Range[0-15]\n");
			return -2;
		}
	}
	
	for(int i=0;i<count;i++){

		y = 1;

		y = y<<numbers[i];
			
		original = original | y;

	}
	
	printInBinary(original);

	return 0;

}
