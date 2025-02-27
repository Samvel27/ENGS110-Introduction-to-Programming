#include <stdio.h>

int main() {
	int nm[2]; // initializing an array for obtaining the lengths of two sides of the rectangle
        printf("Please input the lengths of the rectangle sides: ");
        for (int i = 0; i < 2; i++) {
                if (scanf("%d", &nm[i]) != 1) { // obtaining the elements of the array and checking if they are numbers
                        printf("\nError: Invalid input\n"); // if the input contains something that is not a number we print error
                        return 0;
                }
        }
	if (nm[0] < 1 || nm[1] < 1) { // Side of a rectangle cannot be 0 or negative
		printf("\nError: Size cannot be less than 1\n");
		return 0;
	}
	printf("\n"); 
	for (int i = 1; i <= nm[0]; i++) { // loop for "rows" (number of rows are the value stored in nm[0])
		if (i == 1 || i == nm[0]) { // in the first and last row we need to print full line with *
			for (int j = 1; j<= nm[1]; j++) printf("*"); // printing full line with *, the length is nm[1]
			printf("\n"); // going to the next "row", so we go to new line
			continue;
                }
		for (int k = 1; k <= nm[1]; k++) { // else we should print * only at the start and at the end of the row
			if (k == 1 || k == nm[1]) { // if it is a start of the row or the end we print *
				printf("*");
				continue; // goin to the right, to next cell
			}
			printf(" "); // if it is not we print empty space
		}
		printf("\n"); // goint to new row (new line)
	}
        printf("\n");
        return 0;
}
