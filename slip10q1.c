// Q.1 Write a program to illustrate the concept of orphan process (Using fork() and sleep())

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork(); // Create a child process

    if (child_pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process (PID: %d) is running.\n", getpid());
        sleep(5); // Sleep for 5 seconds
        printf("Child process (PID: %d) is done.\n", getpid());
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID: %d) is running.\n", getpid());
        printf("Parent process is terminating.\n");
        exit(0);
    }

    return 0;
}
