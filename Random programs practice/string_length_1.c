#include<stdio.h>
#include<stdlib.h>

#define STRING_LENGTH(string) (sizeof(string) / sizeof((string)[0]) - 1)

int main()
{
    int len_str = -1;
    printf("Enter length of string you want to store: ");
    scanf("%d",&len_str);

    // Consume leftover newline from the buffer
    getchar();
    
    char *str = (char*)calloc(len_str + 1, sizeof(char));    
    printf("Enter your string: ");


    size_t char_start = 0; // starting point of storage of character
    int ch;

    while (char_start < len_str && (ch = getchar()) != '\n' && ch != EOF)
    {
        str[char_start++] = (char)ch;
    }  
    str[char_start] = '\0';

    printf("This is the string: %s\n",str);
    
    len_str = STRING_LENGTH(str); // macro here addresses the pointer instead of the string
    printf("This is the string length: %d\n", len_str);

    free(str);

    return 0;
}