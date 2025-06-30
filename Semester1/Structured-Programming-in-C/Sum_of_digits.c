#include <stdio.h>

int main() {
    int num, sum = 0;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    if (num < 100 || num > 999) {
        printf("Not a 3-digit number.\n");
        return 1;
    }

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    printf("Sum of digits: %d\n", sum);
    return 0;
}
