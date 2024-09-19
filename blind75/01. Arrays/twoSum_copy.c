#include<stdio.h>
#include<stdlib.h>

#define ARRAY_LENGTH(array) (sizeof(array)/sizeof(array[0]))

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

struct hashNode
{
    int key;
    int value;
    struct hashNode* next;
};

int hashFunction(int key, int hashSize)
{
    return abs(key) % hashSize;
}

struct hashNode* createNode(int key, int value)
{
    struct hashNode* newNode = (struct hashNode*)malloc(sizeof(struct hashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(struct hashNode** hashMap, int key, int value, int hashSize)
{
    int index = hashFunction(key, hashSize);
    struct hashNode* newNode = createNode(key, value);
    if (hashMap[index] == NULL)
    {
        hashMap[index] = newNode;
    }
    else
    {
        newNode->next = hashMap[index];
        hashMap[index] = newNode;
    }
}

int find(struct hashNode** hashMap, int key, int hashSize)
{
    int index  = hashFunction(key, hashSize);

    struct hashNode* current = hashMap[index];
    while (current != NULL)
    {
        if (current-> key = key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int hashSize = numsSize;

    struct hashNode** hashMap = (struct hashNode**)calloc(hashSize, sizeof(struct hashNode));

    int *result = (int*)malloc(2*sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int complementIndex = find(hashMap, complement, hashSize);
        if (complementIndex != -1)
        {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        insert(hashMap, nums[i], i, hashSize);
    }
    free(result);
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[] = {2,7,11,15};
    int target = 18;
    int numsSize = ARRAY_LENGTH(nums);
    int *returnSize = (int *)malloc(sizeof(int));
    int *returnSize1 = (int *)malloc(sizeof(int)*2);
    returnSize1= twoSum(nums, numsSize, target, returnSize);
    printArray(returnSize1,2);
    free(returnSize);
    free(returnSize1);
    return 0;
}