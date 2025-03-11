#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define M 800
#define N 800
#define P 800
#define THREADS 4  // Number of threads

int A[M][N], B[N][P], C[M][P]; // initalizing matrices
int thread_start[THREADS], thread_end[THREADS]; // intitializing arrays for start and end row index storing

void matrix_generation() { // function for generating random matrices
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10; // assigning values to matrix A[M][N]
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = rand() % 10; // assigning values to matrix B[N][P]
        }
    }
}

void *multiplication(void *arg) { // function for parallel multiplication for each thread
    int thread_id = *(int *)arg; // obtaining thread ID
    struct timeval start, end; // variables to store time
    gettimeofday(&start, NULL); // Getting start time
    
    for (int i = thread_start[thread_id]; i < thread_end[thread_id]; i++) { // matrix multiplication for specified rows
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    gettimeofday(&end, NULL); // Getting end time
    double time = (end.tv_sec - start.tv_sec) + 
                          (end.tv_usec - start.tv_usec) / 1000000.0; // calculating the time it took to perform the multiplication
    printf("Thread %d\t rows %-3d to %-3d\t %.6f seconds\n", thread_id, thread_start[thread_id], thread_end[thread_id], time); // printing the time
    pthread_exit(NULL); // exiting thread
}

void parallel_multiplication() { // function for parallel multiplication
    pthread_t threads[THREADS]; // array of thread identifiers
    int thread_ids[THREADS]; // array of thread IDs
    int rows_per_thread = M / THREADS; // number of rows per thread

    for (int i = 0; i < THREADS; i++) { // creating threads and assigning rows
        thread_start[i] = i * rows_per_thread; // start row for thread i
        thread_end[i] = (i == THREADS - 1) ? M : (i + 1) * rows_per_thread; // end row for the thread i
        thread_ids[i] = i; // assigning thread ID
        pthread_create(&threads[i], NULL, multiplication, &thread_ids[i]); // creating thread
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL); // waiting for all threads to finish multiplication
    }
}

void sequential_multiplication() { // function for sequential multiplication
    struct timeval start, end;
    gettimeofday(&start, NULL); // Getting start time
    
    for (int i = 0; i < M; i++) { // matrix multiplication
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    gettimeofday(&end, NULL); // Getting end time
    double time = (end.tv_sec - start.tv_sec) + 
                          (end.tv_usec - start.tv_usec) / 1000000.0; // calculating the time it took to perform the multiplication
    printf("Sequential Multiplication\t%f seconds\n", time); // printfing the time
}

int main() {
    	matrix_generation(); // generating matrices with random values
    
    	printf("Sequential multiplication:\n");
    	sequential_multiplication(); // performing sequential multiplication
    
    	printf("\nParallel multiplication:\n");
    	parallel_multiplication(); // performing parallel multiplication
    
    	return 0;
}
