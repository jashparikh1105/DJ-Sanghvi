#include <stdio.h>
#include <limits.h>

// Check if the page is already present in the frame
int checkHit(int incomingPage, int queue[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        if (incomingPage == queue[i])
            return 1;
    }
    return 0;
}

// Print current content of the frame
void printFrame(int queue[], int occupied) {
    for (int i = 0; i < occupied; i++)
        printf("%d\t\t\t", queue[i]);
}

int main() {
    // Sample stream
    int incomingStream[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    int n = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int frames = 3;
    int queue[n];       // to simulate memory frames
    int distance[n];    // to hold the LRU distances
    int occupied = 0;
    int pagefault = 0;

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Page\t\tFrame1\t\t\tFrame2\t\t\tFrame3\n");

    for (int i = 0; i < n; i++) {
        printf("%d:\t\t", incomingStream[i]);

        if (checkHit(incomingStream[i], queue, occupied)) {
            // Page hit
            printFrame(queue, occupied);
        } else if (occupied < frames) {
            // Free space in frame
            queue[occupied] = incomingStream[i];
            pagefault++;
            occupied++;
            printFrame(queue, occupied);
        } else {
            // LRU Replacement
            int max = INT_MIN, index = -1;

            // Calculate distances for all current frame entries
            for (int j = 0; j < frames; j++) {
                distance[j] = 0;
                for (int k = i - 1; k >= 0; k--) {
                    distance[j]++;
                    if (queue[j] == incomingStream[k])
                        break;
                }

                if (distance[j] > max) {
                    max = distance[j];
                    index = j;
                }
            }

            queue[index] = incomingStream[i];
            pagefault++;
            printFrame(queue, occupied);
        }

        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pagefault);

    return 0;
}
