#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;
int visited[MAX];

// Push operation
void push(int vertex) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = vertex;
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// DFS traversal
void DFS(int graph[MAX][MAX], int startVertex, int goal, int n) {
    int i, found = 0;
    push(startVertex);

    printf("DFS traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty()) {
        int currentVertex = pop();

        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;

            if (currentVertex == goal) {
                found = 1;
                break;
            }

            // Push adjacent unvisited vertices (reverse order for correct DFS)
            for (i = n - 1; i >= 0; i--) {
                if (graph[currentVertex][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }

    if (found)
        printf("\nGoal node %d reached!\n", goal);
    else
        printf("\nGoal node %d not reachable.\n", goal);

    // Print unvisited nodes
    printf("Unvisited nodes: ");
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX];
    int n = 10, i, j, startVertex = 0, goal;

    // Example graph input (Adjacency Matrix)
    int graphInput[10][10] = {
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
    };

    // Copy the graph to a separate matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = graphInput[i][j];

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Get goal node input from user
    printf("Enter the goal node: ");
    scanf("%d", &goal);

    // Perform DFS
    DFS(graph, startVertex, goal, n);

    return 0;
}
