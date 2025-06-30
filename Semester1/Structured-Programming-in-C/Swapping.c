#include <stdio.h>

int main() {
    int a, b, temp;

    // With third variable
    printf("Enter two numbers (with third variable): ");
    scanf("%d %d", &a, &b);

    temp = a;
    a = b;
    b = temp;
    printf("Swapped (with third): a = %d, b = %d\n", a, b);

    // Without third variable
    printf("Enter two numbers (without third variable): ");
    scanf("%d %d", &a, &b);

    a = a + b;
    b = a - b;
    a = a - b;
    printf("Swapped (without third): a = %d, b = %d\n", a, b);

    return 0;
}
