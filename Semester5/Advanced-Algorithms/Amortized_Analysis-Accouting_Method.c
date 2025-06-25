#include <stdio.h>

int stack[100];
int top = -1;
int cost = 0;

void push(int x) {
    stack[++top] = x;
    cost += 2;
    printf("Pushed %d, Cost: %d\n", x, cost);
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped %d, Cost: %d\n", stack[top--], cost);
    cost--;
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    return 0;
}
