#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int highestNumber(int *A, int arr_len)
{
    int max = 0;
    for (int i = 0; i < arr_len; i++)
    {
        if (i == 0)
        {
            max = A[i];
        }
        else
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }
    }
    return max;
}

void countSort(int *A, int max, int arr_len)
{
    int i, j;
    int *count = (int *)malloc(sizeof(int) * (max + 1));

    // Initialize each element to zero
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // add 1 to each element of new array
    for (i = 0; i < arr_len; i++)
    {
        count[A[i]]++;
    }

    i = 0, j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int arr_len = ARRAY_LENGTH(A);
    int max = highestNumber(A, arr_len);
    printArray(A, arr_len);

    countSort(A, max, arr_len);

    printArray(A, arr_len);

    return 0;
}