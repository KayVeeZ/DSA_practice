#include<stdio.h>
#include<stdlib.h>

// Global array to keep track of visited nodes in DFS
int visited[7] = {0, 0, 0, 0, 0, 0, 0}; 

// Adjacency matrix representation of the graph
// a[i][j] = 1 means there is an edge between node i and node j
// a[i][j] = 0 means there is no edge between node i and node j
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},  // Node 0 is connected to nodes 1, 2, and 3
    {1, 0, 0, 1, 0, 0, 0},  // Node 1 is connected to nodes 0 and 3
    {1, 0, 0, 1, 1, 0, 0},  // Node 2 is connected to nodes 0, 3, and 4
    {1, 1, 1, 0, 1, 0, 0},  // Node 3 is connected to nodes 0, 1, 2, and 4
    {0, 0, 1, 1, 0, 1, 1},  // Node 4 is connected to nodes 2, 3, 5, and 6
    {0, 0, 0, 0, 1, 0, 0},  // Node 5 is connected to node 4
    {0, 0, 0, 0, 1, 0, 0},  // Node 6 is connected to node 4
};

// Depth-First Search function
// This function recursively visits nodes and marks them as visited
void DFS(int i) {
    visited[i] = 1;  // Mark the current node as visited
    printf("%d ", i);  // Print the node (this shows the order of traversal)

    // Loop through all possible nodes
    for (int j = 0; j < 7; j++) {
        // If there is an edge between node i and node j, and node j has not been visited
        if (a[i][j] == 1 && !visited[j]) {
            DFS(j);  // Recursively visit node j
        }
    }
}

int main() {
    // Start DFS traversal from node 5
    DFS(5);

    return 0;
}
