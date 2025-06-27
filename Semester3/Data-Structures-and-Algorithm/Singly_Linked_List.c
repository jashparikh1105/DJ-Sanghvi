#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node* create_ll(struct node*);
struct node* display(struct node*);
struct node* insert_beg(struct node*);
struct node* insert_end(struct node*);
struct node* insert_before(struct node*);
struct node* insert_after(struct node*);
struct node* delete_beg(struct node*);
struct node* delete_end(struct node*);
struct node* delete_after(struct node*);
struct node* delete_node(struct node*);
struct node* delete_list(struct node*);
struct node* sort_list(struct node*);
struct node* search(struct node*);

void main() {
    int choice;
    clrscr();
    do {
        printf("\nMENU:\n");
        printf("1. Create List\n2. Display\n3. Insert at Beginning\n4. Insert at End\n5. Insert Before\n6. Insert After\n7. Delete from Beginning\n8. Delete from End\n9. Delete After\n10. Delete Node\n11. Delete List\n12. Sort List\n13. Search\n14. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: start = create_ll(start); break;
            case 2: display(start); break;
            case 3: start = insert_beg(start); break;
            case 4: start = insert_end(start); break;
            case 5: start = insert_before(start); break;
            case 6: start = insert_after(start); break;
            case 7: start = delete_beg(start); break;
            case 8: start = delete_end(start); break;
            case 9: start = delete_after(start); break;
            case 10: start = delete_node(start); break;
            case 11: start = delete_list(start); break;
            case 12: start = sort_list(start); break;
            case 13: start = search(start); break;
        }
    } while(choice != 14);
    getch();
}

struct node* create_ll(struct node *start) {
    struct node *nn, *ptr;
    int val;
    printf("Enter -1 to stop\n");
    printf("Enter values:\n");
    scanf("%d", &val);
    while (val != -1) {
        nn = (struct node *)malloc(sizeof(struct node));
        nn->data = val;
        nn->next = NULL;
        if (start == NULL) {
            start = nn;
        } else {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = nn;
        }
        scanf("%d", &val);
    }
    return start;
}

struct node* insert_beg(struct node *start) {
    int val;
    struct node *nn;
    printf("Enter a value: ");
    scanf("%d", &val);
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = start;
    return nn;
}

struct node* insert_end(struct node *start) {
    int val;
    struct node *nn, *ptr;
    printf("Enter a value: ");
    scanf("%d", &val);
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = nn;
    return start;
}

struct node* insert_after(struct node *start) {
    int val, num;
    struct node *nn, *ptr;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to insert: ");
    scanf("%d", &val);
    printf("Enter node after which to insert: ");
    scanf("%d", &num);
    nn->data = val;
    ptr = start;
    while(ptr != NULL && ptr->data != num)
        ptr = ptr->next;
    if (ptr != NULL) {
        nn->next = ptr->next;
        ptr->next = nn;
    }
    return start;
}

struct node* insert_before(struct node *start) {
    int val, num;
    struct node *nn, *ptr, *prev;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to insert: ");
    scanf("%d", &val);
    printf("Enter node before which to insert: ");
    scanf("%d", &num);
    nn->data = val;
    if (start->data == num) {
        nn->next = start;
        return nn;
    }
    ptr = start;
    while(ptr != NULL && ptr->data != num) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        prev->next = nn;
        nn->next = ptr;
    }
    return start;
}

struct node* display(struct node *start) {
    struct node *ptr = start;
    if (start == NULL)
        printf("List is empty\n");
    else {
        while(ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    return start;
}

struct node* delete_beg(struct node *start) {
    struct node *ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node* delete_end(struct node *start) {
    struct node *ptr = start, *prev;
    if (start->next == NULL) {
        free(start);
        return NULL;
    }
    while(ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
    return start;
}

struct node* delete_after(struct node *start) {
    int val;
    struct node *ptr = start;
    printf("Enter node value after which to delete: ");
    scanf("%d", &val);
    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;
    if(ptr != NULL && ptr->next != NULL) {
        struct node *temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    return start;
}

struct node* delete_node(struct node *start) {
    int val;
    struct node *ptr = start, *prev;
    printf("Enter node to delete: ");
    scanf("%d", &val);
    if (start->data == val) {
        ptr = start;
        start = start->next;
        free(ptr);
        return start;
    }
    while(ptr != NULL && ptr->data != val) {
        prev = ptr;
        ptr = ptr->next;
    }
    if(ptr != NULL) {
        prev->next = ptr->next;
        free(ptr);
    }
    return start;
}

struct node* delete_list(struct node *start) {
    struct node *ptr;
    while(start != NULL) {
        ptr = start;
        printf("Deleting %d\n", ptr->data);
        start = start->next;
        free(ptr);
    }
    return NULL;
}

struct node* search(struct node *start) {
    int val;
    struct node *ptr = start;
    printf("Enter value to search: ");
    scanf("%d", &val);
    while(ptr != NULL) {
        if(ptr->data == val) {
            printf("Found\n");
            return start;
        }
        ptr = ptr->next;
    }
    printf("Not Found\n");
    return start;
}

struct node* sort_list(struct node *start) {
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while(ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while(ptr2 != NULL) {
            if(ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
