#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 10

int top = -1, st[MAX];

void push(char);
char pop();

void main() {
    int i, flag = 1;
    char exp[MAX], temp;

    clrscr();

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the expression: ");
    gets(exp);  // Use fgets(exp, MAX, stdin) in modern compilers

    for(i = 0; i < strlen(exp); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == -1) {
                flag = 0;
                break;
            } else {
                temp = pop();
                if((exp[i] == ')' && (temp == '{' || temp == '[')) ||
                   (exp[i] == '}' && (temp == '(' || temp == '[')) ||
                   (exp[i] == ']' && (temp == '{' || temp == '('))) {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if(top >= 0) {
        flag = 0;
    }

    if(flag == 1)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");

    getch();
}

void push(char c) {
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
        st[++top] = c;
}

char pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return st[top--];
    }
}
