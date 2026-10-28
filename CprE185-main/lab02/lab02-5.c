/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Preston Gaskill																	 -
- 	Section: 3																 -
-	NetID: pgask26																     -
-	Date: 02/03/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
    double filler;

    /* Put your code after this line */
	printf("Enter a value for A,\n");
	scanf("%lf", &a);
	printf("Enter a value for B,\n");
	scanf("%lf", &b);
	c = pow(a,2) + pow(b,2);

    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt(c);
	
	printf("%lf", filler);

    return 0;
}
