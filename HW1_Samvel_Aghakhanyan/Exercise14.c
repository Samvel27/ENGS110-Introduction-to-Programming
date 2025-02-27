#include <stdio.h>
#include <string.h>

int main() {
	char ready[4]; // initializing a string to check user's readiness
        char hint[8]; // initializing a hint string for user's feedback
	int high = 100, low = 1; // variables that indicate limits for binary search
	int guess = (high - low)/2; // so called "mid" in the binary search, which our program will use as its guess
	printf("Think of a number between 1 and 100 and I will guess it\n");
	while (1) {
		printf("Ready to start the game? (yes/no)\n\n"); // Asking about the readiness
		scanf("%s", ready);
		if (strcmp(ready , "yes") == 0) { // by strcmp() we compare the user's inputted string, if it indicates that user is ready, the game starts
			while (1) {
				printf("\nI think the number is... %d\nPlease tell me if my guess is high, low or correct. (high/low/correct)\n\n", guess); // Asking the user to say if the guess is low, high or correct
				scanf("%s", hint); // Obtaining the hint input of the user
				if (strcmp(hint, "high") == 0) {
					high = guess - 1; // setting new upper bound for binary search, based on user's input which was "high"
					guess = low + (high - low)/2; // calculating new "mid" and again passing it as a guess, thus, narrowing the search
				}
				else if (strcmp(hint, "low") == 0) {
					low = guess + 1; // setting new lower bound for binary search, based on user's input which was "low"
                                        guess = low + (high - low)/2; // calculating new "mid" (guess)
				}
                                else if (strcmp(hint, "correct") == 0) {
                                	printf("\nHAHAHHAHAHAAHHA, I WON!\n"); // output if the guess was correct and the program won the game
					return 0;
                                }
				else printf("\nInvalid input\n"); // any input other than "high", "low", "correct" is invalid
			}
		}
		else if (strcmp(ready , "no") == 0) printf("\nAlright, think.\n"); // if the user is not ready
		else printf("\nInvalid input\n"); // any input other than "yes" or "no" is invalid
	}
}
