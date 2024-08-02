#include<stdio.h>
#include<stdlib.h>
struct DEqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct DEqueue *q)
{
    if(q->r==q->size-1 && q->f==-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct DEqueue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}

void enqueueR(struct DEqueue *q, int val)
{
    if(isFull(q))
    {
        printf("Error: Queue Overflow!");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;

    }
}

void enqueueF(struct DEqueue *q, int val)
{
    if(isFull(q))
    {
        printf("Error: Queue Overflow!");
    }
    else
    {
        q->arr[q->f]=val;
        q->f--;
    }
}

int dequeueF(struct DEqueue *q)
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

int dequeueR(struct DEqueue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("Error: Queue Underflow!\n");
    }
    else
    {
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}


int main()
{
    struct DEqueue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueueR(&q, 12);
    enqueueF(&q, 15);
    printf("Dequeuing element %d\n", dequeueR(&q));
    printf("Dequeuing element %d\n", dequeueF(&q));
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