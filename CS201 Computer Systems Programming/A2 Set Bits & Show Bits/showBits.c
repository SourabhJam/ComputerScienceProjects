#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	if(argc<3){
		printf("Error: please provide two hexadecimal numbers as arguments to the program\n");
		return -1;
	}

	unsigned int num1;
	unsigned int num2;

	num1 = strtoul(argv[1],NULL,16);
	num2 = strtoul(argv[2],NULL,16);

	if(num1 ==0 || num2==0){
		printf("\ninput valid inputs\n");
		return -2;
	}
	
	unsigned int common = 0;
	int count = 0;
	int arrayCount = 0;
	int bits[20];

	memset(bits,0,sizeof(int)*20);

	common = num1 & num2;

	int numBits = sizeof(unsigned int) * 8;

	for(int i = numBits; i>=0;i--){
		
		if(common & 1){
		
			bits[arrayCount] = count;
			arrayCount = arrayCount + 1;	
		}

		common = common>>1;

		count = count + 1;
	}

	
	common = num1 & num2;

	printf("Bits ");

	for(int i=0;i<arrayCount;i++){	
		printf(" %d,",bits[i]);
	}

	printf(" In Common\n");


	
	common = num1 & num2;
	
	
	printf("Hexadecimal: 0x%x\n",common);
	signed int commonSigned = (signed int) common;
	printf("Signed Is:  %d\n",commonSigned);
	printf("Unsigned is: %u\n",common);



		




	return 0;
}
