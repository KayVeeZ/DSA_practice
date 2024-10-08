#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preOrder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main()
{
    // construct nodes using function
    struct node *p = createNode(7);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(1);
    struct node *p3 = createNode(0);
    struct node *p4 = createNode(4);

    // linking
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    /*
    The binary tree in this:
        7
       / \
      2   1
     / \
    0   4
    */

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    return 0;
}