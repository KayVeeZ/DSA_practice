#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// check empty for stack
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// check full for stack
int isFull(struct stack *ptr)
{
    if(ptr->top >= ptr->size-1)
    {
        return 1;
    }
    return 0;
}

struct stack *createStack(int size)
{
    struct stack *s;
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    return s;
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size*sizeof(int));

    // struct stack *s;
    // (*s).size = 80;
    // s->top = -1;
    // s->arr = (int *)malloc(s->size*sizeof(int));

    // Pushing an element manually
    // s->arr[0] = 21;
    // s->top++;
    int size = 0;
    scanf("Enter the size of stack you want in a positive integer number: ", &size);
    printf("\n");

    struct stack *s = createStack(size);


    // Check if stack is empty
    if(isEmpty(s))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty.");
    }
    
    return 0;
}