// Q.1 Write a program that demonstrates the use of nice() system call. After a child process is started
// using fork(), assign higher priority to the child using nice() system call.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int nice_value = -10;  // A lower nice value means higher priority

    child_pid = fork();

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process (PID %d) is running with normal priority.\n", getpid());
    } else if (child_pid > 0) {
        // This code is executed by the parent process
        printf("Parent process (PID %d) is running with normal priority.\n", getpid());

        // Adjust the priority of the child process using nice()
        if (nice(nice_value) == -1) {
            perror("nice");
            exit(EXIT_FAILURE);
        }

        printf("Parent process has adjusted the child process's priority to be higher.\n");
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Add a sleep to keep the processes running for a while
    sleep(5);

    return 0;
}
