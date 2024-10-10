#include<stdio.h>
#include<stdlib.h>

void init_array(int *arr, int size)
{
    int value = -1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

int fibonacci(int num, int *store)
{
    if (store[num] > -1) return store[num];
    else
    {
        if (num == 0) return 0;
        else if (num == 1) return 1;
        else store[num] = fibonacci(num - 1, store) + fibonacci(num - 2, store);
    }
    return store[num];
}

int main()
{
    
    int num = -1;
    printf("Enter the position of the number in the fibonacci series: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;  // Invalid input case
    }

    int *store = (int *)malloc((num+1)*sizeof(int));

    if (store == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation failed
    }
    
    init_array(store, num+1);

    printf("The number in the fibonacci series is: %d\n", fibonacci(num, store));
    
    free(store);
    return 0;
}