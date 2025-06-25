#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int currentLoopDepth = 0;
int maximumDepth = 0;
int hasLogarithmicLoop = 0;

char *removeLeadingSpaces(char *str) {
    while (*str == ' ' || *str == '\t') {
        str++;
    }
    return str;
}

void analyzeLineForLoops(char *line) {
    line = removeLeadingSpaces(line);
    if (strncmp(line, "for", 3) == 0 || strncmp(line, "while", 5) == 0 || strncmp(line, "do", 2) == 0) {
        currentLoopDepth++;
        if (currentLoopDepth > maximumDepth) {
            maximumDepth = currentLoopDepth;
        }
        if (strstr(line, "*=") || strstr(line, "/=")) {
            hasLogarithmicLoop = 1;
        }
        printf("Loop detected: depth increased to %d\n", currentLoopDepth);
    }

    if (strstr(line, "}")) {
        if (currentLoopDepth > 0) {
            currentLoopDepth--;
            printf("Closing brace found: depth decreased to %d\n", currentLoopDepth);
        }
    }
}

void displayComplexity() {
    if (maximumDepth == 0) {
        printf("Estimated time complexity: O(1)\n");
    } else {
        if (hasLogarithmicLoop) {
            if (maximumDepth == 1) {
                printf("Estimated time complexity: O(log n)\n");
            } else {
                printf("Estimated time complexity: O(n^%d log n)\n", maximumDepth - 1);
            }
        } else {
            if (maximumDepth == 1) {
                printf("Estimated time complexity: O(n)\n");
            } else {
                printf("Estimated time complexity: O(n^%d)\n", maximumDepth);
            }
        }
    }
}

int main() {
    char lineBuffer[MAX_LINE_LENGTH];
    FILE *filePointer = fopen("tripleloop.c", "r");

    if (filePointer == NULL) {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }

    while (fgets(lineBuffer, sizeof(lineBuffer), filePointer) != NULL) {
        analyzeLineForLoops(lineBuffer);
    }

    fclose(filePointer);
    displayComplexity();
    return EXIT_SUCCESS;
}
