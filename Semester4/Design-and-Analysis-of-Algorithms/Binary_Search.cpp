#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int x, int* steps) {
    while (low <= high) {
        (*steps)++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[10000], i, n = 10000, x;
    double t1, t2, t3;

    for (i = 0; i < n; i++)
        arr[i] = i;

    printf("\nJash Parikh, C065, 60004220080\n");

    // Best case (middle element)
    x = arr[n/2];
    int steps = 0;
    t1 = clock();
    binarySearch(arr, 0, n-1, x, &steps);
    t2 = clock();
    t3 = (t2 - t1) / CLOCKS_PER_SEC;
    printf("Best Case Time: %f seconds, Steps: %d\n", t3, steps);

    // Worst case (not present)
    x = -1;
    steps = 0;
    t1 = clock();
    binarySearch(arr, 0, n-1, x, &steps);
    t2 = clock();
    t3 = (t2 - t1) / CLOCKS_PER_SEC;
    printf("Worst Case Time: %f seconds, Steps: %d\n", t3, steps);

    // Average case
    x = rand() % n;
    steps = 0;
    t1 = clock();
    binarySearch(arr, 0, n-1, x, &steps);
    t2 = clock();
    t3 = (t2 - t1) / CLOCKS_PER_SEC;
    printf("Average Case Time: %f seconds, Steps: %d\n", t3, steps);

    return 0;
}
