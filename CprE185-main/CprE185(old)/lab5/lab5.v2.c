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

/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/

double mag (double inp1, double inp2, double inp3);

int close_to (double tolerance, double point, double value);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
	
    double ax, ay, az;
	
	int t;
	int line1 = 0;
	int line2 = 0;
	
	double Position;
	
	int x = 0;
	int StartTime = 0;
	
	const double x0 = 0;
	int vi = 0;
	double EndingPosition = 0;
	double EndingTime = 0;
	double Currentmag = 0;
	const double g = 9.8;
	
	
   printf("Preston Gaskill\n");
	printf("pgask26\n");
	
	printf("Ok, I'm now receiving data.\n");
	
	while (0.30 > (mag(ax, ay, az))) {
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		
		
		Currentmag = mag(ax,ay,az);
		x0 = 0; 
		
		if (0.30 > Currentmag) {
			
			line1++;
			
			if (line1 == 10) {
				printf("I'm waiting ..............\n");
				line1 = 0;
			}
			
		}
		
		
		if (0.30 <= Currentmag) {
			
			if (x != 1) {
			StartTime = t;
			x++;
		}
		
			while (0.30 <= Currentmag) {
				
				line2++;
			
				if (line2 == 10) {
					printf("	Help me! I'm falling!!!!!!!!!!!!!\n");
					line2 = 0;
				}
				
				scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
				
				Currentmag = mag(ax,ay,az);
			}
			EndingTime = t;
			break;
		}
		
		fflush(stdout);
		
	}
	
	EndingTime = (EndingTime - StartTime) / 1000;
	
	EndingPosition = (x0 + (vi * EndingTime) + (0.5) * (g * (EndingTime*EndingTime)));
	
	vel2 = vi + (g)*(1 - Currentmag)*(EndingTime);
			
	pos2 = 0 + vel2*(EndingTime);
	
	printf("		Ouch! I fell %lf meters in %lf seconds.", EndingPosition, EndingTime);
	
	printf("Compensating for air resistance, the fall was %lf meters.\n", pos2);
				
	printf("this is %1.0lf%% less than computed before.", ((((pos2/EndingPosition)*100)-100));
	
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