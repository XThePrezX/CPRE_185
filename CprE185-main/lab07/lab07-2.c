/*---------------------------------------------------------------------------
-					  SE 185: Lab 07 - Pointers, Pointers and More Pointers           -
-	Name: Preston Gaskill                                                                     -
- Section: 3                                                                 -
-	NetID: pgask26                                                                   -
-	Date: 03/24/23                                                                     -
-                                                                           -
-   This file provides the outline for your program.                        -
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									                                   -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/* add whatever you see fit and need */

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/

/* put your function prototypes here */

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/

// compile with gcc -o lab07-1 lab07-1.c

/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{

    /* implement your solutions here */
	
	char* inputName = (char*) malloc(sizeof(char) * 1024);
	char* inputMajor = (char*) malloc(sizeof(char) * 1024);
	
	printf("Input name:\n");
	scanf("%s", inputName);
	
	printf("Input major:\n");	
	scanf("%s", inputMajor);
	
	printf("\nName: %s\n", inputName);
	printf("Major: %s\n", inputMajor);
	
	free(inputName);
	free(inputMajor);


    return 0;

}

/*-----------------------------------------------------------------------------
-								Functions
-----------------------------------------------------------------------------*/

/* put your functions here */
