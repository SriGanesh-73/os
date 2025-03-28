#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) { // Child process
        close(pipefd[1]);
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else { // Parent process
        close(pipefd[0]);
        const char *message = "Hello from parent!";
        write(pipefd[1], message, sizeof(message));
        close(pipefd[1]);
    }

    return 0;
}
