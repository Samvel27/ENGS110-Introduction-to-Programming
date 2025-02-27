#include <stdio.h>

int main() {
	int numbers[10], min, max; // initializing min and max for minimum and maximum values, and an array numbers[] for storing the numbers inputted by the user
	printf("Please input 10 numbers: "); // ASking the user to input 10 numbers
	for (int i = 0; i < 10; i++) {
		if (scanf("%d", &numbers[i]) != 1) { // Obtaining the numbers while checking if the inputs are actually numbers
                	printf("\nError: Invalid input\n"); // if the input is not a number we print error
                	return 0;
		}
	}
	min = max = numbers[0]; // giving min and max a value of the first number
	for (int i = 1; i < 10; i++) { // comparing min and max with other numbers
                if (numbers[i] < min) min = numbers[i]; // if any number in the array is less than the minimum, the minimum should obtain its value
                if (numbers[i] > max) max = numbers[i]; // if any number in the array is greater than the maximum, the maximum should obtain its value
        }
	printf("\nMaximum number is %d\n", max); // printing the maximum number
	printf("Minimum number is %d\n", min); // printing the minimum number
	return 0;
}
