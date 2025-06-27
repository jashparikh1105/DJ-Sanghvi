#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = val;
    }
}

int dequeue() {
    int val;
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else if (front == rear) {
        val = queue[front];
        front = rear = -1;
    } else {
        val = queue[front];
        front = (front + 1) % MAX;
    }
    return val;
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    enqueue(50);
    enqueue(60);
    display();
    return 0;
}
