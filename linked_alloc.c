#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int data;
    int next;
} Block;

void linkedAllocation(Block blocks[]) {
    blocks[0] = (Block){1, 1};
    blocks[1] = (Block){2, 2};
    blocks[2] = (Block){3, -1}; // End of chain
}

int main() {
    Block blocks[3];
    linkedAllocation(blocks);

    for (int i = 0; i < 3; i++) {
        printf("Data: %d, Next: %d\n", blocks[i].data, blocks[i].next);
    }

    return 0;
}

