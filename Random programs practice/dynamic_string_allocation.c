#include <stdio.h>
#include <stdlib.h>

// // Function to calculate the length of a string using a macro
#define STRING_LENGTH(string) (sizeof(string) / sizeof((string)[0]) - 1)

// Function to print the string
void printString(char *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", A[i]);
    }
}

int main()
{
    // Initial allocation
    size_t capacity = 10; // Start with an initial capacity
    char *abc = (char *)malloc(capacity * sizeof(char));
    // if (abc == NULL) 
    // {
    //     printf("Memory allocation failed!\n");
    //     return 1; // Exit if allocation fails
    // }

    printf("Enter a string: ");
    size_t length = 0; // Actual length of the string
    int ch;

    // Read characters one by one
    while ((ch = getchar()) != '\n' && ch != EOF) 
    {
        // Check if we need more space
        if (length >= capacity) 
        {
            capacity *= 2; // Double the capacity
            char *new_abc = (char *)realloc(abc, capacity * sizeof(char));
            
            // if (new_abc == NULL) 
            // {
            //     printf("Memory allocation failed!\n");
            //     free(abc); // Free previously allocated memory
            //     return 1; // Exit if reallocation fails
            // }

            abc = new_abc; // Update pointer
        }

        abc[length++] = (char)ch; // Store the character
    }
    
    // Null-terminate the string
    abc[length] = '\0';

    // Print the length using the macro and the string
    printf("%zu is string length.\n", length);
    printString(abc, length);

    // Free the dynamically allocated memory
    free(abc);
    return 0;
}