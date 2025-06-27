#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;            // Power of x
    int coeff;          // Coefficient
    struct node *next;
};

// Global start pointers for polynomials
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;

// Function declarations
struct node *create_poly(struct node *);
struct node *display_poly(struct node *);
struct node *add_poly(struct node *, struct node *, struct node *);
struct node *sub_poly(struct node *, struct node *, struct node *);
struct node *add_node(struct node *, int, int);

// ------------------------ MAIN ------------------------
int main() {
    int option;
    do {
        printf("\n******* MAIN MENU *******\n");
        printf("1. Enter the first polynomial\n");
        printf("2. Display the first polynomial\n");
        printf("3. Enter the second polynomial\n");
        printf("4. Display the second polynomial\n");
        printf("5. Add the polynomials\n");
        printf("6. Display the result\n");
        printf("7. Subtract the polynomials\n");
        printf("8. Display the result\n");
        printf("9. EXIT\n");
        printf("Enter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1: start1 = create_poly(start1); break;
            case 2: start1 = display_poly(start1); break;
            case 3: start2 = create_poly(start2); break;
            case 4: start2 = display_poly(start2); break;
            case 5: start3 = add_poly(start1, start2, start3); break;
            case 6: start3 = display_poly(start3); break;
            case 7: start4 = sub_poly(start1, start2, start4); break;
            case 8: start4 = display_poly(start4); break;
        }
    } while(option != 9);
    
    return 0;
}

// ------------------------ CREATE ------------------------
struct node *create_poly(struct node *start) {
    struct node *nn, *ptr;
    int n, c;
    printf("Enter exponent (-1 to stop): ");
    scanf("%d", &n);
    while(n != -1) {
        printf("Enter coefficient: ");
        scanf("%d", &c);
        nn = (struct node *)malloc(sizeof(struct node));
        nn->num = n;
        nn->coeff = c;
        nn->next = NULL;

        if(start == NULL) {
            start = nn;
        } else {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = nn;
        }

        printf("Enter exponent (-1 to stop): ");
        scanf("%d", &n);
    }
    return start;
}

// ------------------------ DISPLAY ------------------------
struct node *display_poly(struct node *start) {
    struct node *ptr = start;
    if(start == NULL) {
        printf("Polynomial is empty.\n");
        return start;
    }

    while(ptr != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->num);
        ptr = ptr->next;
        if(ptr != NULL)
            printf(" + ");
    }
    printf("\n");
    return start;
}

// ------------------------ ADDITION ------------------------
struct node *add_poly(struct node *p1, struct node *p2, struct node *res) {
    while(p1 != NULL && p2 != NULL) {
        if(p1->num == p2->num) {
            res = add_node(res, p1->num, p1->coeff + p2->coeff);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->num > p2->num) {
            res = add_node(res, p1->num, p1->coeff);
            p1 = p1->next;
        }
        else {
            res = add_node(res, p2->num, p2->coeff);
            p2 = p2->next;
        }
    }

    while(p1 != NULL) {
        res = add_node(res, p1->num, p1->coeff);
        p1 = p1->next;
    }

    while(p2 != NULL) {
        res = add_node(res, p2->num, p2->coeff);
        p2 = p2->next;
    }

    return res;
}

// ------------------------ SUBTRACTION ------------------------
struct node *sub_poly(struct node *p1, struct node *p2, struct node *res) {
    while(p1 != NULL && p2 != NULL) {
        if(p1->num == p2->num) {
            res = add_node(res, p1->num, p1->coeff - p2->coeff);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->num > p2->num) {
            res = add_node(res, p1->num, p1->coeff);
            p1 = p1->next;
        }
        else {
            res = add_node(res, p2->num, -p2->coeff);
            p2 = p2->next;
        }
    }

    while(p1 != NULL) {
        res = add_node(res, p1->num, p1->coeff);
        p1 = p1->next;
    }

    while(p2 != NULL) {
        res = add_node(res, p2->num, -p2->coeff);
        p2 = p2->next;
    }

    return res;
}

// ------------------------ ADD NODE ------------------------
struct node *add_node(struct node *start, int exp, int coeff) {
    if(coeff == 0) return start;
    
    struct node *nn, *ptr;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->num = exp;
    nn->coeff = coeff;
    nn->next = NULL;

    if(start == NULL) {
        start = nn;
    } else {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = nn;
    }
    return start;
}
