#include<stdio.h>
#include<stdlib.h>

// creating the unit type for linked list
struct Node{
    int data;
    struct Node * next;
};

// case 1
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    ptr->next = NULL; // not necessary
    free(ptr); // very important
    ptr = NULL; // avoid dangling pointer
    return head;
}

// case 2
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;

    q->next = NULL; // not necessary
    free(q); // very important
    q = NULL; // avoid dangling pointer
    return head;
}

// case 3
struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;

    q->next = NULL; // not necessary
    free(q); // very important
    q = NULL; // avoid dangling pointer
    return head;
}

// case 4
struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;

        q->next = NULL; // not necessary
        free(q); // very important
        q = NULL; // avoid dangling pointer
    }
    
    else
    {
        printf("Value not in Linked list\n");
    }
    
    return head;
}

// traversal of linked list
void linkedListTraversal(struct Node* ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;
    struct Node * sixth;

    //  Allocate memory for nodes in the linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));
    sixth = (struct Node *) malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data=7;
    head->next=second;

    // Link second and third nodes
    second->data=11;
    second->next=third;

    // Link the third and fourth nodes
    third->data=41;
    third->next= fourth;

    // Link the fourth and fifth nodes
    fourth->data=66;
    fourth->next= fifth;

    // Link the fifth and sixth nodes
    fifth->data=55;
    fifth->next= sixth;

    // terminate the list at sixth node
    sixth->data=77;
    sixth->next= NULL;

    // Linked List before Deletion
    printf("Linked List before Deletion\n");
    linkedListTraversal(head);

    // Case 1: Deleting the first element from the linked list
    printf("Case 1: Deleting the first element from the linked list\n");
    head = deleteFirst(head);
    linkedListTraversal(head);

    // // use again to check
    // printf("checking usability of delete first node\n");
    // head = deleteFirst(head);
    // linkedListTraversal(head);

    // Case 2: Deleting the element at a given index from the linked list
    int index = 2;
    printf("Case 2: Deleting the element at a given index from the linked list\n");
    head = deleteAtIndex(head, index);
    linkedListTraversal(head);

    // Case 3: Delete the last node
    printf("Case 3: Delete the last node\n");
    head = deleteLast(head);
    linkedListTraversal(head);

    // Case 4: Delete the element with a given value
    int value = 34;
    printf("Case 4: Delete the element with a given value\n");
    head = deleteAtValue(head, value); // note: not to be used for first node, for that use case look at case 1
    linkedListTraversal(head);

    return 0;
}