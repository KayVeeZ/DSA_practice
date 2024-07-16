#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};


int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size*sizeof(int));

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    (*s).size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    printf("Stack initialized successfully. \nPlease note this stack is based on an array. \nThis array has a max size of %d.\n", s->size);
    
    // Pushing an element manually
    s->arr[0] = 21;
    s->top++;
    free(s->arr);
    free(s);


    return 0;
}