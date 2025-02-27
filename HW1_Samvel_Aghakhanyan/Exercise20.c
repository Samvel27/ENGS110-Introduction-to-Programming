#include <stdio.h>

int main() {
	int N; // initializing a variable for the sequence size
	printf("Please enter the number of elements in the sequence: "); // asking user to input the size of the sequence
	if (scanf("%d", &N) != 1) { // Obtaining the number while checking if the input is actually an integer
                printf("\nError: The input is not a number\n"); // if the input is not an integer we print error
                return 0;
	}
        if (N < 1) { // the size of an array cannot be less than 1 so we print error in case N is less than 1
                printf("\nError: The size cannot be less than 1\n");
                return 0;
        }
	int numbers[N]; // creating an array with that size
	printf("\nInput the elements of the sequence: ");
	for (int i = 0; i < N; i++) {
		if (scanf("%d", &numbers[i]) != 1) { // Obtaining the numbers putting the scanf in a loop to obtain the elements of the array while checking if the input is actually an integer
                	printf("\nError: Invalid input\n"); // if the input is not an integer we print error
                	return 0;
		}
	}
	printf("\n");
	for (int i = (N - 1); i >= 0; i--) {
		printf("%d ", numbers[i]); // printing the array (sequence) in reverse order, starting i from the end of array
	}
	printf("\n");
	return 0;
}
