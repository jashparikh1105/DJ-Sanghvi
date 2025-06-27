#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towers(int num, char frompeg, char topeg, char auxpeg) {
    if (num == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", frompeg, topeg);
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("Move disk %d from peg %c to peg %c\n", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}

int main() {
    int n;

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("The sequence of moves involved are:\n");
    towers(n, 'A', 'C', 'B');  // A = source, C = destination, B = auxiliary

    return 0;
}
