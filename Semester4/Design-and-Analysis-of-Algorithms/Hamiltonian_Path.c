#include <stdio.h>
#define V 5

int path[V];

int isSafe(int v, int graph[V][V], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}

int hamCycleUtil(int graph[V][V], int pos) {
    if (pos == V)
        return graph[path[pos - 1]][path[0]] == 1;

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, pos + 1))
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

void printSolution() {
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    printf("\nJash Parikh, C065, 60004220080\n");

    if (!hamCycleUtil(graph, 1))
        printf("No Hamiltonian Cycle exists\n");
    else
        printSolution();

    return 0;
}
