#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a,int b)
{
    return a>b?a:b;
}

int getHeight(struct node *n)
{
    if(n==NULL) return 0;
    return n->height;
}

struct node *createNode(int key)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalanceFactor(struct node* n)
{
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

struct node* rightRotate(struct node* y)
{
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL) return(createNode(key));

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node; // duplicate node prevention
    }
    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    
    // Right Right case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // Left Right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrder(root);
    return 0;
}