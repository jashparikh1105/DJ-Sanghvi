#include <stdio.h>

int stack[100];
int top = -1;
int totalCost = 0;

void push(int x) {
    stack[++top] = x;
    totalCost++;
    printf("Pushed %d, Total Cost: %d\n", x, totalCost);
}

void multiPop(int k) {
    int actualPop = 0;
    for (int i = 0; i < k && top != -1; i++) {
        printf("Popped %d\n", stack[top--]);
        totalCost++;
        actualPop++;
    }
    printf("Total cost for multiPop(%d): %d\n", actualPop, totalCost);
}

int main() {
    push(1);
    push(2);
    push(3);
    multiPop(2);
    return 0;
}
