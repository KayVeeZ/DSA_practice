#include<stdio.h>
#include<stdlib.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {   
        for (int j = 0; j < numsSize; j++)
        {
            if(nums[i]+nums[j]==target && j!=i)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }    
    }
    free(result);
    return NULL;
}

int main()
{
    int nums[] = {2,7,11,15};
    int target = 18;
    int numsSize = 4;
    int *returnSize = (int *)malloc(sizeof(int));
    int *returnSize1 = (int *)malloc(sizeof(int)*2);
    returnSize1= twoSum(nums, numsSize, target, returnSize);
    printArray(returnSize1,2);
    free(returnSize);
    free(returnSize1);
    return 0;
}