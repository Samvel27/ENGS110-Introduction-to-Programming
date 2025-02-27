#include <stdio.h>

int main() {
	int count[10] = {0}, num; // initializing a counter for number frequencies and a number
	printf("Please input number between 1 - 10\n(enter -1 to quit)\n\n");
	while (1) {
		if (scanf("%d", &num) != 1) { // obtaining number
			printf("\nError: Invalid input\n\n");
			while (getchar() != '\n');
			continue;
		}
		if (num == -1) break; // if input is -1 the loop ends
		if (num > 10 || num < 1) { // notification that the number is out of the range
			printf("\nThe number should be between 1 and 10\n\n");
			continue;
		}
		count[num - 1]++; // incrementing corresponding value of counter
	}

	printf("\nNumber frequencies:\n\n");
	for (int i = 0; i < 10; i++) printf("%d: %d\n", i + 1, count[i]); // printing number frequencies
	printf("\n");
	return 0;
}
