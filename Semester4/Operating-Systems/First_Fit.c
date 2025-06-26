#include <stdio.h>

// Function to allocate memory to blocks as per First Fit algorithm
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int i, j;
    int allocation[n];  // Stores block id allocated to each process

    // Initially no block is assigned to any process
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Pick each process and find a suitable block
    for (i = 0; i < n; i++) {           // n -> number of processes
        for (j = 0; j < m; j++) {       // m -> number of blocks
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;             // Allocate block j
                blockSize[j] -= processSize[i]; // Reduce memory in block
                break;                         // Go to next process
            }
        }
    }

    // Print allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf(" %d\t\t\t%d\t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1); // Block number (1-based)
        else
            printf("Not Allocated");
        printf("\n");
    }
}

// Driver code
int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m, n;

    printf("Jash Parikh, C065, 60004220080\n");

    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);

    return 0;
}
