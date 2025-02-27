#include <stdio.h>

int main() {
        int N, M; // initializing the lengths of two sides of the rectangle
	char S; // character initialization
        printf("Please input the lengths of the rectangle sides and the symbol program will use to draw: ");
        if (scanf("%d %d %c", &N, &M, &S) != 3) { // obtaining the variable values and checking if their data types are correct
                printf("\nError: Invalid input\n"); // if the input contains improper data types we print error
                return 0;
        }
	if (N < 1 || M < 1) { // side of a rectangle cannot be negative or 0
		printf("\nError: Size cannot be less than 1\n");
		return 0;
	}
        printf("\n");
        for (int i = 1; i <= N; i++) { // loop for "rows" (number of rows are the value stored in N
                if (i == 1 || i == N) { // in the first and last row we need to print full line with S
                        for (int j = 1; j<= M; j++) printf("%c", S); // printing full line with S, the length is M
                        printf("\n"); // going to the next "row", so we go to new line
                        continue;
                }
                for (int k = 1; k <= M; k++) { // else we should print S only at the start and at the end of the row
                        if (k == 1 || k == M) { // if it is a start of the row or the end we print S
                                printf("%c", S);
                                continue; // going to the right, to next cell
                        }
                        printf(" "); // if it is not we print empty space
                }
                printf("\n"); // goint to new row (new line)
        }
        printf("\n");
        return 0;
}

