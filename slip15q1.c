// Q.1 Write a program to create a child process using fork().The parent should goto sleep state and
// child process should begin its execution. In the child process, use execl() to execute the “ls”
// command.

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

        // Use execl to run the "ls" command in the child process
        if (execl("/bin/ls", "ls", (char *)NULL) == -1) {
            perror("Execl failed");
            exit(1);
        }
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID: %d) is going to sleep for 5 seconds.\n", getpid());
        sleep(5); // Sleep for 5 seconds
        printf("Parent process (PID: %d) woke up from sleep.\n", getpid());
    }

    return 0;
}
