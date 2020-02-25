
#include "common.h"



int main(){

	int wordNum[9];
	char words[9][10] = {"The","quick","brown","fox","jumps","over","the","lazy","dog"};

	struct timeval start;
	struct timeval end;
	struct timeval result;
	struct timezone zone;

	int seconds;
	int microseconds;

	srand(time(NULL));
	generateRandom(wordNum);



	gettimeofday(&start,&zone);
	for(int i=0;i<9;i++){
		checkWord(words,wordNum[i]);
	}

	gettimeofday(&end,&zone);

	timersub(&end,&start,&result);
	seconds = result.tv_sec;
	microseconds = 1000000*result.tv_sec + result.tv_usec;

	printf("You Took %d seconds and %d microseconds!\n",seconds,microseconds);




	
	




	return 0;

}
