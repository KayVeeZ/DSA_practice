#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing elements of a linked list:\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Error: Queue Oveflow!");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;

    // check queue for empty
    if (f == NULL)
    {
        printf("Error: Queue Underflow!\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    printf("Dequeueing element %d\n", dequeue());
    linkedListTraversal(f);
    enqueue(34);
    enqueue(7);
    enqueue(4);
    linkedListTraversal(f);
    printf("Dequeueing element %d\n", dequeue());
    linkedListTraversal(f);

    return 0;
}