#include <stdio.h>

int main() {
    char ch;
    int lines = 0, words = 0, chars = 0;
    int in_word = 0;

    printf("Enter text (press Ctrl+D or Ctrl+Z to end input):\n");

    while ((ch = getchar()) != EOF) {
        chars++;

        if (ch == '\n')
            lines++;

        if (ch == ' ' || ch == '\n' || ch == '\t')
            in_word = 0;
        else if (in_word == 0) {
            in_word = 1;
            words++;
        }
    }

    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
    return 0;
}
