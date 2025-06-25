#include <stdio.h>

int stack[100];
int top = -1;
int potential = 0;

void push(int x) {
    stack[++top] = x;
    potential++;
    printf("Pushed %d, Potential: %d\n", x, potential);
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped %d, Potential: %d\n", stack[top--], potential);
    potential--;
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    return 0;
}
