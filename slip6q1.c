// Q.1 Write a program to find the execution time taken for execution of a given set of instructions
// (use clock() function

#include <stdio.h>
#include <time.h>

int main() {
    // Record the start time
    clock_t start_time = clock();

    // Perform your set of instructions here
    for (int i = 0; i < 1000000; i++) {
        // Your instructions here
    }

    // Record the end time
    clock_t end_time = clock();

    // Calculate the execution time in seconds
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Execution time: %lf seconds\n", execution_time);

    return 0;
}
