#include<stdio.h>
#include<stdlib.h>

// Function to initialize array with a specific value (-1 for memoization)
void init_array(long long *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;  // Initialize all elements to -1
    }
}

// Iterative Tribonacci function
long long tribonacci(int num, long long *store)
{
    // Base cases
    if (num == 0) return 0;
    if (num == 1 || num == 2) return 1;

    // Initialize first three values in the store
    store[0] = 0;
    store[1] = 1;
    store[2] = 1;

    // Compute Tribonacci numbers iteratively
    for (int i = 3; i <= num; i++)
    {
        store[i] = store[i - 1] + store[i - 2] + store[i - 3];  // Use previous three values
    }

    return store[num];  // Return the Tribonacci number at position `num`
}

int main()
{
    long long digit = 0;
    do
    {
        printf("Enter the quantity of numbers for which you want to print the Tribonacci sequence (only positive integers please): ");
        scanf("%lld", &digit);
    } while (digit <= 0); // Ensures a positive integer is entered

    // Allocate memory for the memoization array
    long long *store = (long long *)malloc((digit + 1) * sizeof(long long));  // Allocate memory for `digit + 1` elements
    if (store == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation failed
    }

    // Initialize the memoization array
    init_array(store, digit + 1);

    // Print the Tribonacci sequence
    printf("The Tribonacci sequence for the provided number is:\n[");
    for (long long i = 0; i < digit; i++)
    {
        printf("%lld", tribonacci(i, store));  // Use %lld for long long output

        if (i < digit - 1) {
            printf(", ");  // Add comma and space between numbers
        }
    }
    printf("]\n");

    // Free allocated memory
    free(store);

    return 0;
}
