#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1, temp;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[10000], i;
    for (i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;

    double t1 = clock();
    quickSort(arr, 0, 9999);
    double t2 = clock();

    printf("\nJash Parikh, C065, 60004220080\n");
    printf("Quick Sort Time: %f seconds\n", (t2 - t1)/CLOCKS_PER_SEC);
    return 0;
}
