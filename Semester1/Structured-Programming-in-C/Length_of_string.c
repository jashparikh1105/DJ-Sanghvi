#include <stdio.h>

int main() {
    char str[100];
    char *ptr;
    int length = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    ptr = str;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    printf("Length of string: %d\n", length);
    return 0;
}
