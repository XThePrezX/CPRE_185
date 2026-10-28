/*---------------------------------------------------------------------------
-		                SE 185: Lab 09 - The DS4Talker                      -
-	Name: Preston Gaskill                                                                  -
- 	Section:  03                                                              -
-	NetID: pgask26                                                                 -
-	Date: 04/14/23                                                                   -
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

/*----------------------------------------------------------------------------
-								Defines	    								 -
-----------------------------------------------------------------------------*/
#define MAX_WORD_LENGTH 12 /* The maximum length a word can be. */
#define MAX_WORDS 75 /* The maximum words that can be in the DS4Talker. */

// Character definitions taken from the ASCII table
#define AVATAR '>'
#define EMPTY_SPACE ' '
/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
void trim_whitespace(char *string);

int read_words(char *word_list[MAX_WORDS], char *file_name);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab09.c -o lab09 -lncurses
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b -bt -bd | ./lab09 word_list.txt
// NO GLOBAL VARIABLES ARE ALLOWED!

/*----------------------------------------------------------------------------
-								Implementation                               -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    char *word_list[MAX_WORDS];
    int word_count = read_words(word_list, argv[1]);
    int i;
    initscr();

    /* Most of your code should go here. */
	int j = 5;
	int k = 0;
	
	int t;
	
	int b[4];
	
	int z[8];

	int q[4];
	
	//Print list values to screen
	for (i = 0; i < MAX_WORDS; i++, j++) {
		if (i%15 == 0) {
			k += 12;
			j = 5;
		}
		mvprintw(j, k, "%s", word_list[i]);
		refresh();
	}
	
	word_list[0] = "the";
		
	j = 5;
	k = 10;
	int prev_k;
	int prev_j;
	int sentX = 10;
	int sentY = 30;
	char sent[80] = "";
	int position = 0;
	int curStrLength = 0;
	char temp[80] = "";
	bool cap = false;
	
	
	draw_character(k, j, AVATAR); //place new avatar
	
	scanf("%d,%d,%d,%d, %d,%d,%d,%d,%d,%d,%d,%d, %d,%d,%d,%d", &b[0], &b[1], &b[2], &b[3], &z[0], &z[1], &z[2], &z[3], &z[4], &z[5], &z[6], &z[7], &q[0], &q[1], &q[2], &q[3]);
	
	do {
		fpurge(stdin);
		scanf("%d,%d,%d,%d, %d,%d,%d,%d,%d,%d,%d,%d, %d,%d,%d,%d", &b[0], &b[1], &b[2], &b[3], &z[0], &z[1], &z[2], &z[3], &z[4], &z[5], &z[6], &z[7], &q[0], &q[1], &q[2], &q[3]);
		fpurge(stdin);
		prev_k = k;
		prev_j = j;
		
		//Button Movements
		if(q[0] && j != 5) {
			j -= 1;
			
		}
		if(q[3] && k < 50) {
			k += 12;
			
		}
		if(q[2] && j != 19) {
			j += 1;
			
		}
		if(q[1] && k != 10) {
			k -= 12;
			
		}
		
		//Print char
		if (b[0]) { //Tri
			int row = (j-5);
			int col = ((k-10)%11);
			int x = (col * 15) + row;
			char word[12];
			
			strcpy(word, word_list[x]);//Get word

			
			if (cap) {
				if (strlen(word) > 0) {
					word[0] = toupper(word[0]);//Cap word
				}

				cap = !cap;
			}
				strcpy(temp, sent);//Copy old string
				strcat(sent, " ");
				strcat(sent, word);//Set new string
				mvprintw(sentY, sentX, "%s", sent); 
		}
		if (b[2]) { //X
			
			strcpy(sent, temp);//Set old string as new string
			int tempx = sentX;
			
			while (tempx <= 90) {
				mvprintw(sentY, tempx, " ");
				tempx++;
			}
			
			
			mvprintw(sentY, sentX, "%s", sent);
		}
		if (b[3]) { //Square
			int row = (j-5);
			int col = ((k-10)%11);
			int x = (col * 15) + row;
			char word[12];
			
			strcpy(word, word_list[x]);//Get word

			
			if (cap) {
				if (strlen(word) > 0) {
					word[0] = toupper(word[0]);//Cap word
				}

				cap = !cap;
			}
				strcpy(temp, sent);//Copy old string
				strcat(sent, word);//Set new string
				mvprintw(sentY, sentX, "%s", sent); 
		}
		if (b[1]) { //Circle
			cap = !cap;
		}
	
		if (z[2]) { //Stop buttons
			break;
		}
		
		if (z[3]) { //Stop buttons
			break;
		}
		
		if (z[0] || z[1]) { //Bumpers for newline
			strcpy(temp, "");
			position = 0;
			sentY++;
		}
		
	
	draw_character(prev_k, prev_j, EMPTY_SPACE); //Erase previous avatar
	draw_character(k, j, AVATAR); //place new avatar
	
	nanosleep(&(struct timespec) { .tv_sec = 0, .tv_nsec = 90000000 }, NULL);
	
	} while(1);
	
	
	endwin();
	
		
    return 0;
}

/**
 * Modifies the given string to trim white space off at the end.
 * DO NOT MODIFY THIS FUNCTION.
 *
 * @param string - The string to ensure has no whitespace.
 */
void trim_whitespace(char *string)
{
    int length = strlen(string);
    if (length == 0) return;

    int i = length - 1;
    while (isspace(string[i]) && i >= 0)
    {
        string[i] = '\0';
        i--;
    }
}

/**
 * Reads words from the given file into word_list.
 * DO NOT MODIFY THIS FUNCTION.
 *
 * @param word_list - The list of words where the words taken from the given
 *                    file will be placed.
 * @param file_name - The name of the file to read from.
 * @return - The number of words read from the file.
 */
int read_words(char *word_list[MAX_WORDS], char *file_name)
{
    int number_of_words_read = 0;
    char line[MAX_WORD_LENGTH];
    char *pointer;
    FILE *file = fopen(file_name, "r");

    while (!feof(file))
    {
        pointer = fgets(line, MAX_WORD_LENGTH, file);
        if (pointer != NULL)
        {
            trim_whitespace(line);
            word_list[number_of_words_read] = (char *) malloc(strlen(line) + 1);
            strcpy(word_list[number_of_words_read], line);
            number_of_words_read++;
        }
    }

    fclose(file);
    return number_of_words_read;
}
// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//
//    >>>>DO NOT CHANGE THIS FUNCTION.<<<<
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}

/*

	1. 1. Describe how you keep track of the word selected on the screen and how this interfaces with the DualShock 4. Is the interface reasonable?

	Instead of keeping track if the word selected on the screen I just tracked the current string and the previous string. Originally I tried to store
	the strings in a string array so you could do it multiple times like ctrl-Z, but I ended up getting segmentation fault errors and I believe that was because what I was
	putting into the string array was to large. This wasn't a resonable interface so I ended up with my other method.

*/