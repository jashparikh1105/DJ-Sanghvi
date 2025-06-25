#include <stdio.h> 
#include <math.h> 
 
// Power function to return value of a^b mod P 
long long int power(long long int a, long long int b, long long int P) { 
    if (b == 1) 
        return a; 
    else 
        return (((long long int)pow(a, b)) % P); 
} 
 
// Driver program 
int main() { 
    long long int P, G, x, a, y, b, ka, kb; 
 
    // Taking user input for P and G 
    printf("Enter the value of P (prime number): "); 
    scanf("%lld", &P); 
 
    printf("Enter the value of G (primitive root of P): "); 
    scanf("%lld", &G); 
 
    // Alice chooses private key a 
    printf("Enter the private key a for Alice: "); 
    scanf("%lld", &a); 
 
    x = power(G, a, P); // generated key for Alice 
    printf("The generated key for Alice: %lld\n", x); 
 
    // Bob chooses private key b 
    printf("Enter the private key b for Bob: "); 
    scanf("%lld", &b); 
 
    y = power(G, b, P); // generated key for Bob 
    printf("The generated key for Bob: %lld\n\n", y); 
 
    // Generating the secret keys 
    ka = power(y, a, P); // Secret key for Alice 
    kb = power(x, b, P); // Secret key for Bob 
 
    printf("Secret key for Alice is : %lld\n", ka); 
    printf("Secret Key for Bob is : %lld\n", kb); 
 
    // Both secret keys should be equal 
    if (ka == kb) 
        printf("The keys match! The secret key is: %lld\n", ka); 
    else 
        printf("There is an error! The keys do not match.\n"); 
 
    return 0; 
}