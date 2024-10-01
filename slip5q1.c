// Q.1 Write a program that demonstrates the use of nice () system call. After a child process is
// started using fork (), assign higher priority to the child using nice () system call.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int main() {
    pid_t child_pid;
    int nice_value = -10; // Set a nice value for the child process

    printf("Parent Process (PID %d) is starting...\n", getpid());

    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child Process (PID %d) is running...\n", getpid());

        // Assign a higher priority to the child process using nice
        if (nice(nice_value) == -1) {
            perror("Nice failed");
            exit(1);
        }

        printf("Child Process (PID %d) has a higher priority (nice value: %d).\n", getpid(), nice_value);
    } else {
        // This code is executed by the parent process
        printf("Parent Process (PID %d) is running...\n", getpid());

        // Sleep for a while to allow the child to execute
        sleep(2);

        printf("Parent Process (PID %d) has finished.\n", getpid());
    }

    return 0;
}
