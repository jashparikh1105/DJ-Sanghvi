#include <stdio.h>

void findMaxMin(int a, int b) {
    if (a > b)
        printf("Max: %d, Min: %d\n", a, b);
    else
        printf("Max: %d, Min: %d\n", b, a);
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    findMaxMin(x, y);
    return 0;
}
