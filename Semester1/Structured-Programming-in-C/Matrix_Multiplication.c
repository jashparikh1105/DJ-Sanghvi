#include <stdio.h>

int main() {
    int m, n, p, q, i, j, k;

    printf("Enter rows and cols for Matrix A: ");
    scanf("%d %d", &m, &n);

    printf("Enter rows and cols for Matrix B: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    int A[m][n], B[p][q], C[m][q];

    printf("Enter elements of Matrix A (row-major):\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B (column-major):\n");
    for (j = 0; j < q; j++)
        for (i = 0; i < p; i++)
            scanf("%d", &B[i][j]);

    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    printf("Resultant Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }

    return 0;
}
