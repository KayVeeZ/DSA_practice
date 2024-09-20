#include<stdio.h>
#include<string.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;

    char str[20];
    sprintf(str, "%d", x);  // Convert the integer to a string

    int str_len = strlen(str);  // Get the actual length of the string
    int i = 0, j = str_len - 1;  // Initialize j to the last character's index

    printf("%c this is the last char.\n", str[str_len-1]);
    
    printf("%d is string length.\n",str_len);
    while (i < j) {
        if (str[i] != str[j]) 
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    int x  = 12321;
    bool y = isPalindrome(x);
    printf("The provided number is a Palindrome: %s\n", y ? "true" : "false");  // Print the boolean value
    return 0;
}