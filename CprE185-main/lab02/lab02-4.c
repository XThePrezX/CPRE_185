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
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* Put your code after this line */
	int one = 6427 + 1725;
	printf("6427 + 1725 = %d\n", one);
	int two = (6971 * 3925) - 95;
	printf("(6971 * 3925) – 95 = %d\n", two);
	
	double three = 79 + 12 / 5;
	printf("79 + 12 / 5 = %.2f\n", three);
	double four = 3640.0 / 107.9;
	printf("3640.0 / 107.9 = %.2f\n", four);
	
	int five = (22 / 3) * 3;
	printf("(22 / 3) * 3 = %d\n", five);
	int six = 22 / (3 * 3);
	printf("22 / (3 * 3) = %d\n", six);
	
	double seven = 22 / (3 * 3);
	printf("22 / (3 * 3) = %.2f\n", seven);
	double eight = 22 / 3* 3;
	printf("22 / 3* 3 = %.2f\n", eight);
	double nine = (22.0 / 3) * 3.0;
	printf("(22.0 / 3) * 3.0 = %.2f\n", nine);
	
	int ten = 22.0 / (3 * 3.0);
	printf("22.0 / (3 * 3.0) = %d\n", ten);
	
	double eleven = 22.0 / 3.0 * 3.0;
	printf("22.0 / 3.0 * 3.0 = %.2f\n", eleven);
	
	//Circle circumfrence
	double circleArea = pow(23.567, 2)/(4*M_PI);
	printf("Calculate the area of a circle with circumference 23.567, %lf\n", circleArea);
	
	//Feet to meters
	double feetToMeters = 0.3048 * 14;
	printf("Convert 14 feet to meters, %lf\n", feetToMeters);
	
	//Fahrenheit to Celsius
	double fToC = (76 - 32 )/ 1.8;
	printf("Convert 76 degrees Fahrenheit to Celsius, %lf\n", fToC);

    return 0;
}
