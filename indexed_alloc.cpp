#include <iostream>
#include <vector>

void indexedAllocation(std::vector<int>& memory, const std::vector<int>& index, int value) {
    for (int i : index) {
        memory[i] = value;
    }
}

int main() {
    std::vector<int> memory(100, 0); // Simulated memory
    std::vector<int> index = {3, 5, 7, 9}; // Blocks to be allocated
    indexedAllocation(memory, index, 1);
    for (int i = 0; i < memory.size(); i++) {
        std::cout << memory[i] << " ";
    }
    return 0;
}

