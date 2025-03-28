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
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        execlp("/bin/ls", "ls", "-l", NULL);
        perror("exec");
        exit(1);
    } else {
        int status;
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        wait(&status);
        printf("Parent Process: Child terminated with status %d\n", status);
    }

    return 0;
}

