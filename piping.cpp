#include <iostream>
#include <unistd.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        std::cerr << "Pipe creation failed!" << std::endl;
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }

    if (pid == 0) { 
        close(pipefd[1]); 
	char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        std::cout << "Child received: " << buffer << std::endl;
        close(pipefd[0]);
    } else { 
        close(pipefd[0]);
        const char* message = "Hello from parent!";
        write(pipefd[1], message, sizeof(message));
        close(pipefd[1]);
    }

    return 0;
}

