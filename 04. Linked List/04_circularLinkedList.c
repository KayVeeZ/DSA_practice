#include<stdio.h>
#include<stdlib.h>
struct Node
{
     int data;
     struct Node *next;
};

void circularTraversal(struct Node *head)
{
    struct Node *ptr = head;
    printf("Element: %d\n",ptr->data);
    ptr = ptr->next;
    do
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
    while(ptr != head);
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));
    sixth = (struct Node *) malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 12;
    head->next = second;

    // Link second and third nodes
    second->data = 1;
    second->next = third;

    // Link the third and fourth nodes
    third->data = 22;
    third->next = fourth;

    // Link the fourth and fifth nodes
    fourth->data = 94;
    fourth->next = fifth;

    // Link the fifth and sixth nodes
    fifth->data = 90;
    fifth->next = sixth;

    // link the sixth node to head and convert to circular
    sixth->data = 99;
    sixth->next = head;

    // linked list before operations
    circularTraversal(head);

    return 0;
}