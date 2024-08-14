#include<stdio.h>

long long tribonacci(long long digit)
{
    if(digit == 1)
    {
        return 1;
    }
    else if (digit == 2)
    {
        return 1;
    }
    else if (digit == 3)
    {
        return 1;
    }
    else if (digit > 3)
    {
        long long result = tribonacci(digit -1)+tribonacci(digit -2)+tribonacci(digit -3);
        return result;
    }
}

int main()
{
    long long digit = 0;
    do
    {
        printf("Enter the quantity of numbers for which you want to print the tribonacci sequence (only positive integers please): ");
        scanf("%d",&digit);
    } while (digit <= 0); // this makes sure a positive integer is entered

    long long trib_list[digit]; // empty array to store all values of tribonacci sequence

    // for loop stores values of whole sequence in the array
    for (long i = 0; i<digit; i++)
    {
        trib_list[i] = tribonacci(i+1);
    }
    // edge case for only one number of sequence requested
    if (digit == 1) printf("The tribonacci sequence for provided number is:\n[%d]\n",trib_list[0]);
    else
    {
    // print the whole array number by number
    for (long i = 0; i<digit; i++)
        {
            if (i == 0) printf("The tribonacci sequence for provided number is:\n[%d, ",trib_list[i]);
            else if (i!= 0 && i < digit - 1) printf("%d, ",trib_list[i]);
            else printf("%d]\n",trib_list[i]);
        }
    }
    int exit = 0;
    do
    {
        printf("Input 1 to exit...");
        scanf("%d", &exit);
    } while (exit != 1);
    

    return 0;
}