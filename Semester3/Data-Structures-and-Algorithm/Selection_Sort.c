#include <stdio.h>
#include <conio.h>

void selectionsort(int a[], int);

void main() {
    int i, n, a[100];
    clrscr();

    printf("Enter the number of elements\n");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    selectionsort(a, n);

    printf("The sorted array is: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    getch();
}

void selectionsort(int a[], int n) {
    int i, j, t, min;
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        if(min != i) {
            t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }
}
