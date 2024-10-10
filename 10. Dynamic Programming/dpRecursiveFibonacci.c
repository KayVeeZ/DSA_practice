#include<stdio.h>
#include<stdlib.h>

// Function to initialize array with a specific value (-1 for memoization)
void init_array(int *arr, int size)
{
    for (int i = 0; i <= size; i++)  // Fix off-by-one: loop should include size
    {
        arr[i] = -1;  // Initialize all elements to -1
    }
}

// Recursive Fibonacci function with memoization
int fibonacci(int num, int *store)
{
    if (store[num] != -1) return store[num];  // Return if already computed

    if (num == 0) return 0;  // Base case
    else if (num == 1) return 1;  // Base case
    else {
        store[num] = fibonacci(num - 1, store) + fibonacci(num - 2, store);  // Recursively calculate and store
    }
    return store[num];
}

int main()
{
    int num;
    printf("Enter the position of the number in the Fibonacci series: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;  // Invalid input case
    }

    // Allocate memory for the memoization array
    int *store = (int *)malloc((num + 1) * sizeof(int));  // Allocate num+1 elements
    if (store == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation failed
    }

    // Initialize the memoization array
    init_array(store, num);

    // Print the Fibonacci number at the given position
    printf("The number in the Fibonacci series is: %d\n", fibonacci(num, store));

    // Free allocated memory
    free(store);

    return 0;
}
