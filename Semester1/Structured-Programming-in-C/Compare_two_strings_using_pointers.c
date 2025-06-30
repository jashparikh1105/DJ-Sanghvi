#include <stdio.h>

int main() {
    char str1[100], str2[100];
    char *p1, *p2;
    int flag = 1;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    p1 = str1;
    p2 = str2;

    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2) {
            flag = 0;
            break;
        }
        p1++;
        p2++;
    }

    if (*p1 != '\0' || *p2 != '\0') flag = 0;

    if (flag)
        printf("Strings are equal.\n");
    else
        printf("Strings are not equal.\n");

    return 0;
}
