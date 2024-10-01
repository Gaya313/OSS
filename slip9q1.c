// Q.1 Write a program to create a child process using fork().The parent should goto sleep state and
// child process should begin its execution. In the child process, use execl() to execute the “ls”
// command.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // This code runs in the child process
        printf("Child process is executing the 'ls' command:\n");
        execl("/bin/ls", "ls", NULL);

        // If execl() fails, the following code is executed
        perror("execl"); // This will be printed if execl() fails
        exit(1); // Terminate the child process
    } else {
        // This code runs in the parent process
        printf("Parent process is going to sleep...\n");
        sleep(2); // Sleep for 2 seconds
        printf("Parent process woke up from sleep.\n");

        // Wait for the child process to complete
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
