#include <stdio.h>

// Function to perform linear search
int ls(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x)
            return i;  // Return the index where the element is found
    }
    return -1;  // Return -1 if element is not found
}

int main() {
    int a[100], n, x, flag;

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &x);

    flag = ls(a, n, x);

    if (flag == -1)
        printf("Not present\n");
    else
        printf("The number is present at index %d\n", flag);

    return 0;
}
