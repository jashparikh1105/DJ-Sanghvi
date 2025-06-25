 #include <stdio.h>
 #include <stdlib.h>
 // A structure to represent an adjacency list node
 struct AdjListNode {
 int dest;
 int cost;
 struct AdjListNode* next;
 };
 // A structure to represent an adjacency list
 struct AdjList {
 struct AdjListNode* head;
 };
 // A structure to represent a graph
 struct Graph {
 int V;
 struct AdjList* array;
 };
 // A function to create a new adjacency list node
 struct AdjListNode* newAdjListNode(int dest, int cost) {
 struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
 newNode->dest = dest;
 newNode->cost = cost;
 newNode->next = NULL;
 return newNode;
 }
// A function to create a graph with V vertices
 struct Graph* createGraph(int V) {
 struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
 graph->V = V;
 // Create an array of adjacency lists. Size of array will be V
 graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 // Initialize each adjacency list as empty by making head as NULL
 for (int i = 0; i < V; ++i)
 graph->array[i].head = NULL;
 return graph;
 }
 // A function to add an edge to a directed graph
 void addEdge(struct Graph* graph, int src, int dest, int cost) {
 // Add an edge from src to dest with a cost.
 struct AdjListNode* newNode = newAdjListNode(dest, cost);
 newNode->next = graph->array[src].head;
 graph->array[src].head = newNode;
 }
 // A function to perform Depth-Limited Search (DLS)
 int DLS(struct Graph* graph, int v, int target, int limit, int* path, int* pathIndex, int* totalCost, int*
 visited) {
 visited[v] = 1;
 path[(*pathIndex)++] = v;
 if (v == target)
 return 1;
 if (limit <= 0) {
 (*pathIndex)--;
 return 0;
 }
 struct AdjListNode* node = graph->array[v].head;
 while (node != NULL) {
 *totalCost += node->cost;
 if (!visited[node->dest]) {
 if (DLS(graph, node->dest, target, limit- 1, path, pathIndex, totalCost, visited))
return 1;
 }
 *totalCost-= node->cost;
 node = node->next;
 }
 (*pathIndex)--;
 return 0;
 }
 // A function to perform Iterative Deepening Depth-First Search (IDDFS)
 int IDDFS(struct Graph* graph, int src, int target, int* totalCost) {
 int depth = 0;
 int path[graph->V];
 int pathIndex;
 while (1) {
 pathIndex = 0;
 *totalCost = 0; // Reset the total cost for each depth iteration
 int visited[graph->V];
 int reachableWithinLimit[graph->V]; // Track reachable nodes that are unvisited within
 depth
 for (int i = 0; i < graph->V; i++) {
 visited[i] = 0; // Reset visited nodes
 reachableWithinLimit[i] = 0;
 }
 printf("Exploring depth: %d\n", depth);
 if (DLS(graph, src, target, depth, path, &pathIndex, totalCost, visited)) {
 printf("Target is reachable from source within depth %d\n", depth);
 printf("Path: ");
 for (int j = 0; j < pathIndex; j++)
 printf("%d ", path[j]);
 printf("\nTotal cost: %d\n", *totalCost);
 return 1;
 } else {
 // Print visited nodes
 printf("Visited nodes in depth %d: ", depth);
 for (int i = 0; i < graph->V; i++) {
 if (visited[i]) {
 printf("%d ", i);
 }
 }
printf("\n");
 // Track reachable but unvisited nodes at the current depth
 for (int i = 0; i < graph->V; i++) {
 if (visited[i]) {
 struct AdjListNode* node = graph->array[i].head;
 while (node != NULL) {
 if (!visited[node->dest]) {
 reachableWithinLimit[node->dest] = 1; // Mark it as reachable
 }
 node = node->next;
 }
 }
 }
 // Print reachable but unvisited nodes
 printf("Reachable but unvisited nodes within depth %d: ", depth);
 for (int i = 0; i < graph->V; i++) {
 if (reachableWithinLimit[i] && !visited[i]) {
 printf("%d ", i);
 }
 }
 printf("\n");
 }
 depth++;
 }
 return 0;
 }
 // Driver code
 int main() {
 int V = 14;
 struct Graph* graph = createGraph(V);
 // Add edges to the graph (source, destination, cost)
 addEdge(graph, 0, 1, 4);
 addEdge(graph, 0, 2, 3);
 addEdge(graph, 1, 3, 4);
 addEdge(graph, 1, 4, 7);
 addEdge(graph, 2, 5, 8);
 addEdge(graph, 3, 7, 1);
 addEdge(graph, 2, 6, 2);
 addEdge(graph, 4, 9, 2);
addEdge(graph, 4, 10, 3);
 addEdge(graph, 5, 11, 5);
 addEdge(graph, 11, 8, 5);
 addEdge(graph, 6, 12, 10);
 addEdge(graph, 9, 13, 1);
 int src, target, totalCost = 0;
 // Take user input
 printf("Enter the source node (0 to 13): ");
 scanf("%d", &src);
 printf("Enter the target node (0 to 13): ");
 scanf("%d", &target);
 // Perform IDDFS and print the result
 if (!IDDFS(graph, src, target, &totalCost))
 printf("Target is NOT reachable from source\n");
 return 0;
 }