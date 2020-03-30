
//function to print in binary(testing purposes)
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

//function to shift fraction field
double shiftFrac(int fracShift, int num, int frac){
	unsigned int fracField = num<<fracShift;
	fracField = fracField>>fracShift;

	int result = pow(2,frac);

	double fracFieldVal = (double)fracField/(double) result;

	return fracFieldVal;
}

//function to shift exponent field
double shiftExp(int num, int frac, int expShift){

	unsigned int expField = num>>frac;
	expField = expField << expShift;
	expField = expField >> expShift;

	return expField;

}

//function to get final output
double getOutput(double M,double E, int signBit){
	double output = 0;	

	if(signBit == 1){
		output = -1*M * pow(2,E);
	}else{
		output = M * pow(2,E);
	}

	return output;

}

//function to get Sign Value
int shiftSign(int frac,int exp, int num){
	
	//printf("\nfrac shift: %d\n",frac);
	//printf("\nexp shift: %d\n",exp);
	unsigned int signBit = num>>(frac+exp);
	signBit = signBit<<31;
	signBit = signBit>>31;

	if(signBit == 0){
		return 0;
	}else{
		return 1;
	}

}

//function to check for special cases such as +0,-0,+inf,-inf,and NaN
int checkSpecialCases(double expField, double exp, double fracField, double signBit){
		
		int newExp = pow(2,exp) - 1;	
		int expFull;

		if(newExp == expField){
			expFull = 0;
		}else{
			expFull = 1;
		}

		if(fracField == 0 && expFull == 0){
			if(signBit == 0){
				printf("\n+inf\n");
				return 0;
			}else if(signBit == 1){
				printf("\n-inf\n");
				return 0;
			}

		}

		if(expFull == 0 && fracField != 0){
			printf("\nNaN\n");
			return 0;
		}

		if(expField == 0 && fracField == 0){
			if(signBit == 0){
				printf("\n+0.000000\n");
				return 0;
			}else{
				printf("\n-0.000000\n");
				return 0;
			}
		}

		return 1;
}			
	
