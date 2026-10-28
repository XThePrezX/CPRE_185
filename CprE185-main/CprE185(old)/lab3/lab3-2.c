/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */

int buttonsPressed (b1,b2,b3,b4) {
		int buttons = 0;
		if (b1 == 1) {
			buttons = buttons + 1;
		}
		if (b2 == 1) {
			buttons = buttons + 1;
		}
		if (b3 == 1) {
			buttons = buttons + 1;
		}
		if (b4 == 1) {
			buttons = buttons + 1;
		}
		return buttons;
	}

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int tri, circ, cros, squar;     


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%d,%d,%d", &tri, &circ, &cros, &squar); 
	int ButtonsS = buttonsPressed (tri, circ, cros, squar);
	printf("%d \n", ButtonsS);
	
	fflush(stdout);
    }

return 0;
}

/* Put your functions here */


