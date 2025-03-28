#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Before exit\n");
    exit(0);  // Exit the program with status 0
    printf("This will not be printed\n");
    return 0;
}

