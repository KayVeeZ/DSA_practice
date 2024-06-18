#include<stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 8, 14, 32, 66, 100, 104, 200, 400};
    int element = 101;
    int size = sizeof(arr)/sizeof(int);

    int searchIndex = linearSearch(arr, size, element);
    
    if (searchIndex == -1)
    {
        printf("Element not in array");
        return -1;
    }
    else
    {
        printf("%d was found at %d index.", element,searchIndex);
        return 0;
    }
}