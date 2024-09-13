#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int parentIndex(int *A, int n, int nodeData)
{
    int resultIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == nodeData)
        {
            resultIndex = ((i+1)/2)-1;
            return resultIndex;
        }
    }
    return -2;
}

int main()
{
    int nodeData;
    int binTree[] = {7, 14, 23, 17, 1, 11, 9, 2,NULL,NULL,NULL,NULL,NULL,NULL,121};
    printf("These are the nodes of the binary tree:\n");
    printArray(binTree, 15);
    printf("Which node of the binary tree do you want to get the parent of? ");
    scanf("%d", &nodeData);

    int result = parentIndex(binTree, 15, nodeData);
    if (result == -1) printf("Entered node is root node.\n");
    else if (result == -2) printf("Node not found in binary tree.\n");
    else printf("%d has parent at %d index in the binary tree.\n", nodeData, result);
    return 0;
}