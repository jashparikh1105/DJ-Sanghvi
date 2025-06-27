#include <stdio.h>
#include <conio.h>
#define SIZE 25

void swap(int A[SIZE], int *i, int *j) {
    int temp;
    temp = A[*i];
    A[*i] = A[*j];
    A[*j] = temp;
}

int Partition(int A[SIZE], int low, int high) {
    int i = low, j = high;
    int pivot = A[low];
    while (i < j) {
        while (A[i] <= pivot && i <= high) i++;
        while (A[j] > pivot && j >= low) j--;
        if (i < j)
            swap(A, &i, &j);
    }
    swap(A, &low, &j);
    return j;
}

void Quick(int A[SIZE], int low, int high) {
    int m;
    if (low < high) {
        m = Partition(A, low, high);
        Quick(A, low, m - 1);
        Quick(A, m + 1, high);
    }
}

void main() {
    int i, n, A[SIZE];
    clrscr();
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the numbers of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    Quick(A, 0, n - 1);

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }
    getch();
}
