#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
 
#define MAX_TEXT 100 
 
void formatKey(char *key) { 
    int len = strlen(key); 
    for (int i = 0; i < len; i++) { 
        if (islower(key[i])) 
            key[i] = toupper(key[i]); 
    } 
} 
 
void encrypt(char *text, char *key, char *result) { 
    int textLen = strlen(text); 
    int keyLen = strlen(key); 
    int j = 0; 
 
    for (int i = 0; i < textLen; i++) { 
        char c = text[i]; 
 
        if (islower(c)) 
            c = toupper(c); 
 
        if (!isalpha(c)) { 
            result[i] = text[i]; 
            continue; 
        } 
 
        result[i] = ((c + key[j] - 2 * 'A') % 26) + 'A'; 
        j = (j + 1) % keyLen; 
    } 
 
    result[textLen] = '\0'; 
} 
 
void decrypt(char *text, char *key, char *result) { 
    int textLen = strlen(text); 
    int keyLen = strlen(key); 
    int j = 0; 
 
    for (int i = 0; i < textLen; i++) { 
        char c = text[i]; 
 
        if (islower(c)) 
            c = toupper(c); 
 
        if (!isalpha(c)) { 
            result[i] = text[i]; 
            continue; 
        } 
 
        result[i] = ((c - key[j] + 26) % 26) + 'A'; 
        j = (j + 1) % keyLen; 
    } 
 
    result[textLen] = '\0'; 
} 
 
int main() { 
    char text[MAX_TEXT], key[MAX_TEXT], encrypted[MAX_TEXT], decrypted[MAX_TEXT]; 
 
    printf("Enter the text: "); 
    fgets(text, MAX_TEXT, stdin); 
    text[strcspn(text, "\n")] = '\0'; 
 
    printf("Enter the key: "); 
    fgets(key, MAX_TEXT, stdin); 
    key[strcspn(key, "\n")] = '\0'; 
 
    formatKey(key); 
 
    encrypt(text, key, encrypted); 
    decrypt(encrypted, key, decrypted); 
 
    printf("Original: %s\n", text); 
    printf("Encrypted: %s\n", encrypted); 
    printf("Decrypted: %s\n", decrypted); 
 
    return 0; 
}