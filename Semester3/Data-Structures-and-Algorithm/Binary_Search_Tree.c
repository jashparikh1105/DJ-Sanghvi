#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree = NULL;

// Function Prototypes
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);

int main() {
    int option, val;
    struct node *ptr;
    do {
        printf("\n****** MAIN MENU ******\n");
        printf("1. Insert Element\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n");
        printf("5. Find Smallest Element\n6. Find Largest Element\n7. Delete Element\n");
        printf("8. Total Nodes\n9. Total External Nodes\n10. Total Internal Nodes\n");
        printf("11. Tree Height\n12. Mirror Image\n13. Delete Tree\n14. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(tree);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(tree);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(tree);
                printf("\n");
                break;
            case 5:
                ptr = findSmallestElement(tree);
                if(ptr != NULL)
                    printf("Smallest element: %d\n", ptr->data);
                break;
            case 6:
                ptr = findLargestElement(tree);
                if(ptr != NULL)
                    printf("Largest element: %d\n", ptr->data);
                break;
            case 7:
                printf("Enter the element to delete: ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 8:
                printf("Total nodes: %d\n", totalNodes(tree));
                break;
            case 9:
                printf("Total external nodes: %d\n", totalExternalNodes(tree));
                break;
            case 10:
                printf("Total internal nodes: %d\n", totalInternalNodes(tree));
                break;
            case 11:
                printf("Height of tree: %d\n", Height(tree));
                break;
            case 12:
                tree = mirrorImage(tree);
                printf("Mirror image created.\n");
                break;
            case 13:
                tree = deleteTree(tree);
                printf("Tree deleted.\n");
                break;
        }
    } while(option != 14);

    return 0;
}

// ---------------- Insert ----------------
struct node *insertElement(struct node *tree, int val) {
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    if(tree == NULL) {
        return ptr;
    } else {
        parentptr = NULL;
        nodeptr = tree;
        while(nodeptr != NULL) {
            parentptr = nodeptr;
            if(val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if(val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}

// ---------------- Traversals ----------------
void preorderTraversal(struct node *tree) {
    if(tree != NULL) {
        printf("%d ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree) {
    if(tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree) {
    if(tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d ", tree->data);
    }
}

// ---------------- Find Smallest & Largest ----------------
struct node *findSmallestElement(struct node *tree) {
    if(tree == NULL || tree->left == NULL)
        return tree;
    return findSmallestElement(tree->left);
}

struct node *findLargestElement(struct node *tree) {
    if(tree == NULL || tree->right == NULL)
        return tree;
    return findLargestElement(tree->right);
}

// ---------------- Delete Node ----------------
struct node *deleteElement(struct node *tree, int val) {
    if(tree == NULL) {
        printf("Tree is empty.\n");
        return NULL;
    }

    if(val < tree->data)
        tree->left = deleteElement(tree->left, val);
    else if(val > tree->data)
        tree->right = deleteElement(tree->right, val);
    else {
        // Node with only one child or no child
        if(tree->left == NULL) {
            struct node *temp = tree->right;
            free(tree);
            return temp;
        }
        else if(tree->right == NULL) {
            struct node *temp = tree->left;
            free(tree);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = findSmallestElement(tree->right);
        tree->data = temp->data;
        tree->right = deleteElement(tree->right, temp->data);
    }
    return tree;
}

// ---------------- Count Nodes ----------------
int totalNodes(struct node *tree) {
    if(tree == NULL)
        return 0;
    return (1 + totalNodes(tree->left) + totalNodes(tree->right));
}

int totalExternalNodes(struct node *tree) {
    if(tree == NULL)
        return 0;
    if(tree->left == NULL && tree->right == NULL)
        return 1;
    return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);
}

int totalInternalNodes(struct node *tree) {
    if(tree == NULL || (tree->left == NULL && tree->right == NULL))
        return 0;
    return 1 + totalInternalNodes(tree->left) + totalInternalNodes(tree->right);
}

// ---------------- Height ----------------
int Height(struct node *tree) {
    if(tree == NULL)
        return 0;
    int leftHeight = Height(tree->left);
    int rightHeight = Height(tree->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// ---------------- Mirror ----------------
struct node *mirrorImage(struct node *tree) {
    if(tree != NULL) {
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        struct node *temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
    return tree;
}

// ---------------- Delete Tree ----------------
struct node *deleteTree(struct node *tree) {
    if(tree != NULL) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    return NULL;
}
