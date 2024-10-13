#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printMST(int V, int parent[], int graph[V][V])
{
    for (int v = 1; v < V; v++)
    {
        printf("%d-%d \t%d\n", v, parent[v], graph[v][parent[v]]);
    }
}

int minKey(int mstSet[], int key[], int V)
{
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < V; i++)
    {
        if(mstSet[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void primMST(int V, int graph[V][V])
{
    int mstSet[V]; int key[V]; int parent[V];

    for (int i = 0; i < V; i++)
    {
        mstSet[i] = 0;
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V - 1; count++)
    {
        int u = minKey(mstSet, key, V);

        mstSet[u] = 1;

        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(V, parent, graph);

}



int main()
{
    // Cost adjacency matrix representing the graph
    int ca[7][7] = 
    {
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
    primMST(V, ca);
    return 0;
}