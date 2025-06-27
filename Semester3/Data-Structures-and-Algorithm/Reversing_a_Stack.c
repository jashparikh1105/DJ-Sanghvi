#include <stdio.h>
#include <conio.h>
#define MAX 10

int top = -1, st[MAX];

void push(int);
int pop();

void main() {
    int a[MAX], i, n;
    clrscr();

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        push(a[i]);
    }

    for(i = 0; i < n; i++) {
        a[i] = pop();
    }

    printf("Reversed Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    getch();
}

// Push operation
void push(int val) {
    if(top == MAX - 1)
        printf("Stack overflow\n");
    else
        st[++top] = val;
}

// Pop operation
int pop() {
    if(top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return st[top--];
    }
}
