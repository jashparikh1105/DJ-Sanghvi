#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

void printJobScheduling(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), compare);
    int result[n], slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }

    printf("Scheduled Jobs:\n");
    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%c ", arr[result[i]].id);
    printf("\n");
}

int main() {
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                 {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\nJash Parikh, C065, 60004220080\n");
    printJobScheduling(arr, n);
    return 0;
}
