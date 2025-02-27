#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char string[100]; // initializing the string
	char conv; // initializing indicator for uppercase/lowercase
	printf("Please input a string: ");
	scanf("%s", string); // obtaining string
	while (getchar() != '\n'); // clearing the input buffer
	printf("\nYou want to make the string uppercase or lowercase? (u/l)\n\n");
	scanf("%c", &conv); // obtaining uppercase/lowercase indicator
	int length = strlen(string); // getting length of the string
	for (int i = 0; i < length; i++) { // for each char in the string
		if (conv == 'u') string[i] = toupper(string[i]); // converting char to uppercase
                else if (conv == 'l') string[i] = tolower(string[i]); // converting char to lowercase
		else {
			printf("\nError: Invalid input\n"); // error for any other value of conv
			return 0;
		}
	}
	printf("\n%s\n", string); // printing the string
	return 0;
}
