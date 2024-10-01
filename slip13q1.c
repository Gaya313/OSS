// Q.1 Write a program that demonstrates the use of nice() system call. After a child process is
// started using fork(), assign higher priority to the child using nice() system call.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    pid_t child_pid = fork(); // Create a child process

    if (child_pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process (PID: %d) is running with default priority.\n", getpid());

        int nice_value = nice(10); // Set a higher priority for the child (lower nice value)

        if (nice_value == -1) {
            perror("Nice failed");
        } else {
            printf("Child process (PID: %d) has a higher priority (lower nice value: %d).\n", getpid(), nice_value);
        }
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID: %d) is running with default priority.\n", getpid());
        printf("Parent process is not changing its priority.\n");
    }

    return 0;
}
