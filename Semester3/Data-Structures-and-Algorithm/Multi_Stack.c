#include <stdio.h>
#include <conio.h>
#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

// Push into Stack A
void pushA(int val) {
    if (topA == topB - 1) {
        printf("\nOVERFLOW in Stack A");
    } else {
        topA++;
        stack[topA] = val;
    }
}

// Pop from Stack A
int popA() {
    int val;
    if (topA == -1) {
        printf("\nUNDERFLOW in Stack A");
        return -999;
    } else {
        val = stack[topA];
        topA--;
        return val;
    }
}

// Display Stack A
void display_stackA() {
    int i;
    if (topA == -1) {
        printf("\nStack A is Empty");
    } else {
        for (i = topA; i >= 0; i--) {
            printf("\t%d", stack[i]);
        }
    }
}

// Push into Stack B
void pushB(int val) {
    if (topB - 1 == topA) {
        printf("\nOVERFLOW in Stack B");
    } else {
        topB--;
        stack[topB] = val;
    }
}

// Pop from Stack B
int popB() {
    int val;
    if (topB == MAX) {
        printf("\nUNDERFLOW in Stack B");
        return -999;
    } else {
        val = stack[topB];
        topB++;
        return val;
    }
}

// Display Stack B
void display_stackB() {
    int i;
    if (topB == MAX) {
        printf("\nStack B is Empty");
    } else {
        for (i = topB; i < MAX; i++) {
            printf("\t%d", stack[i]);
        }
    }
}

// Main function
void main() {
    int option, val;
    clrscr();
    do {
        printf("\n\n***** MENU *****");
        printf("\n1. PUSH IN STACK A");
        printf("\n2. PUSH IN STACK B");
        printf("\n3. POP FROM STACK A");
        printf("\n4. POP FROM STACK B");
        printf("\n5. DISPLAY STACK A");
        printf("\n6. DISPLAY STACK B");
        printf("\n7. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value to push in Stack A: ");
                scanf("%d", &val);
                pushA(val);
                break;
            case 2:
                printf("Enter value to push in Stack B: ");
                scanf("%d", &val);
                pushB(val);
                break;
            case 3:
                val = popA();
                if (val != -999)
                    printf("Popped from Stack A: %d", val);
                break;
            case 4:
                val = popB();
                if (val != -999)
                    printf("Popped from Stack B: %d", val);
                break;
            case 5:
                printf("Contents of Stack A:\n");
                display_stackA();
                break;
            case 6:
                printf("Contents of Stack B:\n");
                display_stackB();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.");
        }
    } while (option != 7);
    getch();
}
