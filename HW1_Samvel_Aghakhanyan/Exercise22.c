#include <stdio.h>

int main() {
        int N, ascending = 1, descending = 1; // initializing N and flags for ascending/descending
        printf("Please input the size of the sequence: ");
        if (scanf("%d", &N) != 1) { // Obtaining the N while checking if the input is a number
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
                if (scanf("%d", &numbers[i]) != 1) { // obtaining the elements of the array and checking if they are numbers
                        printf("\nError: Invalid input\n"); // if the input contains something that is not a number we print error
                        return 0;
                }
        }
	for (int i = 1; i < N; i++) {
		if (numbers[i - 1] < numbers[i]) { // checking for the whole array if the numbers are in descending order
			descending = 0; // if they are not in descending order we change indicator value to 0
			break;
		}
	}
        for (int i = 1; i < N; i++) {
                if (numbers[i - 1] > numbers[i]) { // checking for the whole array if the numbers are in descending order
                        ascending = 0; // if they are not in ascending order we change indicator value to 0
                        break;
                }
        }
	if (ascending || descending) printf("\nYes\n"); // if the sequence is in ascending or descending order we print "yes"
	else printf("\nThe order in the sequence is chaotic\n"); // else we say that there is no order
	return 0;
}

