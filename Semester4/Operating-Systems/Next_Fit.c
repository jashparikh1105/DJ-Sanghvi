#include <stdio.h>

void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    // Initially no block is allocated
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    int j = 0;  // pointer for block position

    // Allocate each process using Next Fit strategy
    for (int i = 0; i < n; i++) {
        int count = 0;

        while (count < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }

            j = (j + 1) % m;
            count++;
        }
    }

    // Print allocation results
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Block for Process No %d with Size %d is %d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Block for Process No %d with Size %d cannot be allocated\n", i + 1, processSize[i]);
    }

    printf("\nEnd of process\n");
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    printf("Jash Parikh, C065, 60004220080\n");

    nextFit(blockSize, m, processSize, n);

    return 0;
}
