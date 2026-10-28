/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>



/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
double mag (double inp1, double inp2, double inp3){
	double magnitude1;
	inp1 = pow (inp1,2);
	inp2 = pow (inp2,2);
	inp3 = pow (inp3,2);
	magnitude1 = sqrt(inp1+inp2+inp3);
	
	return magnitude1;
}

int close_to (double tolerance, double point, double value){
	if (value >= point - tolerance && value <= point + tolerance){
		return 1;
	} 
	else {
		return 0;
	}
}

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;


    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		
		if (b1 == 1) {
			
        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        //printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);
		
        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */
		double Tracker;
		double Accel;
		
        printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));
		
		Accel = mag(ax, ay, az);
		
			if (Accel <= 0.1 && Tracker != Accel){
		if(close_to(0.5, 0.5, gx) == 1){
		printf("LEFT, ");
		}
		else {
		printf("RIGHT, ");
		}
		
		if(close_to(0.5, 0.5, gy) == 1){
		printf("TOP, ");
		}
		else {
		printf("BOTTOM, ");
		}
		
		if(close_to(0.5, 0.5, gz) == 1){
		printf("BACK\n");
		}
		else {
		printf("FRONT\n");
		}
		
		}
		}
    }
	
    return 0;
}

/* Put your functions here */
