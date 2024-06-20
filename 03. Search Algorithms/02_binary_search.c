#include<stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // search starts
    // Keep search until low and high converge i.e. low<=high
    while(low <= high)
        {
        mid = (low + high)/2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if(arr[mid] < element)
        {
            low = mid + 1;
        }
        else if(arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    // search ends
    return -1;
}

int main()
{
    // sorted array because binary search requires sorted array
    int arr[] = {2, 8, 14, 32, 66, 100, 104, 200, 400};
    int element = 200;
    int size = sizeof(arr)/sizeof(int);

    int searchIndex = binarySearch(arr, size, element);
    
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