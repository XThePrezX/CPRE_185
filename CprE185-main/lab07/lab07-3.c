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

/* add whatever you see fit and need */

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/

/* put your function prototypes here */
void makeChange(int productPrice, int moneyPaid, int* dollars, int* quarters, int* dimes, int* nickels, int* pennies);

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
	int price, paid;
	int dollars, quarters, dimes, nickels, pennies;
	
	printf("Input price (in pennies): ");
	scanf("%d", &price);
	
	printf("Input paid amount (in pennies): ");
	scanf("%d", &paid);
	
	makeChange(price, paid, &dollars, &quarters, &dimes, &nickels, &pennies);
	
    printf("\nDollars: %d\n", dollars);
    printf("Quarters: %d\n", quarters);
    printf("Dimes: %d\n", dimes);
    printf("Nickels: %d\n", nickels);
    printf("Pennies: %d\n", pennies);
	
    return 0;

}

/*-----------------------------------------------------------------------------
-								Functions
-----------------------------------------------------------------------------*/

/* put your functions here */

	void makeChange(int productPrice, int moneyPaid, int* dollars, int* quarters, int* dimes, int* nickels, int* pennies) {
		int change = moneyPaid - productPrice;
		
		*dollars = change / 100;
		change %= 100;
		
		*quarters = change / 25;
		change %= 25;
		
		*dimes = change / 10;
		change %= 10;
		
		*nickels = change / 5;
		change %= 5;
		
		*pennies = change;
	}