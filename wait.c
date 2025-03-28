#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process: PID = %d\n", getpid());
        sleep(2);  // Simulate some work in the child process
        printf("Child Process: Exiting\n");
        exit(0);
    } else {
        int status;
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        wait(&status);  // Wait for the child process to finish
        printf("Parent Process: Child terminated with status %d\n", status);
    }

    return 0;
}

