#include <iostream>
#include <vector>

void contiguousAllocation(std::vector<int>& memory, int start, int size) {
    for (int i = start; i < start + size; i++) {
        memory[i] = 1;  // Allocate
    }
}

int main() {
    std::vector<int> memory(100, 0); // Simulated memory
    contiguousAllocation(memory, 10, 5); // Allocating 5 units starting at index 10
    for (int i = 0; i < memory.size(); i++) {
        std::cout << memory[i] << " ";
    }
    return 0;
}

