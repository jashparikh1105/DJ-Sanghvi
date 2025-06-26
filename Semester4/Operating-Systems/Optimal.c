#include <stdio.h>

// Function to check if the key is present in frame
int search(int key, int frame_items[], int frame_occupied) {
    for (int i = 0; i < frame_occupied; i++)
        if (frame_items[i] == key)
            return 1;
    return 0;
}

// Print column headers
void printOuterStructure(int max_frames) {
    printf("Stream\t\t");
    for (int i = 0; i < max_frames; i++)
        printf("Frame%d\t\t", i + 1);
    printf("\n");
}

// Print current stream value and current state of frames
void printCurrFrames(int item, int frame_items[], int frame_occupied, int max_frames) {
    printf("%d\t\t", item);
    for (int i = 0; i < max_frames; i++) {
        if (i < frame_occupied)
            printf("%d\t\t", frame_items[i]);
        else
            printf("-\t\t");
    }
    printf("\n");
}

// Predict which frame item to replace using Optimal algorithm
int predict(int ref_str[], int frame_items[], int refStrLen, int index, int frame_occupied) {
    int result = -1, farthest = index;

    for (int i = 0; i < frame_occupied; i++) {
        int j;
        for (j = index; j < refStrLen; j++) {
            if (frame_items[i] == ref_str[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == refStrLen) // Not used again in future
            return i;
    }

    return (result == -1) ? 0 : result;
}

// Main Optimal Page Replacement Logic
void optimalPage(int ref_str[], int refStrLen, int frame_items[], int max_frames) {
    int frame_occupied = 0;
    int hits = 0;

    printOuterStructure(max_frames);

    for (int i = 0; i < refStrLen; i++) {
        // Page Hit
        if (search(ref_str[i], frame_items, frame_occupied)) {
            hits++;
            printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames);
            continue;
        }

        // Page Miss
        if (frame_occupied < max_frames) {
            frame_items[frame_occupied++] = ref_str[i];
        } else {
            int pos = predict(ref_str, frame_items, refStrLen, i + 1, frame_occupied);
            frame_items[pos] = ref_str[i];
        }

        printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames);
    }

    printf("\nTotal Hits: %d\n", hits);
    printf("Total Misses (Page Faults): %d\n", refStrLen - hits);
}

// Driver Function
int main() {
    int ref_str[] = {9, 0, 5, 1, 0, 3, 0, 4, 1, 3, 0, 3, 1, 3};
    int refStrLen = sizeof(ref_str) / sizeof(ref_str[0]);
    int max_frames = 3;
    int frame_items[max_frames];

    printf("Jash Parikh, C065, 60004220080\n");
    optimalPage(ref_str, refStrLen, frame_items, max_frames);

    return 0;
}
