#include <stdio.h>

int main() {
	int number; // initializing number
	printf("Please input a number: ");
	if (scanf("%d", &number) != 1) { // Obtaining the number while checking if the input is actually an integer
                printf("\nError: The input is not a number\n"); // if the input is not an integer we print error
                return 0;
	}
	if (number <= 0) {
		printf("\n%d is not a power of 2\n", number); // negative numbers and 0 cannot be a power of 2
	} else if ((number & (number - 1)) == 0) { /* using bitwise operation to check if number is a power of 2. As powers of 2 are represented with onle one 1, we can & them with the preceding number, which is consistent of only 1's and check*/
		printf("\n%d is a power of 2\n", number);
	} else printf("\n%d is not a power of 2\n", number);
	return 0;
}
