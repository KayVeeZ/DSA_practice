#include<stdio.h>

int max(int a,int b)
    {
    return a > b? a:b; // if a is greater than b, return a else return b
    }

int main()
{
    
    printf("%d", max(2,3));    
    return 0;
}