#include <stdio.h>

int main() {
	int number, reverse = 0, negative = 0; // initializing number, a variable for its reverse, and a variable for noting if the number is negative
        printf("Please input an integer: "); // Asking the user to input a number
        if (scanf("%d", &number) != 1) { // Obtaining the number while checking if the input is actually an integer
        	printf("\nError: The input is not an integer\n"); // if the input is not an integer we print error
        	return 0;
        }
	if (number < 0) { // if the number is negative we change the sign, follow the same steps but output it with the correct sign (negative)
		number = -number; // changing the sign
		negative++; // noting it is negative
	}
        for (; number > 0; reverse = reverse * 10 + number % 10, number /= 10); // getting the inverse by each time taking the last digit of number and storing it in reverse
        if (negative) reverse = -reverse; // changing the sign again if the number was negative
	printf("\nThe reverse number is %d\n", reverse); // printing the reverse
        return 0;
}
