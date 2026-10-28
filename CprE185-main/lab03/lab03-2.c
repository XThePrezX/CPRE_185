/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name: Preston Gaskill																	 -
- 	Section: 3																 -
-	NetID: pgask26																     -
-	Date: 02/10/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int buttonsPressed(int triangle, int circle, int x, int square);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int triangle, circle, x, square;
	
    while (1)
    {
	scanf("%d, %d, %d, %d", &triangle, &circle, &x, &square);
	printf("%d buttons are being pressed\n", buttonsPressed(triangle, circle, x, square));
	
	fflush(stdout);
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

int buttonsPressed (int triangle, int circle, int x, int square) {
	return triangle + circle + x + square;
}