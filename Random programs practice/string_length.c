#include <stdio.h>
#include <stdlib.h>

// macro to calculate the length of a string
#define STRING_LENGTH(string) (sizeof(string) / sizeof((string)[0]) - 1)

// Function to print string
void printString(char *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", A[i]);
    }
}

int main()
{
    char abc[] = "Hello, World!";
    printf("%d is string length.\n",STRING_LENGTH(abc));
    printString(abc, STRING_LENGTH(abc));
}