#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct Node * insertAtIndex(struct Node *head, int data, int index)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node * insertAtEnd(struct Node *head, int data)
    {
        struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
        struct Node *p = head;
        int i = 0;
        while(p->next != NULL)
        {
            p = p->next;
            i++;
        }
        p->next = ptr;
        ptr->data = data;
        ptr->next = NULL;
        return head;
    }

    struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data)
    {
        struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data=data;
        ptr->next=prevNode->next;
        prevNode->next=ptr;
        return head;
    }

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
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //  Allocate memory for nodes in the linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data=7;
    head->next=second;

    // Link second and third nodes
    second->data=11;
    second->next=third;

    // Link the third and fourth nodes
    third->data=41;
    third->next= fourth;

    // terminate the list at fourth node
    fourth->data=66;
    fourth->next= NULL;
    // traversal before case 1 : insert at beginning
    linkedListTraversal(head);

    // case 1:inserting at beginning
    head = insertAtFirst(head,56);

    printf("case 1 : insert at beginning\n");
    // traversal after case 1: insert at beginning
    linkedListTraversal(head);

    // case 2: insert at index/between
    head = insertAtIndex(head,12,1); // will not work for index = 0
    
    printf("case 2 : insert at index/between\n");
    // traversal after case 2: insert at index/between
    linkedListTraversal(head);

    // case 3: insert at end
    head = insertAtEnd(head,24);
    
    printf("case 3: insert at end\n");
    // traversal after case 3: insert at end
    linkedListTraversal(head);

    // case 4: insert after node
    head = insertAfterNode(head, second, 192);
    
    printf("case 4: insert after node\n");
    // traversal after case 4: insert after node
    linkedListTraversal(head);

    return 0;
}