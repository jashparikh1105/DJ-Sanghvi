#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char infix[MAX], postfix[MAX], temp[MAX];  // global declarations
char stack[MAX];
int top = -1;

void reverse(char str[]);
void infixToPostfix(char infix[], char postfix[]);
int getPriority(char ch);
void push(char val);
char pop();

void main() {
    clrscr();

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter any infix expression:\n");
    gets(infix);  // deprecated, use fgets in modern C

    reverse(infix);
    strcpy(postfix, "");
    infixToPostfix(temp, postfix);

    printf("Postfix expression is:\n");
    puts(postfix);

    strcpy(temp, "");
    reverse(postfix);
    strcpy(temp, postfix); // temp holds the prefix now

    printf("Prefix expression is:\n");
    puts(temp);

    getch();
}

// Reverse the infix or postfix string and store result in temp
void reverse(char str[]) {
    int len = strlen(str), i = 0, j = len - 1;

    while (j >= 0) {
        if (str[j] == '(')
            temp[i] = ')';
        else if (str[j] == ')')
            temp[i] = '(';
        else
            temp[i] = str[j];
        i++;
        j--;
    }
    temp[i] = '\0';
}

// Convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top == -1) {
                printf("Invalid Expression!\n");
                exit(1);
            }
            pop();  // Pop '('
        } else {
            while (top != -1 && getPriority(stack[top]) >= getPriority(ch))
                postfix[j++] = pop();
            push(ch);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Get operator precedence
int getPriority(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Stack operations
void push(char val) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
