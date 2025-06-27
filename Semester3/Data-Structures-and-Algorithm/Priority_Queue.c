#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *start = NULL;

// Function Prototypes
struct node *insert(struct node *);
struct node *delete_node(struct node *);
void display(struct node *);

int main() {
    int option;

    do {
        printf("\n***** MAIN MENU *****\n");
        printf("1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                start = insert(start);
                break;
            case 2:
                start = delete_node(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(option != 4);

    return 0;
}

// Insert a node based on priority
struct node *insert(struct node *start) {
    int val, pri;
    struct node *ptr, *p;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }

    printf("Enter the value and its priority: ");
    scanf("%d%d", &val, &pri);

    ptr->data = val;
    ptr->priority = pri;
    ptr->next = NULL;

    // Insert at beginning or before the first lower-priority node
    if(start == NULL || pri < start->priority) {
        ptr->next = start;
        start = ptr;
    } else {
        p = start;
        while(p->next != NULL && p->next->priority <= pri)
            p = p->next;
        ptr->next = p->next;
        p->next = ptr;
    }

    return start;
}

// Delete the highest priority node (head)
struct node *delete_node(struct node *start) {
    struct node *ptr;

    if(start == NULL) {
        printf("UNDERFLOW - Queue is empty.\n");
        return start;
    }

    ptr = start;
    printf("Deleted item is: %d (Priority: %d)\n", ptr->data, ptr->priority);
    start = start->next;
    free(ptr);

    return start;
}

// Display the priority queue
void display(struct node *start) {
    struct node *ptr = start;

    if(start == NULL) {
        printf("QUEUE IS EMPTY\n");
        return;
    }

    printf("PRIORITY QUEUE IS:\n");
    while(ptr != NULL) {
        printf("%d[priority=%d] -> ", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
