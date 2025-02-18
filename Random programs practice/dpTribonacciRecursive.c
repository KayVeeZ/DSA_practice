#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to initialize array with a specific value (-1 for memoization)
void init_array(long long *arr, int size)
{
    for (int i = 0; i < size; i++)  // Loop goes from 0 to size-1
    {
        arr[i] = -1;  // Initialize all elements to -1
    }
}

// Recursive Tribonacci function with memoization
long long tribonacci(int num, long long *store)
{
    if (store[num] != -1) return store[num];  // Return if already computed

    if (num == 0) return 0;  // Base case
    else if (num == 1 || num == 2) return 1;  // Base cases for 1 and 2
    else {
        store[num] = tribonacci(num - 1, store) + tribonacci(num - 2, store) + tribonacci(num - 3, store);  // Recursively calculate and store
    }
    return store[num];
}

int main()
{
    long long digit = 0;
    do
    {
        printf("Enter the quantity of numbers for which you want to print the tribonacci sequence (only positive integers please): ");
        scanf("%lld", &digit);  // Use %lld for long long input
    } while (digit <= 0); // Ensures a positive integer is entered

    // Allocate memory for the memoization array
    long long *store = (long long *)malloc(digit * sizeof(long long));  // Allocate memory for 'digit' elements
    if (store == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation failed
    }

    // Initialize the memoization array
    init_array(store, digit);

    long long trib_list[digit];  // Array to store all values of the tribonacci sequence

    // Store values of the whole sequence in the array
    clock_t begin = clock();
    for (long long i = 0; i < digit; i++)
    {
        trib_list[i] = tribonacci(i, store);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // Print the tribonacci sequence
    printf("The tribonacci sequence for the provided number is:\n[");
    printf("%lf is time taken by c.\n",time_spent);
    for (long long i = 0; i < digit; i++)
    {
        if (i == digit - 1)  // Last element, no comma
            printf("%lld", trib_list[i]);  // Use %lld for long long output
        else
            printf("%lld, ", trib_list[i]);  // Use %lld for long long output
    }
    printf("]\n");

    // Free allocated memory
    free(store);

    // Exit mechanism
    int exit = 0;
    do
    {
        printf("Input 1 to exit...");
        scanf("%d", &exit);
    } while (exit != 1);
    
    return 0;
}
