// Q. 1 Creating a child process using the command exec(). Note down process ids of the parent
// and the child processes, check whether the control is given back to the parent after the child
// process terminates.

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
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child Process: My PID is %d\n", getpid());
        printf("Child Process: Executing 'ls' command...\n");
        
        // Execute the 'ls' command in the child process
        execlp("ls", "ls", (char *)NULL);

        // If execlp fails, it will print an error message
        perror("execlp");
        exit(1);
    } else {
        // This code is executed by the parent process
        printf("Parent Process: My PID is %d\n", getpid());
        printf("Parent Process: Waiting for the child to finish...\n");

        // Wait for the child process to terminate
        wait(NULL);

        printf("Parent Process: Child has finished.\n");
    }

    return 0;
}
