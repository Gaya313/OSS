// Q.2 Write the program to simulate Non-preemptive Priority scheduling. The arrival time and
// first CPU burst and priority for different n number of processes should be input to the algorithm.
// Assume the fixed IO waiting time (2 units). The next CPU-burst should be generated randomly.
// The output should give Gantt chart, turnaround time and waiting time for each process. Also find
// the average waiting time and turnaround time. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, i, j;
    srand(time(NULL));

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].arrival_time = 0; // You can modify this to input arrival time
        processes[i].burst_time = rand() % 10 + 1; // Generate random burst time (1 to 10)
        processes[i].priority = rand() % 5; // Generate random priority (0 to 4)
    }

    // Sort processes based on priority (lower value has higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completion_time = 0;

    printf("Gantt Chart:\n");
    for (i = 0; i < n; i++) {
        printf("P%d (%d) -> ", processes[i].id, completion_time);
        processes[i].waiting_time = completion_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        completion_time += processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("\n");

    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    float average_waiting_time = (float)total_waiting_time / n;
    float average_turnaround_time = (float)total_turnaround_time / n;

    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}
