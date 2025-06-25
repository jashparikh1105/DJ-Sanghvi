#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
 
// Map A=26, B=25, ..., Z=1 
int getReversedAlphabetValue(char ch) { 
    if (isalpha(ch)) { 
        ch = toupper(ch); 
        return 27 - (ch - 'A' + 1);  // 27 - position gives reverse value 
    } 
    return -1; 
} 
 
// Reverse each word in-place (not the sentence) 
void reverseWord(char *start, char *end) { 
    while (start < end) { 
        char temp = *start; 
        *start = *end; 
        *end = temp; 
        start++; 
        end--; 
    } 
} 
 
int main() { 
    char plaintext[100] = "Rohit is best"; 
    char reversed[100]; 
    strcpy(reversed, plaintext); 
 
    int len = strlen(reversed); 
    char *word_start = NULL; 
 
    // Reverse each word in-place 
    for (int i = 0; i <= len; i++) { 
        if (isalpha(reversed[i]) && word_start == NULL) { 
            word_start = &reversed[i]; 
        } 
        if ((reversed[i] == ' ' || reversed[i] == '\0') && word_start != NULL) { 
            reverseWord(word_start, &reversed[i - 1]); 
            word_start = NULL; 
        } 
    } 
 
    // Output 
    printf("Plaintext: %s\n", plaintext); 
    printf("Reversed Text: %s\n", reversed); 
    printf("Ciphertext: "); 
 
    for (int i = 0; i < len; i++) { 
        int val = getReversedAlphabetValue(reversed[i]); 
        if (val != -1) { 
            printf("%02d", val);  // Always print 2-digit value 
        } 
} 
printf("\n"); 
return 0; 
}