#include <stdio.h>

int main() {
	int N; // initializing the N
	printf("Please input the height of the triangle: ");
	if (scanf("%d", &N) != 1) { // Obtaining the N while checking if it is a number
		printf("\nError: Invalid input\n"); // error if it is not a number
		return 0;
	}
	if (N < 1) { // the height cannot be negative or 0
		printf("\nError: Size cannot be less than 1\n");
		return 0;
	}
	printf("\n");
	for (int i = 1; i <= N; i++) { // loop for the left aligned triangle
		for (int j = i; j > 0; j--) printf("*"); // printing * correspongin to the row's number
		printf("\n"); // going to new line
	}
	for (int i = 1; i <= N; i++) { // loop for the right aligned triangle
                for (int k = (N - i); k > 0; k--) printf(" "); // first we print spaces then we go to printing * and number of spaces is equal to N - i
                for (int j = i; j > 0; j--) printf("*"); // printing * corresponding to the rowss number
                printf("\n"); // going to new line
        }
	printf("\n");
	return 0;
}
