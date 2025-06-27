#include <stdio.h>
#include <conio.h>
#include <string.h>

int st[10], top = -1;

int pop();
void push(int);
int get_type(char);

void main() {
    char prefix[10];
    int len, val, i, opr1, opr2, res;

    clrscr();
    printf("Jash Parikh, C065, 60004220080\n");
    printf("Enter the prefix expression:\n");
    gets(prefix);  // Note: `gets` is unsafe and deprecated. Use `fgets` in real applications.

    len = strlen(prefix);

    for(i = len - 1; i >= 0; i--) {
        switch(get_type(prefix[i])) {
            case 0:  // Operand
                val = prefix[i] - '0';  // Assumes single-digit numbers
                push(val);
                break;

            case 1:  // Operator
                opr1 = pop();
                opr2 = pop();

                switch(prefix[i]) {
                    case '+':
                        res = opr1 + opr2;
                        break;
                    case '-':
                        res = opr1 - opr2;
                        break;
                    case '*':
                        res = opr1 * opr2;
                        break;
                    case '/':
                        res = opr1 / opr2;
                        break;
                }

                push(res);
                break;
        }
    }

    printf("RESULT = %d\n", st[0]);
    getch();
}

void push(int val) {
    st[++top] = val;
}

int pop() {
    return st[top--];
}

int get_type(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;  // Operator
    else
        return 0;  // Operand
}
