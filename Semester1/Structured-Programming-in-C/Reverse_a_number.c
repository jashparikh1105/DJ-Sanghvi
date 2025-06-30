#include <stdio.h>

int main() {
    int num, reverse = 0, sum = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &num);

    int original = num;

    while (num != 0) {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        sum += digit;
        num /= 10;
    }

    printf("Reversed: %d\n", reverse);
    printf("Sum of digits: %d\n", sum);

    return 0;
}
