#include <stdio.h>
#define MAX 10

int Q[MAX];
int f = -1, r = -1;

void insert(int x);
int delete();
int peek();
void display();

int main() {
    int choice, x;

    do {
        printf("\n===== LINEAR QUEUE MENU =====\n");
        printf("1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                x = delete();
                if (x != -1)
                    printf("The number deleted is: %d\n", x);
                break;
            case 3:
                x = peek();
                if (x != -1)
                    printf("The first value in the queue is: %d\n", x);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 5);

    return 0;
}

// Insert an element into the queue
void insert(int x) {
    if (r == MAX - 1) {
        printf("OVERFLOW\n");
        return;
    }
    if (f == -1 && r == -1)
        f = r = 0;
    else
        r++;
    Q[r] = x;
}

// Delete an element from the queue
int delete() {
    int val;

    if (f == -1 || f > r) {
        printf("UNDERFLOW\n");
        return -1;
    }

    val = Q[f];
    if (f == r)
        f = r = -1;
    else
        f++;
    return val;
}

// Peek the first element
int peek() {
    if (f == -1 || f > r) {
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    return Q[f];
}

// Display queue elements
void display() {
    int i;
    if (f == -1 || f > r) {
        printf("QUEUE IS EMPTY\n");
        return;
    }

    printf("Queue contents: ");
    for (i = f; i <= r; i++)
        printf("%d ", Q[i]);
    printf("\n");
}
