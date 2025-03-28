#include <iostream>
#include <vector>

struct Block {
    int data;
    int next;
};

void linkedAllocation(std::vector<Block>& blocks) {
    blocks.push_back({1, 1});
    blocks.push_back({2, 2});
    blocks.push_back({3, -1}); // End of chain
}

int main() {
    std::vector<Block> blocks;
    linkedAllocation(blocks);
    for (const auto& block : blocks) {
        std::cout << "Data: " << block.data << ", Next: " << block.next << std::endl;
    }
    return 0;
}

