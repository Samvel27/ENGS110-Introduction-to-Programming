#include <stdio.h>

int main() {
	int N, sum = 0; // intializing a variable for size of the sequence(N) and sum of its elements
	printf("Please input the size of the sequence: ");
	if (scanf("%d", &N) != 1) { // obtaining N and checking if the input is actually a number
		printf("\nError: Invalid input\n"); // if the input is not a number we print error
		return 0;
	}
        if (N < 1) { // the size of an array cannot be less than 1 so we print error in case N is less than 1
                printf("\nError: The size cannot be less than 1\n");
                return 0;
        }
	int numbers[N]; // initializing an array with size N
	printf("\nInput the sequence elements: ");
	for (int i = 0; i < N; i++) {
		if (scanf("%d", &numbers[i]) != 1) { // obtaining the elements of the sequence while checking if they are numbers
                	printf("\nError: Invalid input\n"); // if at least one of the elements is not a number it result in an error
                	return 0;
        	}
		sum += numbers[i]; // summing all the elements of the sequence
	}
	printf("\nThe sum of the elements of the sequence is  %d\n", sum); // printing the sum
	return 0;
}
