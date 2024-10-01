// Q.1 Write a program to find the execution time taken for execution of a given set of instructions
// (use clock() function

#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Get the start time

    // Your set of instructions goes here
    for (int i = 0; i < 1000000; i++) {
        // Perform some computations or tasks
    }

    end = clock(); // Get the end time

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}
