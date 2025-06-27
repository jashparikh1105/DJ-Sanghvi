// Circular Doubly Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

// Function prototypes
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);
struct node *search(struct node *);

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Create\n2. Display\n3. Insert at beginning\n4. Insert at end\n5. Insert after\n6. Insert before\n");
        printf("7. Delete beginning\n8. Delete end\n9. Delete after\n10. Delete node\n11. Delete entire list\n12. Search\n13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: start = create(start); break;
            case 2: start = display(start); break;
            case 3: start = insert_beg(start); break;
            case 4: start = insert_end(start); break;
            case 5: start = insert_after(start); break;
            case 6: start = insert_before(start); break;
            case 7: start = delete_beg(start); break;
            case 8: start = delete_end(start); break;
            case 9: start = delete_after(start); break;
            case 10: start = delete_node(start); break;
            case 11: start = delete_list(start); break;
            case 12: start = search(start); break;
            case 13: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 13);
    return 0;
}

struct node *create(struct node *start) {
    struct node *new_node, *ptr;
    int val;
    printf("Enter -1 to stop\n");
    printf("Enter data: ");
    scanf("%d", &val);
    while(val != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = val;
        if(start == NULL) {
            start = new_node;
            new_node->next = start;
            new_node->prev = start;
        } else {
            ptr = start->prev;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = start;
            start->prev = new_node;
        }
        printf("Enter data: ");
        scanf("%d", &val);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr;
    if(start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    ptr = start;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != start);
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node, *end;
    int val;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    if(start == NULL) {
        start = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        end = start->prev;
        new_node->next = start;
        new_node->prev = end;
        end->next = new_node;
        start->prev = new_node;
        start = new_node;
    }
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *new_node, *end;
    int val;
    printf("Enter value to insert at end: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    if(start == NULL) {
        start = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        end = start->prev;
        new_node->next = start;
        new_node->prev = end;
        end->next = new_node;
        start->prev = new_node;
    }
    return start;
}

struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int val, num;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    printf("Enter node after which to insert: ");
    scanf("%d", &num);
    ptr = start;
    do {
        if(ptr->data == num) {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = val;
            new_node->next = ptr->next;
            new_node->prev = ptr;
            ptr->next->prev = new_node;
            ptr->next = new_node;
            return start;
        }
        ptr = ptr->next;
    } while(ptr != start);
    printf("Node not found.\n");
    return start;
}

struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr;
    int val, num;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    printf("Enter node before which to insert: ");
    scanf("%d", &num);
    ptr = start;
    do {
        if(ptr->data == num) {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = val;
            new_node->next = ptr;
            new_node->prev = ptr->prev;
            ptr->prev->next = new_node;
            ptr->prev = new_node;
            if(ptr == start)
                start = new_node;
            return start;
        }
        ptr = ptr->next;
    } while(ptr != start);
    printf("Node not found.\n");
    return start;
}

struct node *delete_beg(struct node *start) {
    struct node *end;
    if(start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    if(start->next == start) {
        free(start);
        return NULL;
    }
    end = start->prev;
    end->next = start->next;
    start->next->prev = end;
    free(start);
    return end->next;
}

struct node *delete_end(struct node *start) {
    struct node *end;
    if(start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    if(start->next == start) {
        free(start);
        return NULL;
    }
    end = start->prev;
    end->prev->next = start;
    start->prev = end->prev;
    free(end);
    return start;
}

struct node *delete_after(struct node *start) {
    struct node *ptr;
    int num;
    printf("Enter node after which to delete: ");
    scanf("%d", &num);
    ptr = start;
    do {
        if(ptr->data == num) {
            struct node *del = ptr->next;
            if(del == start) start = start->next;
            ptr->next = del->next;
            del->next->prev = ptr;
            free(del);
            return start;
        }
        ptr = ptr->next;
    } while(ptr != start);
    printf("Node not found.\n");
    return start;
}

struct node *delete_node(struct node *start) {
    struct node *ptr;
    int num;
    printf("Enter node to delete: ");
    scanf("%d", &num);
    ptr = start;
    do {
        if(ptr->data == num) {
            if(ptr->next == ptr) {
                free(ptr);
                return NULL;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            if(ptr == start) start = start->next;
            free(ptr);
            return start;
        }
        ptr = ptr->next;
    } while(ptr != start);
    printf("Node not found.\n");
    return start;
}

struct node *delete_list(struct node *start) {
    struct node *ptr = start;
    while(start != NULL && start->next != start) {
        ptr = start;
        start = start->next;
        delete_beg(ptr);
    }
    if(start != NULL)
        free(start);
    return NULL;
}

struct node *search(struct node *start) {
    struct node *ptr;
    int val;
    printf("Enter value to search: ");
    scanf("%d", &val);
    ptr = start;
    do {
        if(ptr->data == val) {
            printf("Found\n");
            return start;
        }
        ptr = ptr->next;
    } while(ptr != start);
    printf("Not found\n");
    return start;
}
