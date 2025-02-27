#include <stdio.h>
#include <string.h>

int main() {
	char num1[100], num2[100]; // initializing strings for numbers
	printf("Please input first number: ");
	scanf("%s", num1); // obtaining first number
        printf("Please input second number: ");
        scanf("%s", num2); // obtaining second number
	printf("\nThe concatenated number is %s\n", strcat(num1, num2)); // concatenating and printing them using strcat() from string.h
	return 0;
}
