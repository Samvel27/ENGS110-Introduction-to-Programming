#include <stdio.h>

int main() {
	int number, sum = 0; // initializing the variable for number and sum
	printf("Please input an integer number: "); // Asking user to input an integer (number)
	if (scanf("%d", &number) != 1) { // Obtaining the number while checking if the input is actually an integer
                printf("\nError: The input is not an integer\n"); // if the input is not an integer we print error
                return 0;
	}
	if (number < 0) {
		number = number * -1; // if the number is negative, we reverse the sign to count the digits sum correctly
	}	
	while (number > 0) {
		sum += number % 10; // checks the remainder after dividing the number by 10 (obtains the last digit and adds to sum)
		number /= 10; // divides the number by 10 to get the next digit in the next iteration
	}
	printf("\nThe sum of its digits is: %d\n", sum); // outputs the sum of digits
	return 0;
}
