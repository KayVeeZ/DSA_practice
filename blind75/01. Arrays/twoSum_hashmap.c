#include<stdio.h>
#include<stdlib.h>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

// Hash function to calculate the index of a key
int hashFunction(int key, int hashSize) {
    return abs(key) % hashSize;
}

// Create a hashmap node
struct HashNode* createNode(int key, int value) {
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a key-value pair into the hashmap
void insert(struct HashNode** hashMap, int key, int value, int hashSize) {
    int index = hashFunction(key, hashSize);
    struct HashNode* newNode = createNode(key, value);
    if (hashMap[index] == NULL) {
        hashMap[index] = newNode;
    } else {
        // Handle collision by chaining
        newNode->next = hashMap[index];
        hashMap[index] = newNode;
    }
}

// Find the value associated with a key in the hashmap
int find(struct HashNode** hashMap, int key, int hashSize) {
    int index = hashFunction(key, hashSize);
    struct HashNode* current = hashMap[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;  // If the key is not found
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
int hashSize = numsSize;
    struct HashNode** hashMap = (struct HashNode**)calloc(hashSize, sizeof(struct HashNode*));
    
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = find(hashMap, complement, hashSize);
        
        // If the complement is found in the hashmap, return the result
        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        
        // Otherwise, insert the current number into the hashmap
        insert(hashMap, nums[i], i, hashSize);
    }
    
    // Free allocated memory if no solution found
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