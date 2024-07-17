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

int parenthesisMatching(char *exp)
{
    struct stack *s = (struct stack *)malloc(sizeof(exp));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; exp[i] !='\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s,'(');
        }
        else if(exp[i] == ')')
        {
            if(isEmpty(s))
            {
                return 0;
            }
                pop(s);
        }
    }

    int isBalanced = isEmpty(s);

    free(s->arr);
    free(s);
    return isBalanced;
}

int main()
{
    char *exp = (char *)malloc(100 * sizeof(char));
    if (exp==NULL) printf("Memory allocation failed");

    printf("Enter the expression to be matched: ");
    scanf("%99s", exp);

    if(parenthesisMatching(exp) == 1) printf("The parenthesis is matching\n"); 
    else printf("The parenthesis is not matching\n");
    
    


    return 0;
}