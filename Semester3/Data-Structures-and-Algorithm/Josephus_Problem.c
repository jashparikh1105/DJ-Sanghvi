#include <stdio.h>
#include <stdlib.h>

// Node structure for each player
struct node {
    int player_id;
    struct node *next;
};

int main() {
    struct node *start = NULL, *ptr, *new_node;
    int n, k, i, count;

    printf("\nEnter the number of players: ");
    scanf("%d", &n);

    printf("Enter the value of k (every kth player gets eliminated): ");
    scanf("%d", &k);

    // Create circular linked list with players 1 to n
    start = (struct node *)malloc(sizeof(struct node));
    start->player_id = 1;
    start->next = start;
    ptr = start;

    for (i = 2; i <= n; i++) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->player_id = i;
        new_node->next = start;
        ptr->next = new_node;
        ptr = new_node;
    }

    // Elimination process
    ptr = start;
    for (count = n; count > 1; count--) {
        for (i = 0; i < k - 2; ++i)
            ptr = ptr->next;

        // Eliminate the kth player
        struct node *temp = ptr->next;
        printf("Player %d is eliminated.\n", temp->player_id);
        ptr->next = temp->next;

        // If the eliminated node was start, move start
        if (temp == start)
            start = temp->next;

        free(temp);
        ptr = ptr->next;
    }

    printf("\nThe Winner is Player %d\n", ptr->player_id);
    return 0;
}
