#include<stdio.h>
#include<malloc.h>

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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    return 1;
}

struct node *searchIter(struct node* root, int key)
{
    while (root!=NULL)
    {
        if (key == root->data) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

void insert(struct node* root, int key)
{
    struct node* prev = NULL;
    struct node* ptr;
    
    while (root!=NULL)
    {
        prev = root;
        if (key == root->data) 
        {
            printf("Error: Cannot insert %d, already present in BST!\n", key);
            return;
        }
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    // create the node and link appropriately to prev node
    ptr = createNode(key);
    if (key < prev->data) prev->left = ptr;
    else prev->right = ptr;
    
}

int main()
{
    // constructing nodes using function
    struct node *p = createNode(5); 
    struct node *p1 = createNode(3); 
    struct node *p2 = createNode(6); 
    struct node *p3 = createNode(1); 
    struct node *p4 = createNode(4); 

    // linking the nodes to create a binary tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

          /*
    The binary tree in this:
        5
       / \
      3   6
     / \
    1   4
    */
   int insertElement = 6;
   struct node* n = searchIter(p, insertElement);
   if (n!= NULL) printf("Found: %d\n", n->data);
   else printf("Warning! Element %d not found in BST.\n", insertElement);

    // try to insert already present element
    insert(p, 6);
    
    insertElement = 7;
    n = searchIter(p, insertElement);
    // element is not inserted should print warning
   if (n!= NULL) printf("Found: %d\n", n->data);
   else printf("Warning! Element %d not found in BST.\n", insertElement);

    // insert and check again
    insert(p, 7);

   n = searchIter(p, insertElement);
   if (n!= NULL) printf("Found: %d\n", n->data);
   else printf("Warning! Element %d not found in BST.\n", insertElement);

    inOrder(p);

    printf("\n%d\n", p->right->right->data);
    return 0;
}