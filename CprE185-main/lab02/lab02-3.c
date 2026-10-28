/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Preston Gaskill																	 -
- 	Section: 3																 -
-	NetID: pgask26																     -
-	Date: 02/03/2023															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int integer_result;
    double decimal_result;
	
	//Change "%lf" to "d"
    integer_result = 77 / 5;
    printf("The value of 77/5 is %d, using integer math.\n", integer_result);

	//Added ", integer_result"
    integer_result = 2 + 3;
    printf("The value of 2+3 is %d.\n", integer_result);
	
	//Change "%d" to "lf"
    decimal_result = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf.\n", decimal_result);

    return 0;
}
