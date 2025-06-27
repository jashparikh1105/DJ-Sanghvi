#include <stdio.h>
#include <conio.h>

int GCD(int, int);  // Function declaration

void main() {
    int num1, num2, res;

    clrscr();  // Clears screen (only for Turbo C/C++ compilers)
    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the two numbers: \n");
    scanf("%d%d", &num1, &num2);

    res = GCD(num1, num2);
    printf("GCD of %d and %d = %d", num1, num2, res);

    getch();  // Waits for a key press (only for Turbo C/C++)
}

int GCD(int x, int y) {
    int rem;
    rem = x % y;

    if(rem == 0)
        return y;
    else
        return GCD(y, rem);
}
