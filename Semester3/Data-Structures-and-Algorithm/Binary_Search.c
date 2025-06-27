#include <stdio.h>

// Function to perform binary search
int bs(int a[], int n, int x) {
    int l = 0, h = n - 1, m;

    while (l <= h) {
        m = (l + h) / 2;

        if (a[m] == x)
            return m;  // Element found at index m
        else if (a[m] < x)
            l = m + 1;
        else
            h = m - 1;
    }

    return -1;  // Element not found
}

int main() {
    int i, flag, n, x, a[100];

    printf("Jash Parikh, C065, 60004220080\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &x);

    flag = bs(a, n, x);

    if (flag == -1)
        printf("Not present\n");
    else
        printf("The number is present at index %d\n", flag);

    return 0;
}
