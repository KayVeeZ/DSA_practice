#include<stdio.h>
#include<stdlib.h>
#include<limits.h>  // For INT_MAX

// Function to find the vertex with the minimum key value that is not yet included in MST
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int V, int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's algorithm for an adjacency matrix representation of the graph
void primMST(int graph[7][7], int V) {
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key values used to pick minimum weight edge
    int mstSet[V];  // To represent the set of vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from the first vertex (index 0), key of this vertex is 0
    key[0] = 0;
    parent[0] = -1;  // First node is always the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero for adjacent vertices, mstSet[v] is false for vertices not yet included in MST
            // and key[v] is greater than graph[u][v]
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, V, graph);
}

int main() 
{
    // Cost adjacency matrix representing the graph
    int ca[7][7] = {
        {0, 0, 8, 0, 13, 17, 0},  // Node 0 is connected to nodes 2, 4, and 5
        {0, 0, 20, 0, 0, 0, 6},   // Node 1 is connected to nodes 2 and 6
        {8, 20, 0, 11, 0, 0, 0},  // Node 2 is connected to nodes 0, 1, and 3
        {0, 0, 11, 0, 12, 0, 0},  // Node 3 is connected to nodes 2, and 4
        {13, 0, 0, 12, 0, 15, 0}, // Node 4 is connected to nodes 0, 3, and 5
        {17, 0, 0, 0, 15, 0, 18}, // Node 5 is connected to nodes 0, 4, and 6
        {0, 6, 0, 0, 0, 18, 0},   // Node 6 is connected to nodes 1 and 5
    };

    int V = 7;  // Number of vertices in the graph

    // Apply Prim's algorithm on the given graph
    primMST(ca, V);

    return 0;
}
