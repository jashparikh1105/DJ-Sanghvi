#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
 
#define SIZE 5 
 
char table[SIZE][SIZE]; 
 
// Function to remove duplicate characters from the key 
void remove_duplicates(char *str) { 
    int hash[26] = {0}; 
    int index = 0, i; 
    for (i = 0; str[i]; i++) { 
        if (!hash[str[i] - 'A']) { 
            hash[str[i] - 'A'] = 1; 
            str[index++] = str[i]; 
        } 
    } 
    str[index] = '\0'; 
} 
 
// Function to prepare the key matrix 
void prepare_key(char *key) { 
    strcat(key, "ABCDEFGHIKLMNOPQRSTUVWXYZ"); 
    remove_duplicates(key); 
    int k = 0; 
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { 
            table[i][j] = key[k++]; 
        } 
    } 
} 
 
// Function to find position of a letter in the key matrix 
void find_position(char letter, int *row, int *col) { 
    if (letter == 'J') letter = 'I'; 
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { 
            if (table[i][j] == letter) { 
                *row = i; 
                *col = j; 
                return; 
            } 
        } 
    } 
} 
 
// Function to encrypt a pair of letters 
void encrypt_pair(char a, char b, char *enc_a, char *enc_b) { 
    int r1, c1, r2, c2; 
    find_position(a, &r1, &c1); 
    find_position(b, &r2, &c2); 
 
    if (r1 == r2) { 
        *enc_a = table[r1][(c1 + 1) % SIZE]; 
        *enc_b = table[r2][(c2 + 1) % SIZE]; 
    } else if (c1 == c2) { 
        *enc_a = table[(r1 + 1) % SIZE][c1]; 
        *enc_b = table[(r2 + 1) % SIZE][c2]; 
    } else { 
        *enc_a = table[r1][c2]; 
        *enc_b = table[r2][c1]; 
    } 
} 
 
// Function to decrypt a pair of letters 
void decrypt_pair(char a, char b, char *dec_a, char *dec_b) { 
    int r1, c1, r2, c2; 
    find_position(a, &r1, &c1); 
    find_position(b, &r2, &c2); 
 
    if (r1 == r2) { 
        *dec_a = table[r1][(c1 + SIZE - 1) % SIZE]; 
        *dec_b = table[r2][(c2 + SIZE - 1) % SIZE]; 
    } else if (c1 == c2) { 
        *dec_a = table[(r1 + SIZE - 1) % SIZE][c1]; 
        *dec_b = table[(r2 + SIZE - 1) % SIZE][c2]; 
    } else { 
        *dec_a = table[r1][c2]; 
        *dec_b = table[r2][c1]; 
    } 
} 
 
// Function to format the plaintext for encryption 
void format_text(char *text) { 
    int len = strlen(text), index = 0; 
    char formatted[len * 2]; 
 
    for (int i = 0; i < len; i++) { 
        if (text[i] == 'J') text[i] = 'I'; 
 
        if (i < len - 1 && text[i] == text[i + 1]) { 
            formatted[index++] = text[i]; 
            formatted[index++] = 'X'; 
        } else { 
            formatted[index++] = text[i]; 
        } 
    } 
 
    if (index % 2 != 0) 
        formatted[index++] = 'X'; 
 
    formatted[index] = '\0'; 
    strcpy(text, formatted); 
} 
 
// Function to encrypt the full message 
void playfair_encrypt(char *text, char *result) { 
    format_text(text); 
    for (int i = 0; i < strlen(text); i += 2) { 
        encrypt_pair(text[i], text[i + 1], &result[i], &result[i + 1]); 
    } 
    result[strlen(text)] = '\0'; 
} 
 
// Function to decrypt the full message 
void playfair_decrypt(char *text, char *result) { 
    for (int i = 0; i < strlen(text); i += 2) { 
        decrypt_pair(text[i], text[i + 1], &result[i], &result[i + 1]); 
    } 
    result[strlen(text)] = '\0'; 
} 
 
// Function to print the key matrix 
void print_table() { 
    printf("Playfair Cipher Key Matrix:\n"); 
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { 
            printf("%c ", table[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    char key[100], text[100], encrypted[100], decrypted[100]; 
 
    printf("Enter the key for Playfair cipher: "); 
    scanf("%s", key); 
    prepare_key(key); 
 
    print_table(); 
 
    printf("Enter the plaintext to be encrypted: "); 
    scanf("%s", text); 
 
    playfair_encrypt(text, encrypted); 
    printf("Encrypted Message: %s\n", encrypted); 
 
    playfair_decrypt(encrypted, decrypted); 
    printf("Decrypted Message: %s\n", decrypted); 
 
    return 0; 
} 