// I am a C programmer, and I’m currently exploring memory management systems as part of my learning journey. I decided to implement a memory pool allocator to understand how fixed-size memory blocks can be managed efficiently. The system uses a memory pool of 1024 bytes, divided into 32-byte blocks, and tracks their status to manage allocation and deallocation manually.

// As part of best practices, the code should include clear inline comments to help beginners understand the logic and functionality. Additionally, the program needs detailed documentation to explain its structure and behavior comprehensively. Could you help me add these comments and create documentation for the code?

// This is the code:
// ```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define POOL_SIZE 1024  // Memory pool size in bytes
#define BLOCK_SIZE 32   // Size of each block in bytes

typedef struct {
    char pool[POOL_SIZE];
    bool blockStatus[POOL_SIZE / BLOCK_SIZE];
} MemoryPool;

void initializePool(MemoryPool *mp) {
    memset(mp->pool, 0, POOL_SIZE);
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE; i++) {
        mp->blockStatus[i] = false;
    }
}

void *allocateBlock(MemoryPool *mp) {
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE; i++) {
        if (!mp->blockStatus[i]) {
            mp->blockStatus[i] = true;
            return &mp->pool[i * BLOCK_SIZE];
        }
    }
    return NULL; // No free block available
}

void freeBlock(MemoryPool *mp, void *block) {
    int index = ((char *)block - mp->pool) / BLOCK_SIZE;
    if (index >= 0 && index < POOL_SIZE / BLOCK_SIZE) {
        mp->blockStatus[index] = false;
    } else {
        fprintf(stderr, "Error: Invalid block pointer\n");
    }
}

void printPoolStatus(MemoryPool *mp) {
    printf("Memory Pool Status:\n");
    for (int i = 0; i < POOL_SIZE / BLOCK_SIZE; i++) {
        printf("Block %d: %s\n", i, mp->blockStatus[i] ? "Allocated" : "Free");
    }
}

int main() {
    MemoryPool mp;
    initializePool(&mp);

    void *block1 = allocateBlock(&mp);
    void *block2 = allocateBlock(&mp);
    printPoolStatus(&mp);

    freeBlock(&mp, block1);
    printPoolStatus(&mp);

    freeBlock(&mp, block2);
    printPoolStatus(&mp);

    return 0;
}
// ```