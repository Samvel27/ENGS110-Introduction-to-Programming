#include <stdio.h>

int main() {
	int grade; // initializing a variable for grade
	printf("The grade system looks like the following:\n\nA: 90 - 100 \nB: 80 - 89\nC: 70 - 79\nD: 60 - 69\nF: 0 - 59\n"); // Notifying the user about the grading system by outputing the corresponding information
	while (1) { // Creating an infinite loop for the user to continue inputting grades
		printf("\nPlease input your grade: ");  // Asking the user to input their grade
        	if (scanf("%d", &grade) != 1) {	// Obtaining the grade input and checking if it is actually an integer
			printf("\nError: Invalid input\n"); // if it is not an integer it results in error
			while (getchar() != '\n'); // clearing the buffer
			continue;
		}
		if (grade == -1) break; // if -1 is entered - program stops
		if (grade >= 90 && grade <= 100) printf("\nYour grade is A\n\n"); // condition for grade A
		else if (grade >= 80 && grade <= 89) printf("\nYour grade is B\n\n"); // condition for grade B
		else if (grade >= 70 && grade <= 79) printf("\nYour grade is C\n\n"); // condition for grade C
		else if (grade >= 60 && grade <= 69) printf("\nYour grade is D\n\n"); // condition for grade D
		else if (grade >= 0 && grade <= 59) printf("\nYour grade is F\n\n"); // condition for grade F
		else printf("\nThe grade is not in the range 0 - 100\n\n"); // condition for invalid input
	}
	return 0;
}
