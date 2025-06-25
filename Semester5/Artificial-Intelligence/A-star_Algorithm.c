#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 6
#define INF 99999

// Function to find the node in open set with the lowest f(n)
int findLowestFCost(int openSet[], int f_cost[], int openSetSize) {
    int lowestIndex = openSet[0];
    for (int i = 1; i < openSetSize; i++) {
        if (f_cost[openSet[i]] < f_cost[lowestIndex]) {
            lowestIndex = openSet[i];
        }
    }
    return lowestIndex;
}

// Function to check if node is in closed set
bool isInClosedSet(int closedSet[], int closedSetSize, int node) {
    for (int i = 0; i < closedSetSize; i++) {
        if (closedSet[i] == node) {
            return true;
        }
    }
    return false;
}

// Remove a node from open set
void removeFromOpenSet(int openSet[], int *openSetSize, int node) {
    int i;
    for (i = 0; i < *openSetSize; i++) {
        if (openSet[i] == node) {
            break;
        }
    }
    for (; i < *openSetSize - 1; i++) {
        openSet[i] = openSet[i + 1];
    }
    (*openSetSize)--;
}

// Recursively print the path from source to currentNode
void reconstructPath(int parent[], int currentNode) {
    if (parent[currentNode] == -1) {
        printf("%d->", currentNode);
        return;
    }
    reconstructPath(parent, parent[currentNode]);
    printf("%d", currentNode);
    if (currentNode < MAX_NODES - 1) printf("->");
}

// Print current open set (priority queue view)
void printPriorityQueue(int openSet[], int f_cost[], int openSetSize) {
    printf("Priority Queue: ");
    for (int i = 0; i < openSetSize; i++) {
        printf("Node %d (f=%d) ", openSet[i], f_cost[openSet[i]]);
    }
    printf("\n");
}

// A* search algorithm implementation
void aStar(int graph[MAX_NODES][MAX_NODES], int heuristics[MAX_NODES], int startNode, int goalNode) {
    int g_cost[MAX_NODES];
    int f_cost[MAX_NODES];
    int parent[MAX_NODES];

    for (int i = 0; i < MAX_NODES; i++) {
        g_cost[i] = INF;
        f_cost[i] = INF;
        parent[i] = -1;
    }

    g_cost[startNode] = 0;
    f_cost[startNode] = heuristics[startNode];

    int openSet[MAX_NODES];
    int closedSet[MAX_NODES];
    int openSetSize = 1, closedSetSize = 0;
    openSet[0] = startNode;

    int step = 1;

    while (openSetSize > 0) {
        int currentNode = findLowestFCost(openSet, f_cost, openSetSize);
        printPriorityQueue(openSet, f_cost, openSetSize);
        printf("Step %d: Exploring Node %d (f=%d)\n", step++, currentNode, f_cost[currentNode]);

        if (currentNode == goalNode) {
            printf("Goal Node %d Found!\n", goalNode);
            printf("Total Path Cost: %d\n", g_cost[goalNode]);
            printf("Path: ");
            reconstructPath(parent, goalNode);
            printf("\n");
            return;
        }

        removeFromOpenSet(openSet, &openSetSize, currentNode);
        closedSet[closedSetSize++] = currentNode;

        for (int neighbor = 0; neighbor < MAX_NODES; neighbor++) {
            int edgeCost = graph[currentNode][neighbor];
            if (edgeCost == INF) continue;
            if (isInClosedSet(closedSet, closedSetSize, neighbor)) continue;

            int tentativeGCost = g_cost[currentNode] + edgeCost;
            bool inOpenSet = false;
            for (int i = 0; i < openSetSize; i++) {
                if (openSet[i] == neighbor) {
                    inOpenSet = true;
                    break;
                }
            }

            if (!inOpenSet || tentativeGCost < g_cost[neighbor]) {
                parent[neighbor] = currentNode;
                g_cost[neighbor] = tentativeGCost;
                f_cost[neighbor] = g_cost[neighbor] + heuristics[neighbor];
                if (!inOpenSet) {
                    openSet[openSetSize++] = neighbor;
                }
            }
        }
    }

    printf("Goal Node %d Not Found.\n", goalNode);
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {INF, 1,   4,   INF, INF, INF},
        {1,   INF, 4,   2,   7,   INF},
        {4,   4,   INF, 3,   5,   INF},
        {INF, 2,   3,   INF, 4,   6},
        {INF, 7,   5,   4,   INF, 7},
        {INF, INF, INF, 6,   7,   INF}
    };

    int heuristics[MAX_NODES] = {7, 6, 2, 1, 0, 3};

    int startNode = 0;
    int goalNode = 4;

    aStar(graph, heuristics, startNode, goalNode);

    return 0;
}
