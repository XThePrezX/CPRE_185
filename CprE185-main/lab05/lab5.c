/*-----------------------------------------------------------------------------
-					          SE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Preston Gaskill
- 	Section: 3
-	NetID: pgask26
-	Date: 02/24/2023
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/
#define TRUE 1


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
double mag(double x, double y, double z);
int close_to (double tolerance, double point, double value);
void whatSide (double ax, double ay, double az, double gx, double gy, double gz);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
//Global variable
int lastInput = 0;
int input;

int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;


    while (TRUE) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        //printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

        //printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));
		
		whatSide(ax, ay, az, gx, gy, gz);
		
		lastInput = input;
		
		if (b1 == 1) {
		return 0;
		}
    }

    return 0;
}

/* Put your functions here */
/**
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double mag(double x, double y, double z) {
    // Step 8, uncomment and modify the next line
	double magnitude, inp1, inp2, inp3;
	
	inp1 = pow (x,2);
	inp2 = pow (y,2);
	inp3 = pow (z,2);
	magnitude = sqrt(inp1+inp2+inp3);
	
	return magnitude;
}

//close_to function
int close_to (double tolerance, double point, double value) {
	if ((value >= point - tolerance) && (value <= point + tolerance)) {
		return 1;
	} 
	else {
		return 0;
	}
}

//Display facing sides
void whatSide (double ax, double ay, double az, double gx, double gy, double gz) {
 
double Acceleration = mag(ax, ay, az);
		
	if (Acceleration <= 0.75){
		
		if (fabs(gx) > fabs(gy) && fabs(gz)) {
			
			if(close_to(0.5, 0.5, gx) == 1.0) {
				input = 1;
				if (lastInput != input) {
				printf("RIGHT\n");
				}
				
			} else {
				input = 2;
				if (lastInput != input) {
				printf("LEFT\n");
				}
				
			}
		} else if (fabs(gz) > fabs(gy) && fabs(gx)) {
			
			if(close_to(0.5, 0.5, gz) == 1.0) {
				input = 4;
				if (lastInput != input) {
				printf("BOTTOM\n");
				}
				
			} else {
				input = 3;
				if (lastInput != input) {
				printf("TOP\n");
				}
				
			}
		
		} else if (fabs(gy) > fabs(gx) && fabs(gz)) {
			
			if(close_to(0.5, 0.5, gy) == 1.0) {
				input = 5;
				if (lastInput != input) {
				printf("FRONT\n");
				}
				
			} else {
				input = 6;
				if (lastInput != input) {
				printf("BACK\n");
				}
				
			}		
		}
	}
}