#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL)); // sets the time as seed for rand
        int guess, answer = (rand() % 100) + 1; // initialization of guess and answer variable, answer is equal to a random number between 1 - 100
	int count = 0; // initializing variable for count
	while (1) {
		printf("\nGuess the number between 1 - 100!\n\n");
		if (scanf("%d", &guess) != 1) { // Obtaining the number while checking if the input is actually an integer
                	printf("\nError: The input is not a number\n"); // if the input is not an integer we print error
                	while (getchar() != '\n');
			continue;
		}
		if (guess == answer) {
			count++;
			printf("\n\nCongratulations! You have guessed the number!\nIt took you %d guesses.\n", count); // output when user wins
		        break;
		}
		else if (answer - guess > 0) {
			count++;
			printf("\n\nToo low!\n"); // if answer is greater than the guess, means users input is too low
		}
		else if (guess - answer > 0) {
			count++;
			printf("\n\nToo high!\n"); // if answer is smaller than the guess, means users input is too high
		}
	}
        return 0;
}
