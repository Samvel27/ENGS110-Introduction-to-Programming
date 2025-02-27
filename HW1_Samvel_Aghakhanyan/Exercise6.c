#include <stdio.h>

int main() {
	int N; // initializing the number N
	printf("Please input a number: ");
	if (scanf("%d", &N) != 1) { // Obtaining the number N while checking if the input is actually an integer
                printf("\nError: The input is not a number\n"); // if the input is not an integer we print error
                return 0;
	}
	if (N < 2) {
		printf("\n\n%d is not a prime number\n", N); // numbers 0, 1 and negative numbers are not prime
		return 0;
	}
	for (int i = 2; i <= N/2; i++) { // we increase i till N/2 as N cannot have a factor greater than N/2
		if (N % i == 0) {
			printf("\n\n%d is not a prime number\n", N); // if a number is divisible by any number other than 1 and itself, then the function ends and prints that the N is not prime
                	return 0;
		}
	}
	printf("\n\n%d is a prime number\n", N); // if the function haven't breaked till this point, then N is prime
	return 0;
}
