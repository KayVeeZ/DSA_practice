#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    // Allocate memory for the result array
    int *res = (int *)calloc(numsSize, sizeof(int));
    if (!res) return NULL; // Check for allocation failure

    int L = 0;
    int R = numsSize - 1;

    for (int i = numsSize - 1; i >= 0; i--)
    {
        // Compare absolute values of elements at L and R
        if (abs(nums[L]) > abs(nums[R]))
        {
            res[i] = nums[L] * nums[L]; // Store square of the larger absolute value
            L++;
        }
        else
        {
            res[i] = nums[R] * nums[R]; // Store square of the larger absolute value
            R--;
        }
    }

    // Set the return size
    *returnSize = numsSize;

    // Return the result array
    return res;
}

int main() {
    int nums[] = {-4, -1, 0, 3, 10}; // Example input array
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    // Call the sortedSquares function
    int* squared = sortedSquares(nums, numsSize, &returnSize);

    // Check if the function returned NULL
    if (squared == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if allocation fails
    }

    // Print the resulting array
        printf("Squared sorted array: ");
    printArray(squared, returnSize);

    // Free the dynamically allocated memory
    free(squared);
    
    return 0;
}
