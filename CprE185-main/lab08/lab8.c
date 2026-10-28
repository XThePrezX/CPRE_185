// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch


// Headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define NUMCOLS 271
#define NUMROWS 81

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '


// 2D character array which the maze is mapped into
char MAZE[NUMROWS][NUMCOLS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < x_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the roll function written in previous labs.  
float calc_roll(float x_mag);



// Main - Run with './ds4rd.exe -t -g -b' piped into STDIN
int main(int argc, char* argv[])
{
	
	int x = NUMCOLS / 2;
	int y = 0;
	int time, averageX, averageY;
	double g_x, g_y, g_z;
	bool t, o, X, s;
	int prev_x = x;
	int prev_y = y;
	
	if (argc <2) { printf("You forgot the difficulty\n"); return 1;}
	int difficulty = atoi(argv[1]); // get difficulty from first command line arg
	// setup screen    
	initscr();
	refresh();

	// Generate and draw the maze, with initial avatar
	generate_maze(difficulty);
	draw_maze();
	draw_character(x, y, AVATAR); //Avatar placed and waiting
	

	// Read gyroscope data to get ready for using moving averages.    
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &time, &g_x, &g_y, &g_z, &t, &o, &X, &s);

	// Event loop
	do
	{	
		// Read data, update average
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &time, &g_x, &g_y, &g_z, &t, &o, &X, &s);
		prev_x = x;
		prev_y = y;
		
		// Is it time to move?  if so, then move avatar
		
		//Begin move?
		if(calc_roll(g_x) > 0.5){ //left move
			if (MAZE[y][x-1] != WALL && x-1 > -1){ 
				x--; //update X
			}
		} else if (calc_roll(g_x) < -0.5 && x+1 < NUMCOLS){//right move
			if (MAZE[y][x+1] != WALL){
				x++; //update X
			}
		}
			
		if (time % 100 < 10) { //Begin Fall
			if (MAZE[y + 1][x] != WALL){ //Can I fall?
				y++; //update Y
			}	else {
				if (MAZE[y][x-1] == WALL){
						if (MAZE[y][x+1] == WALL){
							
							endwin();
							printf("YOU LOSE!\n");
							return 0;
						}					
				}
			}
		}
		
		draw_character(prev_x, prev_y, EMPTY_SPACE); //Erase previous avatar
		draw_character(x, y, AVATAR); //place new avatar
		
		fflush(stdout);
		
	} while(y < NUMROWS); // Change this to end game at right time //Did I win?

	// Print the win message
	endwin();
	//Announce and exit
	printf("YOU WIN!\n");
	return 0;
}



// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//
//    >>>>DO NOT CHANGE THIS FUNCTION.<<<<
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}

// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty){
		for(int i = 0; i < NUMROWS; i++){
		
			for(int j = 0; j < NUMCOLS; j++){
			
            if(rand() % 100 < difficulty){
                MAZE[i][j] = WALL;
				
            }else{
                MAZE[i][j] = EMPTY_SPACE;
				
            }
		}
	}
}

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void){
	for(int i = 0; i < NUMROWS; i++){
		
		for(int j = 0; j < NUMCOLS; j++){
            draw_character(j, i,MAZE[i][j]);
			
		}
	}
	
	refresh();
}

// PRE: -1.0 < x_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the roll function written in previous labs.  
float calc_roll(float x_mag){
	if (x_mag < -1.0) {
		x_mag = -1.0;
	} else if (x_mag > 1.0) {
		x_mag = 1.0;
	}

  return asin(x_mag);
}