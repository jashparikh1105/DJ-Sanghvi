#include <stdio.h>
#include <conio.h>

#define MAX 10

int st[MAX], top = -1;

void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

void main() {
    int choice, val;
    clrscr();
    
    do {
        printf("\nPress:\n 1 for Push\n 2 for Pop\n 3 for Peek\n 4 for Display\n 5 to Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &val);
                push(st, val);
                break;

            case 2:
                val = pop(st);
                if (val == -1)
                    printf("Stack Underflow! Nothing to pop.\n");
                else
                    printf("Popped element is %d\n", val);
                break;

            case 3:
                val = peek(st);
                if (val == -1)
                    printf("Stack is empty!\n");
                else
                    printf("Top element is %d\n", val);
                break;

            case 4:
                display(st);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    getch();
}

void push(int st[], int val) {
    if (top == MAX - 1)
        printf("Stack Overflow! Cannot push %d\n", val);
    else
        st[++top] = val;
}

int pop(int st[]) {
    if (top == -1) {
        return -1;
    } else {
        return st[top--];
    }
}

int peek(int st[]) {
    if (top == -1) {
        return -1;
    } else {
        return st[top];
    }
}

void display(int st[]) {
    int i;
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d ", st[i]);
        }
        printf("\n");
    }
}
