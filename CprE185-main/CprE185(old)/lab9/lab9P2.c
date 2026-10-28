// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s) ;

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	wordCount = readWords(wordlist, argv[1]);

	int ValueX, ValueY;
	
	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		// add code to print the words to the screen here for part 1
		for (i = 0; i < wordCount; i++) {
			printf("%10s,", wordlist[i]);
		}
	printf("\n");
	}

// most of your code for part 2 goes here. Don't forget to include the ncurses library 
	/*
	ValueX = 0;
	ValueY = 0;
		for(i = 0; i < wordCount; i++) {
			// void mvprintw(int row, int col, char * format,arg1, arg2, arg3…).
			mvprintw(ValueY, ValueX, "%15s", wordlist[i]);
			}
		}
		
	*/
    return 0;
	}
