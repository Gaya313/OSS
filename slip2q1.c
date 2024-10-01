// Q.1 Create a child process using fork(), display parent and child process id. Child process will
// display the message “Hello World” and the parent process should display “Hi”.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child Process ID: %d\n", getpid());
        printf("Hello World\n");
    } else if (child_pid > 0) {
        // This code is executed by the parent process
        printf("Parent Process ID: %d\n", getpid());
        printf("Hi\n");
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}
