#include <stdio.h>
#include <conio.h>

int Fibonacci(int);  // Function prototype

void main() {
    int n, i, res;

    clrscr();  // Clears the screen (useful in Turbo C++)
    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the number of terms\n");
    scanf("%d", &n);

    printf("Fibonacci series:\n");
    for(i = 0; i < n; i++) {
        res = Fibonacci(i);
        printf("%d\t", res);
    }

    getch();  // Wait for key press (Turbo C++)
}

int Fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
