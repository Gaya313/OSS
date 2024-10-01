// Q.1 Write a program to create a child process using fork().The parent should goto sleep state and
// child process should begin its execution. In the child process, use execl() to execute the “ls”
// command. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process ID: %d\n", getpid());

        // Use execl to execute the "ls" command
        execl("/bin/ls", "ls", (char *)NULL);

        // If execl fails, it will reach here
        perror("Execl failed");
        exit(1);
    } else {
        // This code is executed by the parent process
        printf("Parent process ID: %d\n", getpid());

        // Parent goes to sleep for a while (optional)
        sleep(2);

        // Wait for the child to finish
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
