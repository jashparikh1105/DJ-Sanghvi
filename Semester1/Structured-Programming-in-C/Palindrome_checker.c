#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int i, len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i])
            return 0;
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
