#include <stdio.h>

void minMax(int arr[], int low, int high, int* min, int* max) {
    if (low == high) {
        *min = *max = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2, min1, max1, min2, max2;
    minMax(arr, low, mid, &min1, &max1);
    minMax(arr, mid + 1, high, &min2, &max2);

    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {5, 1, 9, 2, 10, 3};
    int min, max;
    minMax(arr, 0, 5, &min, &max);
    printf("\nJash Parikh, C065, 60004220080\n");
    printf("Minimum: %d\nMaximum: %d\n", min, max);
    return 0;
}
