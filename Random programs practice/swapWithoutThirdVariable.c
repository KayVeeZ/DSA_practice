#include<stdio.h>
#include<stdlib.h>

void swap1(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    printf("a is now %d and b is now %d\n", *a, *b);  // Print dereferenced values
}

int main()
{
    int a = 2;  // Declare normal integer variables
    int b = 3;

    swap1(&a, &b);  // Pass the addresses of a and b
    
    return 0;
}
