#include <stdio.h>  
#include <string.h>  
#include <math.h>  
 
// Function to compute base^expo mod m  
int power(int base, int expo, int m) {  
    int res = 1;  
    base = base % m;  
    while (expo > 0) {  
        if (expo & 1)  
            res = (res * 1LL * base) % m;  
        base = (base * 1LL * base) % m;  
        expo = expo / 2;  
    }  
    return res;  
}  
 
// Function to find modular inverse of e modulo phi(n)  
int modInverse(int e, int phi) {  
    for (int d = 2; d < phi; d++) {  
        if ((e * d) % phi == 1)  
            return d;  
    }  
    return -1;  
} 
 
// Function to calculate gcd of two numbers  
int gcd(int a, int b) {  
    while (b != 0) {  
        int temp = b;  
        b = a % b;  
        a = temp;  
    }  
    return a;  
}  
 
// RSA Key Generation  
void generateKeys(int* e, int* d, int* n, int p, int q) {  
    *n = p * q;  
    int phi = (p - 1) * (q - 1);  
 
    // Choose e, where 1 < e < phi(n) and gcd(e, phi(n)) == 1  
    for (*e = 2; *e < phi; (*e)++) {  
        if (gcd(*e, phi) == 1)  
            break;  
    }  
 
    // Compute d such that e * d ≡ 1 (mod phi(n))  
    *d = modInverse(*e, phi);  
}  
 
// Encrypt message using public key (e, n)  
int encrypt(int m, int e, int n) {  
    if (m >= n) {  
        printf("Error: Message value %d exceeds the modulus n=%d\n", m, n);  
        return -1; // Return -1 if message is too large  
    }  
    return power(m, e, n);  
}  
 
// Decrypt message using private key (d, n)  
int decrypt(int c, int d, int n) {  
    return power(c, d, n);  
}  
 
// Convert plain text to an array of integers (ASCII values)  
void stringToAscii(char* str, int* asciiArr) {  
    int i = 0;  
    while (str[i] != '\0') {  
        asciiArr[i] = (int)str[i];  
        i++;  
    }  
}  
 
// Convert an array of integers (ASCII values) back to string  
void asciiToString(int* asciiArr, int length, char* str) {  
    for (int i = 0; i < length; i++) {  
        str[i] = (char)asciiArr[i];  
    }  
    str[length] = '\0'; // Null-terminate the string  
}  
 
int main() {  
    int e, d, n;  
    int p, q;  
 
    // Take user input for prime numbers p and q  
    printf("Enter a prime number p: ");  
    scanf("%d", &p);  
    printf("Enter a prime number q: ");  
    scanf("%d", &q);  
 
    // Key Generation  
    generateKeys(&e, &d, &n, p, q);  
    printf("Public Key (e, n): (%d, %d)\n", e, n);  
    printf("Private Key (d, n): (%d, %d)\n", d, n);  
 
    // Take user input for the message (plain text)  
    char message[256];  
    printf("Enter the message (plain text): ");  
    getchar(); // To consume the newline character left by previous scanf  
    fgets(message, sizeof(message), stdin);  
 
    // Convert the plain text message to ASCII values  
    int asciiArr[256];  
    stringToAscii(message, asciiArr);  
    printf("Original Message: %s\n", message);  
 
    // Encrypt the message  
    int encryptedMessage[256];  
    int length = strlen(message) - 1; // Exclude the newline character  
    for (int i = 0; i < length; i++) {  
        encryptedMessage[i] = encrypt(asciiArr[i], e, n);  
        if (encryptedMessage[i] == -1) {  
            return 1; // Exit if encryption fails due to large number  
        }  
    }  
 
    // Print encrypted message  
    printf("Encrypted Message (in numbers): ");  
    for (int i = 0; i < length; i++) {  
        printf("%d ", encryptedMessage[i]);  
    }  
    printf("\n");  
 
    // Decrypt the message  
    int decryptedMessage[256];  
    for (int i = 0; i < length; i++) {  
        decryptedMessage[i] = decrypt(encryptedMessage[i], d, n);  
    }  
 
    // Convert decrypted ASCII values back to text  
    char decryptedText[256];  
    asciiToString(decryptedMessage, length, decryptedText);  
    printf("Decrypted Message: %s\n", decryptedText);  
 
    return 0;  
} 