// Q.1 Create a child process using fork(), display parent and child process id. Child process will
// display the message “Hello World” and the parent process should display “Hi”.

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork(); // Create a child process

    if (child_pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child Process (PID: %d) says: Hello World\n", getpid());
    } else {
        // This code is executed by the parent process
        printf("Parent Process (PID: %d) says: Hi\n", getpid());
    }

    return 0;
}
