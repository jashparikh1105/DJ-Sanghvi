#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // (a) Using modulus operator
    if (num % 2 == 0)
        printf("Even (using modulus)\n");
    else
        printf("Odd (using modulus)\n");

    // (b) Using conditional operator
    (num % 2 == 0) ? printf("Even (using conditional)\n") : printf("Odd (using conditional)\n");

    return 0;
}
