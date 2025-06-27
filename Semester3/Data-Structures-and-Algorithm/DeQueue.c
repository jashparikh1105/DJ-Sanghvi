#include <stdio.h>
#define MAX 10

int deque[MAX];
int left = -1, right = -1;

// Function Prototypes
void input_deque(void);
void output_deque(void);
void insert_left(void);
void insert_right(void);
void delete_left(void);
void delete_right(void);
void display(void);

int main() {
    int option;
    do {
        printf("\n***** MAIN MENU *****\n");
        printf("1. Input Restricted Deque\n");
        printf("2. Output Restricted Deque\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1: input_deque(); break;
            case 2: output_deque(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(option != 3);

    return 0;
}

// Input Restricted Deque Menu
void input_deque() {
    int option;
    do {
        printf("\n--- INPUT RESTRICTED DEQUE ---\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1: insert_right(); break;
            case 2: delete_left(); break;
            case 3: delete_right(); break;
            case 4: display(); break;
            case 5: break;
            default: printf("Invalid choice\n");
        }
    } while(option != 5);
}

// Output Restricted Deque Menu
void output_deque() {
    int option;
    do {
        printf("\n--- OUTPUT RESTRICTED DEQUE ---\n");
        printf("1. Insert at right\n");
        printf("2. Insert at left\n");
        printf("3. Delete from left\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1: insert_right(); break;
            case 2: insert_left(); break;
            case 3: delete_left(); break;
            case 4: display(); break;
            case 5: break;
            default: printf("Invalid choice\n");
        }
    } while(option != 5);
}

// Insert at right
void insert_right() {
    int val;
    printf("Enter the value to be added: ");
    scanf("%d", &val);

    if ((left == 0 && right == MAX-1) || (left == right + 1)) {
        printf("OVERFLOW\n");
        return;
    }

    if (left == -1) {
        left = right = 0;
    } else if (right == MAX - 1) {
        right = 0;
    } else {
        right++;
    }

    deque[right] = val;
}

// Insert at left
void insert_left() {
    int val;
    printf("Enter the value to be added: ");
    scanf("%d", &val);

    if ((left == 0 && right == MAX-1) || (left == right + 1)) {
        printf("OVERFLOW\n");
        return;
    }

    if (left == -1) {
        left = right = 0;
    } else if (left == 0) {
        left = MAX - 1;
    } else {
        left--;
    }

    deque[left] = val;
}

// Delete from left
void delete_left() {
    if (left == -1) {
        printf("UNDERFLOW\n");
        return;
    }

    printf("The deleted element is: %d\n", deque[left]);

    if (left == right) {
        left = right = -1;
    } else if (left == MAX - 1) {
        left = 0;
    } else {
        left++;
    }
}

// Delete from right
void delete_right() {
    if (left == -1) {
        printf("UNDERFLOW\n");
        return;
    }

    printf("The deleted element is: %d\n", deque[right]);

    if (left == right) {
        left = right = -1;
    } else if (right == 0) {
        right = MAX - 1;
    } else {
        right--;
    }
}

// Display deque
void display() {
    int i = left;

    if (left == -1) {
        printf("QUEUE IS EMPTY\n");
        return;
    }

    printf("The elements of the deque are: ");

    if (left <= right) {
        while (i <= right) {
            printf("%d ", deque[i]);
            i++;
        }
    } else {
        while (i < MAX) {
            printf("%d ", deque[i]);
            i++;
        }
        i = 0;
        while (i <= right) {
            printf("%d ", deque[i]);
            i++;
        }
    }
    printf("\n");
}
