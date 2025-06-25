#include <stdio.h>
#include <limits.h>
#define SIZE 6

// Function to find the vertex with the minimum distance which is not yet visited
int min(int d[], int visited[]) {
    int min = INT_MAX;
    int minIndex;
    for (int i = 0; i < SIZE; i++) {
        if (visited[i] == 0 && d[i] < min) {
            minIndex = i;
            min = d[i];
        }
    }
    return minIndex;
}

// Function to print the path recursively
void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        printf("%d", vertex + 1);
        return;
    }
    printPath(parent, parent[vertex]);
    printf(" -> %d", vertex + 1);
}

// Dijkstra's Algorithm implementation
void dijkstra(int w[SIZE][SIZE], int source) {
    int visited[SIZE];
    int parent[SIZE];
    int d[SIZE];

    for (int i = 0; i < SIZE; i++) {
        visited[i] = 0;
        d[i] = INT_MAX;
    }
    d[source] = 0;
    parent[source] = -1;

    for (int i = 0; i < SIZE; i++) {
        int minIndex = min(d, visited);
        visited[minIndex] = 1;

        for (int j = 0; j < SIZE; j++) {
            if (w[minIndex][j] != 0 && visited[j] == 0 && d[j] > d[minIndex] + w[minIndex][j]) {
                d[j] = d[minIndex] + w[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }

    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < SIZE; i++) {
        if (i != source) { // Skip the source vertex
            printf("%d\t%d\t\t", i + 1, d[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

void main() {
    int w[SIZE][SIZE];
    int source;

    printf("Enter the adjacency matrix for the graph (%d x %d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &w[i][j]);
        }
    }

    printf("Enter the source vertex (1 to %d): ", SIZE);
    scanf("%d", &source);
    source--; // Adjusting for 0-based indexing

    printf("\nShortest paths from source vertex %d:\n", source + 1);
    dijkstra(w, source);
}