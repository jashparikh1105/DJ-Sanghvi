#include <stdio.h>
#include <limits.h>
#define SIZE 6

int min(int d[], int visited[]) 
{
    int min = INT_MAX;
    int minIndex;
    for (int i = 0; i < SIZE; i++) 
    {
        if (visited[i] == 0 && d[i] < min) 
        {
            minIndex = i;
            min = d[i];
        }
    }
    return minIndex;
}
void printPath(int parent[], int vertex) 
{
    if (parent[vertex] == -1) 
    {
        printf("%d", vertex + 1);
        return;
    }
    printPath(parent, parent[vertex]);
    printf(" -> %d", vertex + 1);
}
void dijkstra(int w[SIZE][SIZE]) 
{
    int visited[SIZE];
    int parent[SIZE];
    int d[SIZE];

    for (int i = 0; i < SIZE; i++) 
    {
        visited[i] = 0;
        d[i] = INT_MAX;
    }
    d[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < SIZE; i++) 
    {
        int minIndex = min(d, visited);
        visited[minIndex] = 1;

        for (int j = 0; j < SIZE; j++) 
        {
            if (w[minIndex][j] != 0 && visited[j] == 0 && d[j] > d[minIndex] + w[minIndex][j]) 
            {
                d[j] = d[minIndex] + w[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }
    printf("Vertex\tDistance\tPath\n");
    for (int i = 1; i < SIZE; i++) 
    {
        printf("%d\t%d\t\t", i + 1, d[i]);
        printPath(parent, i);
        printf("\n");
    }
}
void main() 
{
    int w[SIZE][SIZE] = {{0, 7, 9, 0, 0, 14},
                         {7, 0, 10, 15, 0, 0},
                         {9, 10, 0, 11, 0, 2},
                         {0, 15, 11, 0, 6, 0},
                         {0, 0, 0, 6, 0, 9},
                         {14, 0, 2, 0, 9, 0}};
    dijkstra(w);
}