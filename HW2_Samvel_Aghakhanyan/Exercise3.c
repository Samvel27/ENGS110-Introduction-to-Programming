#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    	if (str == NULL || *str == '\0') { // checking for NULL pointer or empty string
        	return;
    	}

    	char *start = str; // pointer to the start of the string
    	char *end = str + strlen(str) - 1; // pointer to the last character of the string

    	while (start < end) { // iterating through half of the string and swapping the characters using XOR
        	*start = *start ^ *end;
       		*end = *start ^ *end;
        	*start = *start ^ *end;
        	start++;
        	end--; // going to next characters to swap
    	}
}

int main() {
	int N; // initializing N for size
	printf("PLease input the length of the string: ");
	if (scanf("%d", &N) != 1 || N < 1) { // obtaining size while checking if it is valid
		printf("Error: Invalid input\n");
		return 0;
	}

    	char str[N+1]; // intializing string
	
	printf("Please input the string: ");
	getchar(); // clearing buffer
   	fgets(str, N+1, stdin); // reading the input

   	printf("\nOriginal String: %s\n", str); // printing the original string
    
    	reverseString(str); // calling the function

	printf("Reversed String: %s\n", str); // printing the reversed string
    
    	return 0;
}
