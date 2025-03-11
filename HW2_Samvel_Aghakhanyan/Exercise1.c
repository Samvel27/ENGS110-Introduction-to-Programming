#include <stdio.h>

#define FILE_NAME "Exercise1.c"

int main() {
	printf("\n");
	FILE *file = fopen(FILE_NAME, "r"); // pointer to read the file
    	if (!file) { // Error if the file doesn't exist
        	perror("Error opening file");
        	return 1;
    	}

    	int ch, row = 1, column = 0; // initializing variables for row, column and reading character
    	while ((ch = fgetc(file)) != EOF) { // while the file hasn't ended 
        	column++; // going through each column and checking
        	if (ch == '{' || ch == '}') printf("Row: %d\t Column: %2d\tdetected symbol: %c\n", row, column, ch); // if { or } is detected, print its position
        	if (ch == '\n') { // if reached end of the line, go to the next line
			row++; 
			column = 0; 
		}
    	}

    	fclose(file); // closing the file
	printf("\n");
	return 0;
    }
