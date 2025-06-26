// C program for FIFO page replacement algorithm
#include <stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;

    printf("Jash Parikh, 60004220080, C065\n");

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3\n");

    int temp[frames];
    for (m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    for (m = 0; m < pages; m++) {
        s = 0;

        // Check for page hit
        for (n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s++;
                pageFaults--;  // Avoid counting twice
                break;
            }
        }

        pageFaults++;  // Default page fault increase

        // Add page if there's space
        if ((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m];
        } 
        // Replace using FIFO
        else if (s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        // Print current frame status
        printf("%d\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf(" %d\t\t", temp[n]);
            else
                printf(" -\t\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
