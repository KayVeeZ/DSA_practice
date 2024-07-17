#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node * next;
};

struct Node * top = NULL;

void linkedListTraversal(struct Node* ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
     if(top == NULL)
     {
        return 1;
     }
     else
     {
        return 0;
     }
     
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if (p==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node* push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Error: Stack Overflow!");
    }
    else
    {
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *tp)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        struct Node *n =  tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
} 

int peek(int pos)
{
    struct Node *ptr = top;
    for(int i = 0; i < pos-1 && ptr!=NULL; i++)
    { 
        ptr = ptr->next;
    }
    if (ptr != NULL )
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop()
{
    return top->data;
}

int stackBottom()
{
    struct Node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);
    top = push(top, 721);
    top = push(top, 17);
    top = push(top, 97);
    top = push(top, 2087);

    linkedListTraversal(top);
    printf("Value at position 3 is %d\n", peek(3));
    printf("Value of stack top is %d\n", stackTop());
    printf("Value of stack bottom is %d\n", stackBottom());

    return 0;
}