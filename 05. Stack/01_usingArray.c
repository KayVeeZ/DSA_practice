#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// check empty for stack do video
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

// check full for stack
int isFull(struct stack *ptr)
{
    if(ptr->top >= ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s)
{
    int element = 0;
    printf("Please enter element to be pushed: ");
    scanf("%d", &element);
    printf("--------------------------------------\n");
    s->arr[s->top+1] = element;
    s->top++;
    // return *s;
}

void pop(struct stack *s)
{
    int element1 = s->arr[s->top];
    s->top--;
    printf("Popped element is %d\n", element1);
    // return *s;
}

void display(struct stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("Element %d is %d\n", abs(i-s->top)+1,s->arr[i]);
    }
}

int peek(struct stack *s, int position)
{
    for (int i = s->top; i >= 0; i--)
    {
        if(position == i)
        {
            return s->arr[i];
        }

    }
    return -1;
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size*sizeof(int));

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    (*s).size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    printf("Stack initialized successfully. \nPlease note this stack is based on an array. \nThis array has a max size of %d.\n", s->size);
    int choice = 0;
    do
    {
        printf("Enter the intended operation on stack:\n");
        printf("--------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("--------------------------------------\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        printf("--------------------------------------\n");


        switch (choice)
        {
            case 1:

            if (isFull(s) == 1)
            {
                printf("Error: Stack Overflow!\n");
                break;
            }

            else
            {            
                push(s);
                break;
            }

            case 2:
            if (isEmpty(s) == 1)
            {
                printf("Error: Stack is Empty!\n");
                break;
            }
            else
            {
                pop(s);
                break;
            } 

            case 3:
            if (isEmpty(s) == 1)
            {
                printf("Error: Stack is Empty!\n");
                break;
            }
            else
            {
                display(s);
                break;
            }

            case 4:
            if (isEmpty(s) == 1)
            {
                printf("Error: Stack is Empty!\n");
                break;
            }
            else
            {
                int element = 0;
                int position = 0;
                printf("Which index of the stack do you want to peek at? ");
                scanf("%d", &position);
                element = peek(s, position);
                if (element != -1)
                {
                    printf("At index %d is this element: %d\n", position, element);
                    break;
                }
                else
                {
                    printf("No element at %d index!\n", position);
                    break;
                }
            }
            
        }

    }while(choice<5);

    printf("Thanks for using my program...\n");
    // Pushing an element manually
    // s->arr[0] = 21;
    // s->top++;
    free(s->arr);
    free(s);


    return 0;
}