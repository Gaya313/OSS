// Q.2 Write the program to simulate Non-preemptive Priority scheduling. The arrival time and first 
// CPU burst and priority for different n number of processes should be input to the algorithm.
// Assume the fixed IO waiting time (2 units). The next CPU-burst should be generated randomly.
// The output should give Gantt chart, turnaround time and waiting time for each process. Also find
// the average waiting time and turnaround time..

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process {
    int id;
    int arrivalTime;
    int initialCpuBurst;
    int remainingCpuBurst;
    int priority;
    int turnaroundTime;
    int waitingTime;
};

// Function to sort processes by priority (lowest priority first)
void sortByPriority(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input arrival times, initial CPU burst times, and priorities
    for (int i = 0; i < n; i++) {
        processes[i].id = i;
        printf("Enter arrival time for process P%d: ", i);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter initial CPU burst for process P%d: ", i);
        scanf("%d", &processes[i].initialCpuBurst);
        printf("Enter priority for process P%d: ", i);
        scanf("%d", &processes[i].priority);
        processes[i].remainingCpuBurst = processes[i].initialCpuBurst;
    }

    sortByPriority(processes, n);

    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    printf("\nGantt Chart:\n");
    printf("0 "); // Print the initial time

    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime > currentTime) {
            currentTime = processes[i].arrivalTime;
        }

        // Execute the process
        printf("| P%d ", processes[i].id);

        // Calculate waiting and turnaround times
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        totalWaitingTime += processes[i].waitingTime;

        // Simulate next CPU burst with random time between 1 and 5 units
        int randomBurst = (rand() % 5) + 1;
        processes[i].remainingCpuBurst -= randomBurst;
        currentTime += randomBurst;

        processes[i].turnaroundTime = currentTime - processes[i].arrivalTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("|\n");

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", i, processes[i].turnaroundTime, processes[i].waitingTime);
    }

    float averageTurnaroundTime = (float)totalTurnaroundTime / n;
    float averageWaitingTime = (float)totalWaitingTime / n;

    printf("\nAverage Turnaround Time: %.2f\n", averageTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);

    return 0;
}
