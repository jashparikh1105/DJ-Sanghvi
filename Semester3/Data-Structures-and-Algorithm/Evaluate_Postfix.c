#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAX 100

float st[MAX];
int top = -1;

void push(float);
float pop();
float evaluatePostfixExp(char exp[]);

void main() {
    float val;
    char exp[100];
    clrscr();

    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter any postfix expression: \n");
    gets(exp);  // Use fgets() in modern compilers

    val = evaluatePostfixExp(exp);
    printf("Value of the postfix expression = %.2f\n", val);

    getch();
}

float evaluatePostfixExp(char exp[]) {
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push((float)(exp[i] - '0'));
        } else if (exp[i] == ' ') {
            // Ignore spaces
        } else {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/': value = op1 / op2; break;
                case '%': value = (int)op1 % (int)op2; break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    return -1;
            }

            push(value);
        }
        i++;
    }

    return pop();
}

void push(float val) {
    if (top == MAX - 1)
        printf("STACK OVERFLOW\n");
    else
        st[++top] = val;
}

float pop() {
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
        return -1;
    } else {
        return st[top--];
    }
}
