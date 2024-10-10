#include<stdio.h>
#include<stdlib.h>

// Structure for the queue to be used in BFS
struct queue {
    int size;  // Maximum size of the queue
    int f;     // Front index (for dequeue operations)
    int r;     // Rear index (for enqueue operations)
    int *arr;  // Array to store elements in the queue
};

// Function to check if the queue is full
int isFull(struct queue *q) {
    if(q->r == q->size - 1) {  // Queue is full if rear index equals size-1
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct queue *q) {
    if(q->r == q->f) {  // Queue is empty if front and rear indexes are equal
        return 1;
    }
    return 0;
}

// Function to add an element (enqueue) to the queue
void enqueue(struct queue *q, int val) {
    if(isFull(q)) {
        printf("Error: Queue Overflow!");  // Handle queue overflow
    }
    else {
        q->r = q->r + 1;  // Increment rear index
        q->arr[q->r] = val;  // Add the value to the queue
    }
}

// Function to remove an element (dequeue) from the queue
int dequeue(struct queue *q) {
    int a = -1;  // Initialize return value as -1 in case of underflow
    if(isEmpty(q)) {
        printf("Error: Queue Underflow!");  // Handle queue underflow
    }
    else {
        q->f++;  // Increment front index
        a = q->arr[q->f];  // Return the dequeued value
    }
    return a;
}

int main() {
    // Initialize queue for BFS
    struct queue q;
    q.size = 400;  // Set queue size to 400
    q.f = q.r = 0;  // Initialize front and rear indices to 0
    q.arr = (int*)malloc(q.size * sizeof(int));  // Allocate memory for queue array

    // BFS graph traversal
    int i = 0;  // Start traversal from the first node (node 0)

    // Visited array to keep track of visited nodes (0 = not visited, 1 = visited)
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    // Adjacency matrix representing the graph
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},  // Node 0 is connected to nodes 1, 2, and 3
        {1, 0, 0, 1, 0, 0, 0},  // Node 1 is connected to nodes 0 and 3
        {1, 0, 0, 1, 1, 0, 0},  // Node 2 is connected to nodes 0, 3, and 4
        {1, 1, 1, 0, 1, 0, 0},  // Node 3 is connected to nodes 0, 1, 2, and 4
        {0, 0, 1, 1, 0, 1, 1},  // Node 4 is connected to nodes 2, 3, 5, and 6
        {0, 0, 0, 0, 1, 0, 0},  // Node 5 is connected to node 4
        {0, 0, 0, 0, 1, 0, 0},  // Node 6 is connected to node 4
    };

    printf("%d ", i);  // Print the starting node (node 0)
    
    visited[i] = 1;  // Mark the starting node as visited
    enqueue(&q, i);  // Enqueue the starting node for BFS exploration
    
    // BFS loop: continue until the queue is empty
    while(!isEmpty(&q)) {
        int node = dequeue(&q);  // Dequeue the next node

        // Explore all neighboring nodes
        for (int j = 0; j < 7; j++) {
            // If there is an edge and the neighboring node has not been visited
            if(a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);  // Print the neighboring node
                visited[j] = 1;  // Mark the neighboring node as visited
                enqueue(&q, j);  // Enqueue the neighboring node for further exploration
            }
        }
    }

    free(q.arr);  // Free the memory allocated for the queue

    return 0;
}
