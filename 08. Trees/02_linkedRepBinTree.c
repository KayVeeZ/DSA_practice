#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node *left;
struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node *n; /* creating a node pointer*/
    n = (struct Node*)malloc(sizeof(struct Node)); /*allocating memory from heap*/
    n->data = data; /*setting data value*/
    n->left = NULL; // setting left child to NULL
    n->right = NULL; // setting right child to NULL
    return n; // return the created node
}

int main()
{   
    /*
    //  constructing the root node
    struct Node *p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    //  constructing the second node
    struct Node *p1;
    p1 = (struct Node*)malloc(sizeof(struct Node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

//  constructing the third node
    struct Node *p2;
    p2 = (struct Node*)malloc(sizeof(struct Node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    // linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    */

    // constructing node using function createNode   
   struct Node *p = createNode(2);
   struct Node *p1 = createNode(1);
   struct Node *p2 = createNode(4);

    // linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    return 0;
}
