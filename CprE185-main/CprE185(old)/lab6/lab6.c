// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589
#define TRUE 1
#define FALSE 0

//NO GLOBAL VARIABLES ALLOWED
//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when the square button is pressed
//  False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);

// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);


int main()
{
	double x, y, z;                             // magnitude values of x, y, and z
	int b_Triangle, b_X, b_Square, b_Circle;    // variables to hold the button statuses
	double roll_rad, pitch_rad;                 // value of the roll measured in radians
	int scaled_value;                           // value of the roll adjusted to fit screen display

	//insert any beginning needed code here
	int RollorPitch = 0;
	int time = 0;
	
  
	do
	{
		// Get line of input
      //read_line(&x, &y, &z, &time, &b_Triangle, &b_X, &b_Square, &b_Circle);
	  
	  scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d\n", &x, &y, &z, &time, &b_Triangle, &b_X, &b_Square, &b_Circle);
	  
	  
		// calculate roll and pitch.  Use the buttons to set the condition for roll and pitch
	if (RollorPitch == 0){
		roll_rad = roll(x);
	} else {
        pitch_rad = pitch(y);
	}
		
		// switch between roll and pitch(up vs. down button)

	if (b_Triangle != 0) {	
			RollorPitch = 0;
	}
	if (b_X != 0) {	
			RollorPitch = 1;
	}
	
    
		// Scale your output value

    if (RollorPitch == 0) {
        scaled_value = scaleRadsForScreen(roll_rad);
        } else {
            scaled_value = scaleRadsForScreen(pitch_rad);
        }
    
    
		// Output your graph line
    graph_line(scaled_value);

		fflush(stdout);
	} while (b_Square == 0); // Modify to stop when the square button is pressed
	return 0;
}


int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C){
scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d", &*g_x, &*g_y, &*g_z, &*time, &*Button_T, &*Button_X, &*Button_S, &*Button_C);
  if (*Button_S == 1){
    return 1;
  } else {
    return 0;
  }
}
 

double roll(double x_mag){
  if (-1.0 >= x_mag) {
    x_mag = -1.0;
  } else if (x_mag >= 1.0) {
    x_mag = 1.0;
  }

  return asin(x_mag);
}
  

double pitch(double y_mag){
  if (-1.0 >= y_mag) {
    y_mag = -1.0;
  }
  if (y_mag >= 1.0) {
    y_mag = 1.0;
  }

  return asin(y_mag);
}



int scaleRadsForScreen(double rad){
  return (rad*39) / (PI/2);
}


void print_chars(int num, char use) {
	if(num == 0){
		printf("%40c\n", use);
	}else if(num > 0){
		printf("%40c", use);
		for(int i = 0; i < num - 1; ++i){
			printf("%c", use);
		}
		printf("\n");
	}else{
        if(num == -1){
            printf("%40c", use);
        }else{
			int col = 41 + num;
			printf("%*c", col, use);
            for(int j = col; j < 40; ++j){
				printf("%c", use);
			}
		}
		printf("\n");
	}
}

void graph_line(int number){
	if (number < 0){
		print_chars((number), 'L');
	}
	else if (number > 0){
		print_chars((number), 'R');
	}
	else if (number == 0){
		print_chars(0, '0');
	}
	}