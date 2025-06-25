#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h> 
 
#define MAX_TEXT 100 
 
void generate_key(char *key, int length) { 
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    for (int i = 0; i < length; i++) { 
        key[i] = charset[rand() % (sizeof(charset) - 1)]; 
    } 
    key[length] = '\0'; 
} 
 
void encrypt(char *plaintext, char *key, char *ciphertext) { 
    int length = strlen(plaintext); 
    for (int i = 0; i < length; i++) { 
        ciphertext[i] = plaintext[i] ^ key[i]; 
    } 
    ciphertext[length] = '\0'; 
} 
 
void decrypt(char *ciphertext, char *key, char *decrypted_text) { 
    int length = strlen(ciphertext); 
    for (int i = 0; i < length; i++) { 
        decrypted_text[i] = ciphertext[i] ^ key[i]; 
    } 
    decrypted_text[length] = '\0'; 
} 
 
int main() { 
    srand(time(NULL)); 
 
    char plaintext[MAX_TEXT], key[MAX_TEXT], ciphertext[MAX_TEXT], 
decrypted_text[MAX_TEXT]; 
 
    printf("Enter the plaintext: "); 
    fgets(plaintext, MAX_TEXT, stdin); 
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
 
    generate_key(key, strlen(plaintext)); 
 
    printf("Plaintext: %s\n", plaintext); 
    printf("Key: %s\n", key); 
 
    encrypt(plaintext, key, ciphertext); 
 
    printf("Ciphertext: "); 
    for (int i = 0; i < strlen(plaintext); i++) { 
        printf("%02X", (unsigned char)ciphertext[i]); 
    } 
    printf("\n"); 
 
    decrypt(ciphertext, key, decrypted_text); 
    printf("Decrypted Text: %s\n", decrypted_text); 
 
    return 0; 
}