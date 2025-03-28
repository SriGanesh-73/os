#include <stdio.h>
#include <stdlib.h>

void contiguousAllocation(int memory[], int start, int size) {
    for (int i = start; i < start + size; i++) {
        memory[i] = 1;
    }
}

int main() {
    int memory[100] = {0}; // Simulated memory
    contiguousAllocation(memory, 10, 5); // Allocating 5 units starting at index 10

    for (int i = 0; i < 100; i++) {
        printf("%d ", memory[i]);
    }

    return 0;
}

