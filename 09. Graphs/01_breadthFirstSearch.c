#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("Error: Queue Overflow!");
    }
    else
    {
        q->r=q->r+1;
        q->arr[q->r]=val;

    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("Error: Queue Underflow!");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}


int main()
{
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // BFS implementation
    int i = 0; // start from first node

    int visited[7] ={0,0,0,0,0,0,0}; // array to keep track of visitation in bfs
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    }; //a is adjacency matrix for the graph in the notebook

    printf("%d ",i); // print first node

    visited[i] = 1; // set first element to visited because we are already at first node of graph
    enqueue(&q, i); // enqueue i for exploration
    
    while(!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            // if edge exists and node has not been visited print node
            if(a[node][j] == 1 && visited[j]==0)
            {
                printf("%d ",j); 
                visited[j] = 1;
                enqueue(&q, j);             
            }
        }
    }
    free(q.arr);

    return 0;
}