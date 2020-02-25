#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "fp_parse.h"
#include <stdbool.h>



int main(int argc, char* argv[]){

	if(argc != 4){
		printf("\nUsage: fp_parse <# of frac_bits> <# of exp_bits>\n");
		exit(argc);
	}
	
	unsigned int frac = 0; //user input of fraction bits
	unsigned int exp; //user input of exponent bits
	unsigned int num; //user input of hex number
	
	double E; //E value
	double Bias; //Bias Value
	double M; //M Value
	
	double fracField; //value of fraction field
	double expField; //value of exponent field
	int signBit; //positive or negative
	double finalOutput; //final output

	sscanf(argv[1], "%d", &frac);
        sscanf(argv[2], "%d", &exp);
        sscanf(argv[3], "%x", &num);
	
		
	unsigned int InvalidNum = num >> frac; //valid or invalid number
	InvalidNum = InvalidNum >> exp;
	InvalidNum = InvalidNum >> 1;


	if(frac <2 || frac > 10){
		printf("\nInvalid number of fraction bits (%d). Should be between 2 and 10\n",frac);
		return 0;
	}else if(exp < 3 || exp > 5){
		printf("\nInvalid number of exponent bits (%d). Should be between 3 and 5\n",exp);
		return 0;
	}else if( InvalidNum != 0){
		printf("\nNumber %s exceeds maximum number of bits. Only %d allowed here.\n",argv[3],(frac+exp+1));
		return 0;
	}

	int fracShift = 32-frac;
	int expShift = 32-exp;

	fracField = shiftFrac(fracShift,num,frac);
	expField = shiftExp(num,frac,expShift);
	signBit = shiftSign(frac,exp,num);

	int specialCase = checkSpecialCases(expField,exp,fracField,signBit);

	if(specialCase == 1){

		M = 1 + fracField;

		Bias = pow(2,(exp-1)) - 1;
	
		E = expField - Bias;

		finalOutput = getOutput(M,E,signBit);
	
		printf("\n%f\n",finalOutput);

	}

	return 0;

}

