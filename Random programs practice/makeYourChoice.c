#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    char *text;
    struct node *next;
};

// Function to dynamically allocate and input a string
char* stringInput()
{
    size_t capacity = 10;
    char *buffer = (char *)malloc(capacity * sizeof(char));

    if (buffer == NULL) 
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    size_t len = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) 
    {
        if (len >= capacity) 
        {
            capacity *= 2;
            char *new_buffer = (char *)realloc(buffer, capacity * sizeof(char));
            if (new_buffer == NULL) 
            {
                printf("Memory reallocation failed!\n");
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
        buffer[len++] = (char)ch;
    }

    if (len == 0) 
    {
        free(buffer);
        return NULL;
    }

    buffer[len] = '\0';
    return buffer;
}

// Function to free dynamically allocated memory for the linked list
void free_mem(struct node* head)
{
    struct node *p = head;
    while (p != NULL) 
    {
        struct node *next = p->next;
        free(p->text);
        free(p);
        p = next;
    }
}

// Function to print the choice at the given index (1-based index)
void print_choice(struct node *head, int index)
{
    struct node *p = head->next;  // Start from the first real node

    for (int i = 0; i < index - 1; i++)  // Adjust to 0-based indexing in the loop
    {
        if (p == NULL) 
        {
            printf("Error: Invalid index.\n");
            return;
        }
        p = p->next;
    }

    if (p != NULL) 
    {
        printf("%s\n", p->text);
    } 
    else 
    {
        printf("Error: No choice found at index %d.\n", index);
    }
}

int main()
{
    srand(time(NULL));  // Seed the random number generator with current time
    printf("Make up your mind!\n");
    printf("------------------\n\n");
    printf("This applet is brought to you by KayVeeZ, to make life choices easier.\n");
    printf("----------------------------------------------------------------------\n\n");

    printf("This app randomly selects from your choices to eliminate bias, giving you an impartial choice when you are stuck!\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n\n");
    
    // Ask for the user's name and handle potential memory allocation issues
    printf("Hello! What is your name?\n");
    char *name = stringInput();
    if (name == NULL)
    {
        printf("Memory allocation failed for name!\n");
        return 1;
    }

    // Set up the head of the linked list
    struct node *head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) 
    {
        printf("Memory allocation failed for head\n");
        free(name);  // Free previously allocated memory
        return 1;
    }

    head->text = (char *)malloc(2 * sizeof(char));
    if (head->text == NULL) 
    {
        printf("Memory allocation failed for head->text\n");
        free(name);
        free(head);
        return 1;
    }

    head->text[0] = 'a';  // Placeholder text
    head->text[1] = '\0';
    head->next = NULL;

    // Ask for the number of choices
    int num_choices;
    printf("\nSo, %s, what are the number of options in your dilemma you are facing? ", name);
    scanf("%d", &num_choices);
    getchar();  // Consume newline character

    if (num_choices <= 0) 
    {
        printf("Number of choices must be greater than 0\n");
        free_mem(head);
        free(name);
        return 1;
    }

    struct node *a = NULL, *b = NULL;

    // Create the linked list of choices
    for (int i = 0; i < num_choices; i++) 
    {
        printf("\nOption %d:\n", i + 1);
        b = (struct node *)malloc(sizeof(struct node));
        if (b == NULL) 
        {
            printf("Memory allocation failed for node.\n");
            free_mem(head);
            free(name);
            return 1;
        }

        b->text = stringInput();
        if (b->text == NULL) 
        {
            printf("Invalid input. Please enter a valid choice.\n");
            free(b);
            i--;  // Retry the current iteration
            continue;
        }

        b->next = NULL;

        if (i == 0)
            head->next = b;
        else
            a->next = b;

        a = b;
    }

    // Generate a random index (0 to num_choices - 1)
    int random_index = rand() % num_choices;

    // Print the randomly selected choice
    printf("\nYou should do the following:\n");
    print_choice(head, random_index + 1);  // Pass 1-based index to print_choice
    printf("\n");
    // Free the dynamically allocated memory
    free_mem(head);
    free(name);  // Don't forget to free the name string

    // Wait for user input to exit
    int exit_code = 0;
    
    printf("Thank you for using my app. Please support me by praying for me in my endeavours.\n\n");
    while (exit_code != 1)
    {
        printf("Input 1 to exit: ");
        scanf("%d", &exit_code);
    }

    return 0;
}
