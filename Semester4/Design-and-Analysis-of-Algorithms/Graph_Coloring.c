#include <stdio.h>
#define V 4

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0},
};

void printSolution(int color[]) {
    printf("Color Assignments: ");
    for (int i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
}

int isSafe(int v, int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return 0;
    return 1;
}

int graphColoringUtil(int m, int color[], int v) {
    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c)) {
            color[v] = c;
            if (graphColoringUtil(m, color, v + 1))
                return 1;
            color[v] = 0;
        }
    }

    return 0;
}

int graphColoring(int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(m, color, 0)) {
        printf("Solution does not exist.\n");
        return 0;
    }

    printSolution(color);
    return 1;
}

int main() {
    int m = 3;
    printf("\nJash Parikh, C065, 60004220080\n");
    graphColoring(m);
    return 0;
}
