#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};


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

void push(struct stack *s)
{
    int element = 0;
    printf("Please enter element to be pushed: ");
    scanf("%d", &element);
    printf("--------------------------------------\n");
    s->arr[s->top+1] = element;
    s->top++;
    // return *s;
}

void pop(struct stack *s)
{
    int element1 = s->arr[s->top];
    s->top--;
    printf("Popped element is %d\n", element1);
    // return *s;
}

int parenthesisMatching(char *exp)
{
    struct stack *s;
    for (int i = 0; exp[i] !="\0"; i++)
    {
        if (exp[i] == "(")
        {
            push(s);
        }
        else if(exp[i] == ")")
        {
            if(isEmpty(s))
            {
                return 0;
            }
            else{
                pop(s);
            }
        }
    }
    if (isEmpty(s))
    {
        return 0;
    }
    return 1;
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    (*s).size = 5;
    s->top = -1;
    s->arr = (char *)malloc(s->size*sizeof(char));
    printf("Stack initialized successfully. \nPlease note this stack is based on an array. \nThis array has a max size of %d.\n", s->size);
    





    free(s->arr);
    free(s);


    return 0;
}