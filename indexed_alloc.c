#include <stdio.h>
#include <stdlib.h>

void indexedAllocation(int memory[], int index[], int value, int size) {
    for (int i = 0; i < size; i++) {
        memory[index[i]] = value;
    }
}

int main() {
    int memory[100] = {0}; // Simulated memory
    int index[] = {3, 5, 7, 9}; // Blocks to be allocated

    indexedAllocation(memory, index, 1, 4);

    for (int i = 0; i < 100; i++) {
        printf("%d ", memory[i]);
    }

    return 0;
}

