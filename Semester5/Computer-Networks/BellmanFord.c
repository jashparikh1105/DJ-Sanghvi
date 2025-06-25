#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define OG 999


int w[MAX][MAX];  
int d[MAX];       
int parent[MAX];

void initialize(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        d[i] = OG;     
        parent[i] = -1; 
    }
    d[0] = 0; 
}

void relax(int u, int v) 
{
    if (d[v] > d[u] + w[u][v]) 
    {
        d[v] = d[u] + w[u][v];
        parent[v] = u;
    }
}

void bellmanFord(int n) 
{
    for (int j = 0; j < n - 1; j++) 
    { 
        for (int u = 0; u < n; u++)
         { 
            for (int v = 0; v < n; v++) 
            { 
                if (w[u][v] != 0)
                { 
                    relax(u, v);    
                }
            }
        }
    }
}

int main() 
{
    int n;
    printf("Number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
    initialize(n);
    bellmanFord(n);

    printf("Shortest distances from source node:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: Distance = %d, Parent = %d\n", i + 1, d[i], parent[i] + 1);
    }

    return 0;
}
//Output
/*Number of vertices: 7
Enter the adjacency matrix:
0 6 5 5 0 0 0
0 0 0 0 -1 0 0
0 -2 0 0 1 0 0
0 0 -2 0 0 -1 0
0 0 0 0 0 0 3
0 0 0 0 0 0 3
0 0 0 0 0 0 0
Shortest distances from source node:
Node 1: Distance = 0, Parent = 0
Node 2: Distance = 1, Parent = 3
Node 3: Distance = 3, Parent = 4
Node 4: Distance = 5, Parent = 1
Node 5: Distance = 0, Parent = 2
Node 6: Distance = 4, Parent = 4
Node 7: Distance = 3, Parent = 5*/