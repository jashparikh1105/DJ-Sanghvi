#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h> 
 
#define MAX_KEY_LEN 20 
#define MAX_TEXT_LEN 200 
#define MAX_ROUNDS 10 
 
// Generate the order of columns based on the key (sorted index) 
void generate_column_order(const char *key, int len_key, int col_order[]) { 
    int i, j, index = 0; 
    char sorted_key[MAX_KEY_LEN]; 
    strcpy(sorted_key, key); 
 
    // Sort the key to find the order 
    for (i = 0; i < len_key - 1; i++) { 
        for (j = i + 1; j < len_key; j++) { 
            if (sorted_key[i] > sorted_key[j]) { 
                char temp = sorted_key[i]; 
                sorted_key[i] = sorted_key[j]; 
                sorted_key[j] = temp; 
            } 
        } 
    } 
 
    // Generate column order 
    for (i = 0; i < len_key; i++) { 
        for (j = 0; j < len_key; j++) { 
            if (key[j] == sorted_key[i] && col_order[j] == -1) { 
                col_order[j] = index++; 
                break; 
            } 
        } 
    } 
} 
 
// Encrypt the plain text using the key 
void encrypt(const char *key, const char *plain_text, char *cipher_text) { 
    int len_key = strlen(key); 
    int len_text = strlen(plain_text); 
    int num_rows = (int)ceil((double)len_text / len_key); 
 
    char matrix[num_rows][len_key]; 
    int col_order[len_key]; 
    memset(matrix, 'X', sizeof(matrix)); 
    memset(col_order, -1, sizeof(col_order)); 
 
    int index = 0; 
    for (int i = 0; i < num_rows; i++) { 
        for (int j = 0; j < len_key; j++) { 
            if (index < len_text) 
                matrix[i][j] = plain_text[index++]; 
        } 
    } 
 
    generate_column_order(key, len_key, col_order); 
 
    index = 0; 
    for (int i = 0; i < len_key; i++) { 
        int col = -1; 
        for (int j = 0; j < len_key; j++) { 
            if (col_order[j] == i) { 
                col = j; 
                break; 
            } 
        } 
        for (int r = 0; r < num_rows; r++) { 
            cipher_text[index++] = matrix[r][col]; 
        } 
    } 
    cipher_text[index] = '\0'; 
} 
 
// Decrypt the cipher text using the key 
void decrypt(const char *key, const char *cipher_text, char *decrypted_text) { 
    int len_key = strlen(key); 
    int len_cipher = strlen(cipher_text); 
    int num_rows = (int)ceil((double)len_cipher / len_key); 
 
    char matrix[num_rows][len_key]; 
    int col_order[len_key]; 
    memset(matrix, 'X', sizeof(matrix)); 
    memset(col_order, -1, sizeof(col_order)); 
 
    generate_column_order(key, len_key, col_order); 
 
    int index = 0; 
    for (int i = 0; i < len_key; i++) { 
        int col = -1; 
        for (int j = 0; j < len_key; j++) { 
            if (col_order[j] == i) { 
                col = j; 
                break; 
            } 
        } 
        for (int r = 0; r < num_rows; r++) { 
            matrix[r][col] = cipher_text[index++]; 
        } 
    } 
 
    index = 0; 
    for (int i = 0; i < num_rows; i++) { 
        for (int j = 0; j < len_key; j++) { 
            if (matrix[i][j] != 'X') 
                decrypted_text[index++] = matrix[i][j]; 
        } 
    } 
    decrypted_text[index] = '\0'; 
} 
 
// Main function handling multiple rounds (double or more transposition) 
int main() { 
    int num_rounds; 
    char keys[MAX_ROUNDS][MAX_KEY_LEN], plain_text[MAX_TEXT_LEN]; 
 
    printf("Enter number of encryption rounds: "); 
    scanf("%d", &num_rounds); 
    getchar(); 
 
    for (int i = 0; i < num_rounds; i++) { 
        printf("Enter keyword %d (Unique letters only): ", i + 1); 
        fgets(keys[i], MAX_KEY_LEN, stdin); 
        keys[i][strcspn(keys[i], "\n")] = 0; 
    } 
 
    printf("Enter plain text (Letters only): "); 
    fgets(plain_text, MAX_TEXT_LEN, stdin); 
    plain_text[strcspn(plain_text, "\n")] = 0; 
 
    char cipher_text[MAX_TEXT_LEN], decrypted_text[MAX_TEXT_LEN]; 
    strcpy(cipher_text, plain_text); 
 
    printf("\nEncryption Process\n"); 
    for (int i = 0; i < num_rounds; i++) { 
        char temp[MAX_TEXT_LEN]; 
        encrypt(keys[i], cipher_text, temp); 
        strcpy(cipher_text, temp); 
        printf("Round %d Cipher Text using Key %d: %s\n", i + 1, i + 1, cipher_text); 
    } 
 
    strcpy(decrypted_text, cipher_text); 
 
    printf("\nDecryption Process\n"); 
    for (int i = num_rounds - 1; i >= 0; i--) { 
        char temp[MAX_TEXT_LEN]; 
        decrypt(keys[i], decrypted_text, temp); 
        strcpy(decrypted_text, temp); 
printf("Round %d Decrypted Text using Key %d: %s\n", num_rounds - i, i + 1, 
decrypted_text); 
} 
printf("\nFinal Results\n"); 
printf("Original Plain Text: %s\n", plain_text); 
printf("Final Cipher Text: %s\n", cipher_text); 
printf("Final Decrypted Text: %s\n", decrypted_text); 
return 0; 
}