#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10

char st[MAX];
int top = -1;

void infixToPostfix(char source[], char target[]);
int getPriority(char);
void push(char);
char pop();

void main() {
    char infix[MAX], postfix[MAX];
    clrscr();

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter an expression:\n");
    gets(infix);  // Use fgets for modern compilers

    strcpy(postfix, "");
    infixToPostfix(infix, postfix);

    printf("The postfix expression is:\n");
    puts(postfix);

    getch();
}

void infixToPostfix(char source[], char target[]) {
    int i = 0, j = 0;
    char temp;

    strcpy(target, "");

    while(source[i] != '\0') {
        if(source[i] == '(') {
            push(source[i]);
            i++;
        }
        else if(source[i] == ')') {
            while((top != -1) && (st[top] != '(')) {
                target[j++] = pop();
            }
            if(top == -1) {
                printf("Incorrect Expression\n");
                exit(1);
            }
            pop(); // pop '('
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i])) {
            target[j++] = source[i++];
        }
        else if(source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                source[i] == '/' || source[i] == '%' || source[i] == '^') {
            while((top != -1) && (st[top] != '(') && 
                  (getPriority(st[top]) >= getPriority(source[i]))) {
                target[j++] = pop();
            }
            push(source[i]);
            i++;
        }
        else {
            printf("Invalid character in expression\n");
            exit(1);
        }
    }

    while((top != -1) && (st[top] != '(')) {
        target[j++] = pop();
    }

    target[j] = '\0';
}

int getPriority(char ch) {
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void push(char val) {
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
        st[++top] = val;
}

char pop() {
    char val = ' ';
    if(top == -1)
        printf("Stack Underflow\n");
    else
        val = st[top--];
    return val;
}
