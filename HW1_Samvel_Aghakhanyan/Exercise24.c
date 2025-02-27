#include <stdio.h>

int main () {
	int N, M; // initializing N and M
	printf("Please input the size of the array: ");
	if (scanf("%d", &N) != 1) { // Obtaining N while checking the data type
		printf("\nError: Invalid input\n");
		return 0;
	}
	if (N < 1) { // size cannot be less than 1
		printf("\nError: Size cannot be less than 1\n");
		return 0;
	}

	int num[N]; // initializing the array

        printf("Please input the index of the element to be deleted: ");
        if (scanf("%d", &M) != 1) { // Obtaining M while checking the data type
                printf("\nError: Invalid input\n");
                return 0;
        }
        if (M < 0 || M >= N) { // M cannot be negative, M cannot be greater or equal to N
                printf("\nError: The index of the element should be less than the size\n");
                return 0;
        }

	for (int i = 0; i < N; i++) {
		if (scanf("%d", &num[i]) != 1) { // Obtaining array elements while checking if they are numbers
			printf("\nError: Invalid input\n");
			return 0;
		}
	}

	for (int i = M; i < N - 1; i++) {
		num[i] = num[i + 1]; // shifting array elements to the left
	}
	N--; // logically decreasing size of the array
	
	printf("\n");
	for (int i = 0; i < N; i++) printf("%d ", num[i]); // printing the array
	printf("\n");
	return 0;
}
