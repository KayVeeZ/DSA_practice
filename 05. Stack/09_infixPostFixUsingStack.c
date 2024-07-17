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

int stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int stackBottom(struct stack *s)
{
    return s->arr[0];
}

int precedence(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    else if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *infixToPostfix(char *infix)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size*sizeof(char));
    char *postfix = (char *)malloc(strlen(infix)*sizeof(char));
    int i = 0; // track infix traversal
    int j = 0; // track postfix addition
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    free(s->arr);
    free(s);
    return postfix;
}


int main()
{
    char *infix = "x-y/z-k*d";
    printf("Postfix is %s",infixToPostfix(infix));
    return 0;
}