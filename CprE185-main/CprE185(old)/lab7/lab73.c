// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	
	/* PUT YOUR CODE HERE */

	int Tri = 0, Circle = 0, Xx = 0, Square = 0;
	int i = 0;
    double maxV = 0;
	double minV = 0;
    
	while(Square == 0){
        scanf("%lf, %lf, %lf, %d, %d, %d, %d", &x[i], &y[i], &z[i], &Tri, &Circle, &Xx, &Square);
        if(i > lengthofavg){
			printf(" X: %lf, Y: %lf, Z: %lf, ", x[i], y[i], z[i]);
            printf("Average X: %lf, Average Y: %lf, Average Z: %lf, ", avg(x, lengthofavg), avg(y, lengthofavg), avg(z, lengthofavg));
			
            printf("X: ");
            maxmin(x, i, &maxV, &minV);
            printf(", Y: ");
            maxmin(y, i, &maxV, &minV);
            printf(", Z: ");
            maxmin(z, i, &maxV, &minV);
            printf("\n");
			
            updatebuffer(x, i + 1, x[i]);
            updatebuffer(y, i + 1, y[i]);
            updatebuffer(z, i + 1, z[i]);
        }else{
            i++;
        }
	}

}

double avg(double buffer[], int items){
	double total = 0;
	double average = 0;
	for (int i = 0; i < items; i++) {
		total = total + buffer[i];
	}
	average = total/items;
	return average;
}

void maxmin(double array[], int items, double* max, double* min){
	*max = array[0];
	*min = array[0];
	for (int i = 0; i < items; i++) {
		if (array[i] > *max) {
			*max = array[i];
		}
		if (array[i] < *min) {
			*min = array[i];
	}
}
    printf("Max: %lf, ", *max);
    printf("Min: %lf", *min);
}
void updatebuffer(double buffer[], int length, double new_item){
	for (int i = 0; i < (length - 1); i++){
		buffer[i] = buffer[i+1];
	}
	buffer[length - 1] = new_item;
}