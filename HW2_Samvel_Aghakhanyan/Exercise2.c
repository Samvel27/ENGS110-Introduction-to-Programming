#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024 // maximum line length

void search_csv(const char *filename, int column, const char *search_value) {
    	FILE *file = fopen(filename, "r"); // pointer to read the file
    	if (!file) { // error if the file doesn't exist
        	perror("Error opening file");
        	return;
    	}

    	char line[MAX_LINE]; // variable for storing the line 
    	int header = 1; // flag for header row
    	int match = 0;  // flag for search match
	printf("\nSearching for matches...\n");

    	while (fgets(line, MAX_LINE, file)) { // read a line (row) from file and storing it in array line[]
        	if (header) { // skipping the header row
            		header = 0;
            		continue;
        	}

        	int col_index = 1, end = 0; // variables for column and end of a string
        	char value[MAX_LINE]; // variable to store the string in the column
		
        	for (int i = 0; line[i] != '\0'; i++) { // iterating through all characters
            		if (line[i] == ',' || line[i] == '\n') { // comma or newline means entering new column
                		value[end] = '\0'; // setting the end of the string
                		if ((col_index == column)) { // if the column index is the same as user's input we proceed
                        		if (strcmp(value, search_value) == 0) { // comparing the value in the column with the value we are searching for
						printf("%s", line); // if they match, we print the whole line
                        			match = 1; // indicating that there is at least 1 match
                        			break;
					}
                		}
                	col_index++; // going to next column
                	end = 0; // clearing the value[]
            		} else value[end++] = line[i]; // oing o next character and storing the string in value[]
        	}
	}
	if (!match) { // notifying that there is no match
		printf("\nNo matches found\n");
        }
	printf("\n");
	fclose(file); // closing the file
}

int main() {
    	char filename[100], search_value[100]; // arrays for storing the filename and search value
    	int column; // variable for column input

    	printf("Enter CSV file name: ");
    	scanf("%s", filename); // obtaining the filename
    
    	printf("Enter column number: ");
    	if (scanf("%d", &column) != 1) { // obtaining column number while checking the data type
    		printf("Error: Invalid input");
		return 0;
    	}
    
    	if (column < 1) { // column number cannot be smaller than 1
        	printf("Error: Invalid column number!\n");
        	return 0;
    	}

    	printf("Enter search value: ");
    	scanf("%s", search_value); // obtaining value to search for

    	search_csv(filename, column, search_value); // calling the function
    
	return 0;
}

