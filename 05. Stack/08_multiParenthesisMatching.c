#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};


int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr->top >= ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack* s, char element)
{
    if(isFull(s))
    {
        printf("Error: Stack Overflow, cannot push %c to stack\n",element);
    }
    else{
        s->top++;
        s->arr[s->top] = element;
    }
}

char pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Error: Stack is empty! Cannot pop from the stack!\n");
        return -1;
    }
    else
    {
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int match(char a, char b)
{
    if(a == '{' && b== '}') return 1;
    if(a == '(' && b== ')') return 1;
    if(a == '[' && b== ']') return 1;
    return 0;  
}

int parenthesisMatching(char *exp)
{
    struct stack *s = (struct stack *)malloc(sizeof(exp));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; exp[i] !='\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty(s))
            {
                return 0;
            }
            char popped_ch = pop(s);
            if(!match(popped_ch, exp[i] ))
            {
                return 0;
            }
        }
    }

    int isBalanced = isEmpty(s);

    free(s->arr);
    free(s);
    return isBalanced;
}

int main()
{
    size_t buffer_size = 100;  // Initial buffer size

    char *exp = (char *)malloc(buffer_size * sizeof(char));
    
    if (exp == NULL) 
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter the expression to be matched: ");
    if (fgets(exp, buffer_size, stdin) == NULL) 
    {
        printf("Failed to read input\n");
        free(exp);
        return -1;
    }

    // Remove the newline character if it exists
    size_t len = strlen(exp);
    if (len > 0 && exp[len - 1] == '\n') {
        exp[len - 1] = '\0';
    }

    if(parenthesisMatching(exp) == 1) printf("The parenthesis is matching\n"); 
    else printf("The parenthesis is not matching\n");
    
    free(exp);
    


    return 0;
}