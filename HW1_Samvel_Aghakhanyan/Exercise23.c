#include <stdio.h>

int main() {
        int N; // initializing N (size)
        char order; // initializing a variable for indicating the order
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
	while (getchar() != '\n'); // clearing input buffer

	printf("\nYou want the sequence to be sorted in ascending or descending order? (a/d)\n\n");
	scanf("%c", &order); // obtaining information about the required sorting order
	if (order != 'a' && order != 'd') {
		printf("\nError: Invalid input\n"); // error if the input is other than a or d
		return 0;
	}
	printf("\n");

	for (int i = 0; i < N - 1; i++) { // bubble sort algorithm
		int swapped = 0; // assuming no swap happened
		for (int j = 0; j < (N - i - 1); j++) {
			if ((order == 'a' && numbers[j] > numbers[j + 1]) || (order == 'd' && numbers[j] < numbers[j + 1])) { // cases for ascending and descending orders that would require the elements to be swapped
				numbers[j] = numbers[j] ^ numbers[j+1]; // swapping numbers using XOR
				numbers[j + 1] = numbers[j] ^ numbers[j+1];
				numbers[j] = numbers[j] ^ numbers[j+1];
				swapped = 1; // swap happening indicator
			}
		}
		if (!swapped) break; // if no swap happened, the array is sorted and we can leave the loop
	}

        for (int i = 0; i < N; i++) printf("%d ", numbers[i]); // printing the sorted array
	printf("\n");
        return 0;
}
