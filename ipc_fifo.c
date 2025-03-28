#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "myfifo"

int main() {
    char message[100];
    int fd;

    mkfifo(FIFO_FILE, 0666);

    if (fork() == 0) {
        fd = open(FIFO_FILE, O_WRONLY);
        char *msg = "Hello from the write process!";
        write(fd, msg, strlen(msg) + 1);
        close(fd);
        exit(0);
    }

    fd = open(FIFO_FILE, O_RDONLY);
    read(fd, message, sizeof(message));
    printf("Read from FIFO: %s\n", message);
    close(fd);

    unlink(FIFO_FILE);

    return 0;
}

