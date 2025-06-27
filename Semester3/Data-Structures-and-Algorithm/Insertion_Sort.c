#include <stdio.h>

void insertionsort(int a[], int n) {
    int i, j, t;
    for (i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}

int main() {
    int n, a[100], i;

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    insertionsort(a, n);

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}
