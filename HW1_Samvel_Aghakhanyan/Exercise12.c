#include <stdio.h>

int main() {
        int N; // initializing the N
        printf("Please input the length of the base of the triangle: ");
        if (scanf("%d", &N) != 1) { // Obtaining the N while checking if it is a number
                printf("\nError: Invalid input\n"); // error if it is not a number
                return 0;
        }
        if (N < 1) { // the base cannot be negative or 0
                printf("\nError: Size cannot be less than 1\n");
                return 0;
        }
        printf("\n");
        for (int i = 0; i < (N + 1) / 2; i++) { // determining the height of triangle by (N + 1)/2
		for (int m = 0; m < (N / 2 - i); m++) printf(" "); // space length is equal to N/2 - i, the height minus the row's number. We do it to center the triangle
		for (int j = 0; j < (2 * i + ((N % 2 == 0) ? 2 : 1)); j++) printf("*"); // base is equal to 2*i (row number) + 1 or 2, depending the N is an even or odd number
		printf("\n"); // going to new line (row)
	}
        printf("\n");
        return 0;
}

