// Q.2 Write the simulation program using SJF (non-preemptive). The arrival time and first CPU
// bursts of different jobs should be input to the system. Assume the fixed I/O waiting time (2 units).
// The next CPU burst should be generated using random function. The output should give the Gantt
// chart, Turnaround Time and Waiting time for each process and average times.[20 
// marks]
//program not working properly 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

struct Process {
    int id;
    int arrivalTime;
    int initialCpuBurst;
    int remainingCpuBurst;
    int turnaroundTime;
    int waitingTime;
};

// Function to sort processes by arrival time
void sortByArrivalTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrivalTime > processes[j].arrivalTime) {
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

    // Input arrival times and initial CPU burst times
    for (int i = 0; i < n; i++) {
        processes[i].id = i;
        printf("Enter arrival time for process P%d: ", i);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter initial CPU burst for process P%d: ", i);
        scanf("%d", &processes[i].initialCpuBurst);
        processes[i].remainingCpuBurst = processes[i].initialCpuBurst;
    }

    sortByArrivalTime(processes, n);

    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    printf("\nGantt Chart:\n");

    while (1) {
        int shortestJobIndex = -1;
        int shortestJobBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingCpuBurst < shortestJobBurst && processes[i].remainingCpuBurst > 0) {
                shortestJobIndex = i;
                shortestJobBurst = processes[i].remainingCpuBurst;
            }
        }

        if (shortestJobIndex == -1) {
            currentTime++;
            continue;
        }

        // Execute the shortest job
        processes[shortestJobIndex].remainingCpuBurst--;

        printf("P%d ", processes[shortestJobIndex].id);

        if (processes[shortestJobIndex].remainingCpuBurst == 0) {
            int finishTime = currentTime + 1;
            processes[shortestJobIndex].turnaroundTime = finishTime - processes[shortestJobIndex].arrivalTime;
            processes[shortestJobIndex].waitingTime = processes[shortestJobIndex].turnaroundTime - processes[shortestJobIndex].initialCpuBurst;

            totalTurnaroundTime += processes[shortestJobIndex].turnaroundTime;
            totalWaitingTime += processes[shortestJobIndex].waitingTime;
        }

        currentTime++;
    }

    printf("\n");

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
