#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Enqueue operation
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Dequeue operation
int dequeue() {
    int del;
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        del = queue[front];
        front++;
        return del;
    }
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// BFS traversal with goal node detection
void BFS(int graph[MAX][MAX], int startVertex, int goal, int n) {
    int i, found = 0;
    enqueue(startVertex);
    printf("BFS traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty()) {
        int currentVertex = dequeue();
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;

            if (currentVertex == goal) {
                found = 1;
                break;
            }

            for (i = 0; i < n; i++) {
                if (graph[currentVertex][i] == 1 && !visited[i]) {
                    enqueue(i);
                }
            }
        }
    }

    if (found)
        printf("\nGoal node %d reached!\n", goal);
    else
        printf("\nGoal node %d not reachable.\n", goal);

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
    int n, i, j, startVertex, goal;

    // Example graph (adjacency matrix of 10 nodes)
    n = 10;
    int graphInput[10][10] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}
    };

    // Copy to graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = graphInput[i][j];
        }
    }

    // Set the start vertex
    startVertex = 0;

    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Get goal node input
    printf("Enter the goal node: ");
    scanf("%d", &goal);

    // Perform BFS
    BFS(graph, startVertex, goal, n);

    return 0;
}
