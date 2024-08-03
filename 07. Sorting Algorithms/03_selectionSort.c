#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    printf("Running selection sort.....\n");
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12};
    // int A[] = {1, 2, 3, 4, 5, 6};
    int n = 5;
    printArray(A, n);    // Printing the array before sorting
    selectionSort(A, n); // function to sort the array
    printArray(A, n);
    return 0;
}