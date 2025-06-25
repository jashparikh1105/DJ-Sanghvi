#include <stdio.h>
#define INF 9999 // Large number representing infinity
#define NUM_NODES 12 // Number of nodes (A to L)

// Function to print the routing table
void printRoutingTable(int routingTable[], char *pathTable[], int numNodes) 
{
    printf("Routing Table for J:\n");
    for (int i = 0; i < numNodes; i++) 
    {
        printf("To %c: Cost = %d via %s\n", 'A' + i, routingTable[i], pathTable[i]);
    }
}

int main() 
{
    // Delay vectors from neighbors (A, I, H, K) to all nodes (A to L)
    int delayFromNeighbors[4][NUM_NODES] = {
        {0, 12, 25, 40, 14, 23, 18, 17, 21, 9, 24, 29}, // From A
        {24, 36, 18, 27, 7, 20, 31, 20, 0, 11, 22, 33}, // From I
        {20, 31, 19, 8, 30, 19, 6, 0, 14, 7, 22, 9},    // From H
        {21, 28, 36, 24, 22, 40, 31, 19, 22, 10, 0, 9}  // From K
    };

    // Delays from J to its neighbors
    int delaysToNeighbors[4] = {8, 10, 12, 6}; // To A, I, H, K
    char *neighborNames[4] = {"A", "I", "H", "K"}; // Names of neighbors

    // Routing table and path table
    int routingTable[NUM_NODES];   // Shortest delay to each node
    char *pathTable[NUM_NODES];   // Neighbor providing the shortest path

    // Calculate the shortest paths from J
    for (int node = 0; node < NUM_NODES; node++) 
    {
        if (node == 9)
        { // Node J itself (index 9)
            routingTable[node] = 0;      // Cost to itself is 0
            pathTable[node] = "J";      // Path is directly J
        }
        else 
        {
            int minCost = INF;          // Initialize with infinity
            char *bestNeighbor = NULL;  // Neighbor with the shortest path

            // Check the cost through each neighbor
            for (int n = 0; n < 4; n++) 
            {
                int cost = delaysToNeighbors[n] + delayFromNeighbors[n][node];
                if (cost < minCost) 
                {
                    minCost = cost;
                    bestNeighbor = neighborNames[n];
                }
            }

            // Update the routing table
            routingTable[node] = minCost;
            pathTable[node] = bestNeighbor;
        }
    }

    // Print the final routing table
    printRoutingTable(routingTable, pathTable, NUM_NODES);

    return 0;
}