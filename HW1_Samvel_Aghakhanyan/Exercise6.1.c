#include <stdio.h>

int main() {
	int N; // initializing N
	printf("Please input a number: ");
        if (scanf("%d", &N) != 1) { // Obtaining the number N while checking if the input is actually an integer
                printf("\nError: The input is not a number\n"); // if the input is not an integer we print error
                return 0;
        }
	if (N < 2) {
		printf("\n\nThe number should be greater than 1, otherwise there are no prime numbers in the range 1 - %d\n", N); // There are no numbers less than 2 that are prime
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		int prime = 1; // we assume that each number until N is a prime by default
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				prime--; // if the number is divisible by some other, we set the prime indicator to 0
				break;
			}
		}
		if (prime) printf("%d ", i); // if the prime indicator is 1 (true), we print it
	}
	printf("\n");
	return 0;
}
