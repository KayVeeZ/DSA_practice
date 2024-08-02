#include<stdio.h>
#include<stdlib.h>
struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if((q->r+1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *q)
{
    if(q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if(isFull(q))
    {
        printf("Error: Queue Overflow!\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;

    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("Error: Queue Underflow!");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}


int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0; //note that actual size of queue is size-1 because of allocating 0 to initial indicator position
    q.arr = (int*)malloc(q.size*sizeof(int));

    // enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 23);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    enqueue(&q, 1);
    enqueue(&q, 121);
    enqueue(&q, 129);
    // printf("Dequeuing element %d\n", dequeue(&q));
    if(isEmpty(&q))
    {
        printf("Error: Queue Underflow!");
    }

    if(isFull(&q))
    {
        printf("Error: Queue Overflow!\n");
    }
    
    free(q.arr);

    return 0;
}