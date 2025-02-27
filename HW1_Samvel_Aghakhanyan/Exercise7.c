#include <stdio.h>

int main() {
	int N, reverse = 0; // initializing N and variable for the reverse of N
        printf("Please input a number: ");
	if (scanf("%d", &N) != 1) { // Obtaining the number while checking if the input is actually an integer
                printf("\nError: The input is not a number\n"); // if the input is not an integer we print error
                return 0;
	}
	int copy = N; // As we will lose N while processing the reverse, it is better to store it in a copy variable and use the copy
	while (copy > 0) {
		reverse = reverse * 10 + copy % 10; // Obtaining the reverse of the N
		copy /= 10;
	}
	if (reverse == N) printf("\n\n%d is a palindrome\n", N); // if the reverse is equal to the N, then it is a palindrome
	else printf("\n\n%d is not a palindrome\n", N);
	return 0;
}
