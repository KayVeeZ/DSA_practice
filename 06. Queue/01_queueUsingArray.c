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
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // if(isEmpty(&q))
    // {
    //     printf("Error: Queue Empty!");
    // }

    // enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    if(isEmpty(&q))
    {
        printf("Error: Queue Underflow!");
    }

    if(isFull(&q))
    {
        printf("Error: Queue Overflow!");
    }
    free(q.arr);

    return 0;
}