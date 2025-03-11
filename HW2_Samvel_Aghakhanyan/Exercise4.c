#include <stdio.h>
#include <string.h>

void StringCompression(char *str) {
    	if (str == NULL || *str == '\0') { // error if string is empty or NULL pointer
        	return;  
    	}
    	int cursor = 0; // intializing a writing pointer / cursor, where we will write
	int count = 1, copy, digits; // intializing variables for counting the char, its digits and copy
	char character; // intializing a variable for reading and checking the char
    
    	for (int i = 0; i < 1024 && str[i] != '\0' ; i++) { // iterating through the string
        	count = 1; // setting count to 1
        	for (int t = i; t < 1024 && str[t] != '\0'; t++) { // searching for same characters
			character = str[i]; // reading the character
			if (str[i] == str[t + 1]) count++; // counting if the character repeats
			else {
				digits = 0; // setting digits to 0
				copy = count; // copying the count to do some math
				while (copy != 0) { // counting the number of digits
					copy /= 10;
					digits++;
				}
				for (int j = 1023; j >= digits + cursor; j--) str[j] = str[j - digits]; // shifting everything to the right
				copy = count; // copying the count again
				str[cursor] = character; // writing the character after shift
				for (int k = cursor + digits; copy != 0; k--) { // writing the compressed string
					character = '0' + (copy % 10);
					str[k] = character;
					copy /= 10;
				}
				cursor += digits + 1; // moving the cursor
				i += digits + count - 1; // going to the next different character
				break;
			}
		}
	}
    	str[cursor] = '\0'; // writing the terminating character at the end of the string
}

int main() {
    	char str[1024] = {0}; // initializing the string
    
    	printf("Enter the string to compress: ");
    	scanf("%s", str); // obtaining the string

    	printf("\nOriginal String: %s\n", str); // printing the original string

    	StringCompression(str); // calling the function

    	printf("Compressed String: %s\n", str); // printing the compressed string

    	return 0;
}
