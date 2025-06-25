#include <stdio.h>
#include <math.h>

// Function to calculate parity for a given position
int hamming_calculate(int position, int length, int code[]) 
{
    int count = 0;
    int i, j;
    i = position - 1;
    while (i < length) 
    {
        for (j = i; j < i + position && j < length; j++) 
        {
            if (code[j] == 1) 
            {
                count++;
            }
        }
        i = i + 2 * position;
    }
    return count % 2;
}
// Function to print the Hamming Code
void print(int length, int code[]) 
{
    for (int i = 0; i < length; i++) 
    {
        printf(" %d ", code[i]);
    }
    printf("\n");
}
int main() 
{
    int n, p;
    printf("Enter the size of hamming code: ");
    scanf("%d", &n);
     for (int i = 1; i < n; i++) 
    {
        if (pow(2, i) >= n + i + 1) 
        {
            p = i;
            break;
        }
    }
    int totalLength = n + p;
    int code[totalLength];
    printf("Enter the received Hamming code (including parity bits):\n");
    for (int i = 0; i < totalLength; i++) 
    {
        printf("Bit %d: ", i + 1);
        scanf("%d", &code[i]);
    }
    printf("\nReceived Hamming Code: \n");
    print(totalLength, code);

    // Error detection and correction
    int errorPosition = 0;
    for (int i = 0; i < p; i++) 
    {
        int position = pow(2, i);
        int parity = hamming_calculate(position, totalLength, code);
        if (parity != 0) 
        {
            errorPosition += position;
        }
    }
    if (errorPosition == 0) 
    {
        printf("\nNo error detected in the received Hamming Code.\n");
    } 
    else 
    {
        printf("\nError detected at bit position: %d (1-based index).\n", errorPosition);

        // Correct the error
        code[errorPosition - 1] ^= 1; // Flip the erroneous bit
         printf("\nCorrected Hamming Code: \n");
        print(totalLength, code);
    }
    return 0;
}
