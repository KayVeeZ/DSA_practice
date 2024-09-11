#include <stdio.h>
#include <stdlib.h>

// Function to calculate the length of a statically defined array
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

// Function to print array
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// helper function for merge sort, can merge two sorted arrays by itself
void merge(int *A, int low, int mid, int high)
{
    int i = low, j = mid+1, k = low;
    int B[high+1]; // array to merge and sort the sorted arrays into
    
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

// mergesort function
void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        // get mid value
        int mid = (low + high)/2;

        // recursively breakdown array
        mergeSort(A, low, mid); 
        mergeSort(A, mid+1, high);

        // join and sort
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {7, 15, 2, 8, 10, 5, 20, 0, 9, 1, 3, -2};
    int low = 0;
    int high = ARRAY_LENGTH(A)-1;
    int len_c = ARRAY_LENGTH(A);
    mergeSort(A, low, high);

    printArray(A, len_c);

    return 0;
}