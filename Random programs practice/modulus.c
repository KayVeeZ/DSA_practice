#include <stdio.h>

int modulus(int a, int b)
{
    int quotient, remainder, product;
    quotient = a / b;
    product = quotient * b;
    remainder = a - product;
    return remainder;
}

int floor1(int a, int b)
{
    int quotient, remainder, product;
    quotient = a / b;
    product = quotient * b;
    remainder = a - product;
    return quotient;
}



int main()
{
    int a = 50, b = 6;
    int r = modulus(a,b);
    int f = floor1(a,b);
    printf("modulus of %d and %d is %d\n",a,b,r);
    printf("modulus of %d and %d is %d\n",a,b,a%b);
    printf("floor division of %d and %d is %d\n",a,b,f);

    float e = 2.5;
    int d = (int)e;
    printf("Type casted integer is %d", d);
}