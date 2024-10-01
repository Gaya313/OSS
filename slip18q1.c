// Q. 1 Write a C program to accept the number of process and resources and find the need matrix
// content and display it.

#include <stdio.h>

int main() {
    int num_processes, num_resources;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    int maximum[num_processes][num_resources];
    int allocation[num_processes][num_resources];
    int need[num_processes][num_resources];

    // Input the maximum allocation matrix
    printf("Enter the Maximum Allocation Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    // Input the allocation matrix
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Calculate and display the need matrix
    printf("Need Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}
