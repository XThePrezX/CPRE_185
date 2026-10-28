/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/
#define TRUE 1
#define FALSE 0
#define g 9.8
#define StartingPosition 0
/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/

double mag (double inp1, double inp2, double inp3);

int close_to (double tolerance, double point, double value);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
	
    double ax = 0.000000;
	double ay = 0.000000;
	double az = 0.000000;
	
	int t = 0;
	int line1 = 0;
	int line2 = 0;
	
	int x = 0;
	int StartTime = 0;
	
	double EndingPosition = 0;
	double EndingTime = 0;
	double Currentmag = 0.000000;
	
	
   printf("Preston Gaskill\n");
	printf("pgask26\n");
	
	printf("Ok, I'm now receiving data.\n");
	
	scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
	Currentmag = mag(ax, ay, az);
	
	
	while (1.050000 > Currentmag) {
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		
		Currentmag = mag(ax, ay, az);
		
		if (1.050000 > Currentmag) {
			
			line1++;
			
			if (line1 == 10) {
				printf("I'm waiting ..............\n");
				line1 = 0;
			}
			
		}
		
		fflush(stdout);
	}
	
			
	StartTime = t;
			
	while (1.050000 <= Currentmag) {
			scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		
			Currentmag = mag(ax, ay, az);
		
			if (1.050000 <= Currentmag) {
			
				line1++;
			
				if (line1 == 10) {
					printf("	Help me! I'm falling!!!!!!!!!!!!!\n");
					line1 = 0;
				}
			
		}
		
		fflush(stdout);
	}
	
	EndingTime = t;
	
	
	
	EndingTime = (EndingTime - StartTime) / 1000;
	
	EndingPosition = (StartingPosition + (0.5) * g * (EndingTime*EndingTime));
	
	
	printf("		Ouch! I fell %lf meters in %lf seconds.", EndingPosition, EndingTime);
	
	
    return 0;
	}
	
	
/* Put your functions here */

double mag (double inp1, double inp2, double inp3){
	double magnitude1;
	inp1 = pow (inp1,2);
	inp2 = pow (inp2,2);
	inp3 = pow (inp3,2);
	magnitude1 = sqrt(inp1+inp2+inp3);
	
	return magnitude1;
}

int close_to (double tolerance, double point, double value){
	if (value >= (point - tolerance) && value <= (point + tolerance)){
		return 1;
	} 
	else {
		return 0;
	}
}