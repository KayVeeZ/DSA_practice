#include <stdio.h>
#include <stdlib.h>

// Function to calculate the length of a string
#define STRING_LENGTH(string) (sizeof(string) / sizeof((string)[0]) - 1)

void stringLength(char *str)
{
    size_t length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }

    printf("%zu is string length.\n", length);
}

// Function to print the string
void printString(char *A)
{
    // Print the string until null terminator
    for (size_t i = 0; A[i] != '\0'; i++)
    {
        printf("%c", A[i]);
    }
    printf("\n");
}

// Function to allocate memory for a string and read it dynamically
char* stringInput()
{
    size_t capacity = 10; // Start with an initial capacity
    char *buffer = (char *)malloc(capacity * sizeof(char)); // Allocate initial memory

    // // Check if memory allocation fails
    // if (buffer == NULL) 
    // {
    //     printf("Memory allocation failed!\n");
    //     return NULL; // Return NULL if allocation fails
    // }

    size_t len = 0; // Actual length of the string
    int ch;

    // Read characters one by one
    while ((ch = getchar()) != '\n' && ch != EOF) 
    {
        // Check if we need more space
        if (len >= capacity) 
        {
            capacity *= 2; // Double the capacity
            char *new_buffer = (char *)realloc(buffer, capacity * sizeof(char)); // Reallocate memory
            
            // // Check for reallocation failure
            // if (new_buffer == NULL) 
            // {
            //     printf("Memory reallocation failed!\n");
            //     free(buffer); // Free previously allocated memory
            //     return NULL; // Return NULL if reallocation fails
            // }

            buffer = new_buffer; // Update pointer
        }

        buffer[len++] = (char)ch; // Store the character
    }

    // Null-terminate the string
    buffer[len] = '\0';

    return buffer; // Return the dynamically allocated string
}

int main()
{
    printf("Enter a string: ");
    char *abc = stringInput(); // Call the function to read a dynamic string
    
    // // Check if the string was read successfully
    // if (abc == NULL) 
    // {
    //     return 1; // Exit if memory allocation fails
    // }

    stringLength(abc);

    printString(abc);

    // Free the dynamically allocated memory
    free(abc);

    char show[] = "mai sexy programmer hu";

    int len_show = STRING_LENGTH(show);
    printString(show);
    printf("Length of this string is %d\n", len_show);

    return 0;
}
