// Q.2 Write the program to simulate Round Robin (RR) scheduling. The arrival time and first CPUburst for different n number of processes should be input to the algorithm. Also give the time
// quantum as input. Assume the fixed IO waiting time (2 units). The next CPU-burst should be
// generated randomly. The output should give Gantt chart, turnaround time and waiting time for each
// process. Also find the average waiting time and turnaround time. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process {
    int arrival_time;
    int first_cpu_burst;
    int next_cpu_burst;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
    int executed;
};

int main() {
    int n, time_quantum;

    srand(time(NULL));

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("First CPU Burst Time: ");
        scanf("%d", &processes[i].first_cpu_burst);

        // Initialize other process attributes
        processes[i].next_cpu_burst = 0;
        processes[i].remaining_time = processes[i].first_cpu_burst;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
        processes[i].executed = 0;
    }

    int current_time = 0;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int executed_processes = 0;

    printf("\nGantt Chart:\n");

    while (executed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                int execute_time = (processes[i].remaining_time > time_quantum) ? time_quantum : processes[i].remaining_time;

                // Generate the next CPU burst time randomly
                processes[i].next_cpu_burst = rand() % 10 + 1;

                printf("P%d (%d-%d) ", i + 1, current_time, current_time + execute_time);

                processes[i].remaining_time -= execute_time;
                current_time += execute_time;

                if (processes[i].remaining_time == 0) {
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].first_cpu_burst;
                    total_turnaround_time += processes[i].turnaround_time;
                    total_waiting_time += processes[i].waiting_time;
                    executed_processes++;
                }
            }
        }
    }

    printf("\n\nTurnaround Time and Waiting Time:\n");

    for (int i = 0; i < n; i++) {
        printf("Process %d - Turnaround Time: %d, Waiting Time: %d\n", i + 1, processes[i].turnaround_time, processes[i].waiting_time);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);

    return 0;
}
