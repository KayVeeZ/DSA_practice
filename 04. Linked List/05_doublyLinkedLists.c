#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// forward traversal for doubly linked lists
void forwardTraversal(struct Node *head)
{
struct Node *ptr = head;
while(ptr != NULL)
{
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
}
}

// backward traversal for doubly linked lists
void backwardTraversal(struct Node *tail)
{
struct Node *ptr = tail;
while(ptr != NULL)
{
    printf("Element: %d\n", ptr->data);
    ptr = ptr->prev;
}
}

int main()
{

    // initialise nodes for doubly linked list
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *tail;

    // get memory from heap for each node
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    sixth = (struct Node*)malloc(sizeof(struct Node));
    tail = (struct Node*)malloc(sizeof(struct Node));

    // create the data for the linked lists

    // link the head forward to the first named node and prev to NULL
    head->data = 1;
    head->prev = NULL;
    head->next = first;

    // link the first forward to the second named node and prev to head
    first->data = 2;
    first->prev = head;
    first->next = second;

    // link the second forward to the third named node and prev to first
    second->data = 3;
    second->prev = first;
    second->next = third;

    // link the third forward to the fourth named node and prev to second
    third->data = 4;
    third->prev = second;
    third->next = fourth;

    // link the fourth forward to the fifth named node and prev to third
    fourth->data = 5;
    fourth->prev = third;
    fourth->next = fifth;

    // link the fifth forward to the sixth named node and prev to fourth
    fifth->data = 6;
    fifth->prev = fourth;
    fifth->next = sixth;

    // link the sixth forward to tail and prev to fifth
    sixth->data = 7;
    sixth->prev = fifth;
    sixth->next = tail;

    // link the sixth forward to NULL and prev to sixth
    tail->data = 8;
    tail->prev = sixth;
    tail->next = NULL;

    // forward traversal
    printf("Forward Traversal\n");
    forwardTraversal(head);


// backward traversal
    printf("Backward Traversal\n");
    backwardTraversal(tail);

    return 0;
}