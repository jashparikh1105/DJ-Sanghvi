#include <stdio.h>
#include <conio.h>

void merge(int a[], int beg, int mid, int end);
void merge_sort(int a[], int beg, int end);

void main() {
    int arr[100], i, n;
    clrscr();

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    printf("Enter the values of array: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("The sorted array is: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    getch();
}

void merge_sort(int arr[100], int beg, int end) {
    int mid;
    if(beg < end) {
        mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void merge(int arr[100], int beg, int mid, int end) {
    int i = beg, j = mid + 1, index = beg, temp[100], k;

    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp[index++] = arr[i++];
        } else {
            temp[index++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[index++] = arr[i++];
    }

    while(j <= end) {
        temp[index++] = arr[j++];
    }

    for(k = beg; k < index; k++) {
        arr[k] = temp[k];
    }
}
