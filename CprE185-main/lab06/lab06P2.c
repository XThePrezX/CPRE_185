/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name: Preston Gaskill																	 -
- 	Section: 03																 -
-	NetID: pgask26																     -
-	Date: 03/10/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
void bopGame ();

/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    srand(time(NULL)); /* This will ensure a random game each time. */
	
	printf("This is a Bop-It game!\n");
	printf("Please press any key to begin!\n");
	
	char startVal[1];
	
	scanf("%c", &startVal);
	
	if (startVal != NULL) {
		bopGame();
	}
	
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

void bopGame () {
	int loopCount = 0;
	int endVal = 1;
	int rand(void);
	char c = 0; 
	int inputC;
	clock_t startT, endT;
	double currentTime;

	while (endVal) {
		int responseTime = 2500 - (loopCount * 100);
		int key = (rand() % 93) + 33;
		startT = clock();
	
		while (1) {
			int character = (rand() % 93) + 33;
			while  (character != 127) {
				printf("%c: %d\n", character, character);
				character = 1 + character;
			}

			printf("\nPress the '%d' key!\n", key);
			printf("You have %d milliseconds to respond!\n", responseTime);
			
			endT = clock();
			currentTime = ((double)(endT - startT) / CLOCKS_PER_SEC) * 1000;
			
			scanf(" %c", &c);
			inputC = (int) c;
		
			
				if ((currentTime < responseTime) && (key == inputC)) {
						printf("Curr time: %d, Resp time: %d\n", currentTime, responseTime);
						break;
				} else if ((key != inputC) || (currentTime >= responseTime)) {
					
						printf("\nWrong key or you ran out of time! :(\n");
						printf("You lose!\n");
						printf("You made it through %d rounds!\n", loopCount);
						
						endVal = 0;
						break;
				}
			
			
			fflush(stdin);
		}
		
		loopCount++;
		fflush(stdin);
	}
}