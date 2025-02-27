#include <stdio.h>

int main() {
	int N, sum = 0; // initializing N and variable for storing the sum
	printf("Please input a number N in range 1 - 10000: "); // Asking the user to input N
	scanf("%d", &N); // Obtaining N
	if (N >= 1 && N <= 10000) { // checking if N is in correct range
		for (int i = 1; i < N; i++) { // loop counting until N
			if (i % 3 == 0 || i % 5 == 0) sum += i; // checking if the number is multiple of 3 or 5 and adding it to sum variable
		}
		printf("\nThe sum of the multiples of 3 or 5 below N is: %d\n", sum); // outputing the result
	} else printf("\nThe number is not in the correct range!\n"); // output for invalid N
	return 0;
}
