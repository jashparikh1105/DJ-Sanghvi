#include <stdio.h>

void implementWorstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    int occupied[blocks];

    // Initially assign -1 to all allocation indexes (no allocation yet)
    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    // Mark all blocks as unoccupied
    for (int i = 0; i < blocks; i++) {
        occupied[i] = 0;
    }

    // Allocate each process to the worst-fit block
    for (int i = 0; i < processes; i++) {
        int indexPlaced = -1;

        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i] && !occupied[j]) {
                if (indexPlaced == -1 || blockSize[j] > blockSize[indexPlaced]) {
                    indexPlaced = j;
                }
            }
        }

        // If a suitable block was found
        if (indexPlaced != -1) {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
            blockSize[indexPlaced] -= processSize[i]; // Reduce block size
        }
    }

    // Output the allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processes; i++) {
        printf("%d\t\t\t%d\t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);  // Block number shown as 1-based
        else
            printf("Not Allocated\n");
    }
}

// Driver code
int main() {
    int blockSize[] = {100, 50, 30, 120, 35};
    int processSize[] = {40, 10, 30, 60};
    int blocks = sizeof(blockSize) / sizeof(blockSize[0]);
    int processes = sizeof(processSize) / sizeof(processSize[0]);

    printf("Jash Parikh, C065, 60004220080\n");
    implementWorstFit(blockSize, blocks, processSize, processes);

    return 0;
}
