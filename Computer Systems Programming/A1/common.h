	
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

bool checkInput(char word[]); //checks to see if the users input of the word matches the word prompted
void generateRandom(int wordNum[]); //generates random order for the words
void checkWord(char[][10],int num); //checks to see if word matches user input, if it does not it asks user to re-enter

