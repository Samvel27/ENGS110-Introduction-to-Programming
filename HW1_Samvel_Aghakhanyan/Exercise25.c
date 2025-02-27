#include <stdio.h>

int main () {
        int N, M, K; // initializing N and M
        printf("Please input the size of the array: ");
        if (scanf("%d", &N) != 1) { // Obtaining N while checking the data type
                printf("\nError: Invalid input\n");
                return 0;
        }
        if (N < 1) { // size cannot be less than 1
                printf("\nError: Size cannot be less than 1\n");
                return 0;
        }

	N++; // increasing N to fit new element
	int arr[N]; // initializing the array
	
	printf("\nInput the elements of the array: ");
        for (int i = 0; i < N - 1; i++) {
                if (scanf("%d", &arr[i]) != 1) { // Obtaining array elements while checking if they are numbers
                        printf("\nError: Invalid input\n");
                        return 0;
                       }       
        }

        printf("\nPlease input the value of the new element: ");
        if (scanf("%d", &K) != 1) { // Obtaining K while checking the data type
                printf("\nError: Invalid input\n");
                return 0;
        }

        printf("\nPlease input the index where the element will be placed: (0 for beggining, %d for end, etc.) ", N - 1);
        if (scanf("%d", &M) != 1) { // Obtaining M while checking the data type
                printf("\nError: Invalid input\n");
                return 0;
        }
        if (M < 0 || M >= N) { // M cannot be negative, M cannot be greater or equal to N
                printf("\nError: The index of the element should be less than the size\n");
                return 0;
        }

	for (int i = N - 1; i >= M; i--) {
			arr[i] = arr[i - 1]; // starting from the end, shifting everything to the right up to M
	}
	arr[M] = K; // giving arr[M] the value K

        printf("\n");
        for (int i = 0; i < N; i++) printf("%d ", arr[i]); // printing the array
        printf("\n");
        return 0;
}
