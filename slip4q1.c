// Q.1 Write a program to illustrate the concept of orphan process ( Using fork() and sleep())
// [10 marks]


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    printf("Parent Process (PID %d) is starting...\n", getpid());

    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child Process (PID %d) is running...\n", getpid());

        // Sleep for a while to simulate some work
        sleep(5);

        printf("Child Process (PID %d) has finished.\n", getpid());
    } else {
        // This code is executed by the parent process
        printf("Parent Process (PID %d) is running...\n", getpid());

        // Sleep for a while to simulate some work
        sleep(2);

        printf("Parent Process (PID %d) has finished.\n", getpid());
    }

    return 0;
}
