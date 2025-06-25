#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 
// Function to print the encryption matrix 
void PrintMatrix(int no_rows, int len_key, char enc_mat[no_rows + 1][len_key]) { 
    for (int i = 0; i < no_rows + 1; i++) { 
        for (int j = 0; j < len_key; j++) { 
            printf("%c ", enc_mat[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
// Function to print the key matrix 
void PrintKeyMatrix(int len_key, char key[], int col_val[]) { 
    printf("\nKey Matrix:\n"); 
    for (int i = 0; i < len_key; i++) { 
        printf("%c ", key[i]); 
    } 
    printf("\n"); 
    for (int i = 0; i < len_key; i++) { 
        printf("%d ", col_val[i]); 
    } 
    printf("\n"); 
} 
 
// Encryption function 
void Encryption(int no_rows, int len_key, int len_msg, char msg[], int col_val[], char cipher[]) { 
    int x = 0; 
    char enc_mat[no_rows + 1][len_key]; 
 
    // Fill the matrix with the message 
    for (int i = 0; i < no_rows + 1; i++) { 
        for (int j = 0; j < len_key; j++) { 
            if (x >= len_msg) { 
                enc_mat[i][j] = '_'; // Padding 
            } else { 
                enc_mat[i][j] = msg[x]; 
            } 
            x++; 
        } 
    } 
 
    PrintMatrix(no_rows, len_key, enc_mat); 
 
    // Read matrix column-wise based on key order 
    int t = 1; 
    int index = 0; 
    while (t <= len_key) { 
        for (int i = 0; i < len_key; i++) { 
            if (col_val[i] == t) { 
                for (int j = 0; j < no_rows + 1; j++) { 
                    cipher[index++] = enc_mat[j][i]; 
                } 
                t++; 
            } 
        } 
    } 
    cipher[index] = '\0'; 
} 
 
// Decryption function 
void Decryption(int no_rows, int len_key, char cipher[], int col_val[], char message[]) { 
    char dec_mat[no_rows + 1][len_key]; 
    int x = 0, t = 1; 
 
    // Fill the matrix column-wise based on key order 
    while (t <= len_key) { 
        for (int i = 0; i < len_key; i++) { 
            if (col_val[i] == t) { 
                for (int j = 0; j < no_rows + 1; j++) { 
                    dec_mat[j][i] = cipher[x++]; 
                } 
                t++; 
            } 
        } 
    } 
 
    // Read the matrix row-wise 
    int index = 0; 
    for (int i = 0; i < no_rows + 1; i++) { 
        for (int j = 0; j < len_key; j++) { 
            if (dec_mat[i][j] == '_') { 
                dec_mat[i][j] = ' '; // Replace padding with space 
            } 
            message[index++] = dec_mat[i][j]; 
        } 
    } 
    message[index] = '\0'; 
} 
 
int main() { 
    char msg[100], key[20]; 
 
    printf("Enter the message: "); 
    fgets(msg, sizeof(msg), stdin); 
    msg[strcspn(msg, "\n")] = 0; 
 
    printf("Enter the key: "); 
    fgets(key, sizeof(key), stdin); 
    key[strcspn(key, "\n")] = 0; 
 
    int len_key = strlen(key); 
    int len_msg = strlen(msg); 
    int col_val[len_key]; 
    memset(col_val, 0, sizeof(col_val)); 
 
    // Generate column order based on key's alphabetical order 
    int val = 1, count = 0, ind; 
    while (count < len_key) { 
        int min = 999; 
        for (int i = 0; i < len_key; i++) { 
            if ((min > (int)key[i]) && (col_val[i] == 0)) { 
                min = (int)key[i]; 
                ind = i; 
            } 
        } 
        col_val[ind] = val++; 
        count++; 
    } 
 
    PrintKeyMatrix(len_key, key, col_val); 
 
    int no_rows = len_msg / len_key; 
    if (len_msg % len_key != 0) no_rows++; 
char cipher_text[200], original_msg[200]; 
Encryption(no_rows, len_key, len_msg, msg, col_val, cipher_text); 
printf("Encrypted Message: %s\n", cipher_text); 
Decryption(no_rows, len_key, cipher_text, col_val, original_msg); 
printf("Decrypted Message: %s\n", original_msg); 
return 0; 
}