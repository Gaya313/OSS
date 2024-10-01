// Q.2 Write the simulation program using FCFS. The arrival time and first CPU bursts of different
// jobs should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU
// burst should be generated using random function. The output should give the Gantt chart,
// Turnaround Time and Waiting time for each process and average times

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a job
typedef struct {
    int arrival_time;
    int first_cpu_burst;
    int next_cpu_burst;
    int turnaround_time;
    int waiting_time;
} Job;

// Function to calculate average turnaround and waiting times
void calculateAverages(Job jobs[], int n, float *avg_turnaround, float *avg_waiting) {
    int total_turnaround = 0;
    int total_waiting = 0;
    
    for (int i = 0; i < n; i++) {
        total_turnaround += jobs[i].turnaround_time;
        total_waiting += jobs[i].waiting_time;
    }
    
    *avg_turnaround = (float)total_turnaround / n;
    *avg_waiting = (float)total_waiting / n;
}

int main() {
    int n; // Number of jobs
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];

    // Input arrival time and first CPU burst for each job
    for (int i = 0; i < n; i++) {
        printf("Job %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &jobs[i].arrival_time);
        printf("First CPU Burst Time: ");
        scanf("%d", &jobs[i].first_cpu_burst);

        // Initialize other job attributes
        jobs[i].next_cpu_burst = 0;
        jobs[i].turnaround_time = 0;
        jobs[i].waiting_time = 0;
    }

    int current_time = 0;

    // Process jobs in FCFS order
    for (int i = 0; i < n; i++) {
        // Wait for the job to arrive
        if (current_time < jobs[i].arrival_time) {
            current_time = jobs[i].arrival_time;
        }

        // Update next CPU burst using a random function (e.g., rand())
        jobs[i].next_cpu_burst = rand() % 10 + 1; // Generating random burst time between 1 and 10 units

        // Calculate turnaround and waiting times
        jobs[i].turnaround_time = current_time + jobs[i].first_cpu_burst + jobs[i].next_cpu_burst - jobs[i].arrival_time;
        jobs[i].waiting_time = jobs[i].turnaround_time - jobs[i].first_cpu_burst - jobs[i].next_cpu_burst;

        // Update the current time
        current_time += jobs[i].first_cpu_burst + jobs[i].next_cpu_burst;
    }

    // Calculate and display the Gantt chart
    printf("\nGantt Chart:\n");
    printf("0");
    for (int i = 0; i < n; i++) {
        printf(" -> Job%d -> %d", i + 1, current_time);
    }
    printf("\n");

    // Display turnaround and waiting times for each job
    printf("\nTurnaround Times and Waiting Times:\n");
    for (int i = 0; i < n; i++) {
        printf("Job%d - Turnaround Time: %d, Waiting Time: %d\n", i + 1, jobs[i].turnaround_time, jobs[i].waiting_time);
    }

    // Calculate and display average turnaround and waiting times
    float avg_turnaround, avg_waiting;
    calculateAverages(jobs, n, &avg_turnaround, &avg_waiting);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);

    return 0;
}
