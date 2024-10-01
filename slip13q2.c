// or Write the simulation program using SJF(non-preemptive). The arrival time and first CPU bursts of
// different jobsshould be input to the system. The Assume the fixed I/O waiting time (2 units).Thenext 
// CPU burst should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a process
struct Process {
    int id;          // Process ID
    int arrivalTime; // Arrival Time
    int cpuBurstTime; // CPU Burst Time
    int ioBurstTime;  // I/O Burst Time
    int turnaroundTime;
    int waitingTime;
};

// Function to generate a random CPU burst time (between 1 and 10 units)
int generateRandomCPUBurstTime() {
    return (rand() % 10) + 1;
}

int main() {
    srand(time(NULL)); // Seed for random number generator

    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input arrival time and CPU burst time for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        processes[i].cpuBurstTime = generateRandomCPUBurstTime();
        processes[i].ioBurstTime = 2; // Fixed I/O burst time (2 units)
    }

    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        // Simulate arrival time
        if (processes[i].arrivalTime > currentTime) {
            currentTime = processes[i].arrivalTime;
        }

        printf("P%d ", processes[i].id);

        // Simulate CPU burst time
        currentTime += processes[i].cpuBurstTime;

        // Calculate waiting time and turnaround time for the current process
        processes[i].waitingTime = currentTime - processes[i].arrivalTime - processes[i].cpuBurstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].cpuBurstTime;

        totalTurnaroundTime += processes[i].turnaroundTime;
        totalWaitingTime += processes[i].waitingTime;
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

