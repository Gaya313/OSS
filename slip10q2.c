// Q.2 Write the simulation program using FCFS. The arrival time and first CPU bursts of different
// jobs should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU
// burst should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a process
struct Process {
    int id;          // Process ID
    int arrivalTime; // Arrival Time
    int burstTime;   // Burst Time
    int turnaroundTime;
    int waitingTime;
};

int main() {
    srand(time(NULL)); // Seed for random number generator

    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input arrival time and initial burst time for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter Initial Burst Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    printf("\nGantt Chart:\n");
    printf("0");
    for (int i = 0; i < n; i++) {
        printf(" --> P%d", processes[i].id);

        // Simulate I/O wait time
        currentTime += 2;

        // Calculate waiting time and turnaround time for the current process
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

        totalTurnaroundTime += processes[i].turnaroundTime;
        totalWaitingTime += processes[i].waitingTime;

        // Generate next CPU burst time for the current process (between 1 and 10 units)
        int nextBurst = rand() % 10 + 1;
        processes[i].burstTime = nextBurst;

        // Update the current time
        currentTime += processes[i].burstTime;
    }

    printf("\n\nProcess\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i].id, processes[i].turnaroundTime, processes[i].waitingTime);
    }

    double avgTurnaroundTime = (double)totalTurnaroundTime / n;
    double avgWaitingTime = (double)totalWaitingTime / n;

    printf("\nAverage Turnaround Time: %.2lf\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2lf\n", avgWaitingTime);

    return 0;
}
