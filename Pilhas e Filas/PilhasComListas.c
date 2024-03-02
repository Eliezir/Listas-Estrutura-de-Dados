#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *data;
    struct node *next;
};

struct stack
{
    int current_size;
    struct node *items;
};

struct stack *create_stack()
{
    struct stack *new_stack = (struct stack *)malloc(sizeof(struct stack));
    new_stack->current_size = 0;
    new_stack->items = NULL;
    return new_stack;
}

void push(struct stack *stack, char *item)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = strdup(item);
    new_node->next = stack->items;
    stack->items = new_node;
    stack->current_size++;
}


char *pop(struct stack *stack)
{
    if (stack->current_size == 0)
    {
        return NULL;
    }
    struct node *top = stack->items;
    char *item = top->data;
    stack->items = top->next;
    free(top);
    stack->current_size--;
    return item;
}

void print_stack(struct stack *stack)
{
    struct node *current = stack->items;
    while (current != NULL)
    {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main()
{
    struct stack *stack = create_stack();
    char input[100];
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        input[strcspn(input, "\n")] = 0;
        if (strncmp(input, "PUSH", 4) == 0)
        {
            char value[100000];
            fgets(value, sizeof(value), stdin);
            value[strcspn(value, "\n")] = 0;
            push(stack, value);
        }
        else if (strncmp(input, "POP", 3) == 0)
        {
            if ( stack->current_size == 0)
            {
                printf("EMPTY STACK\n");
            }
            else
            {
                char *popped = pop(stack);
                if (popped != NULL)
                {
                    printf("%s\n", popped);
                }
            }
        }
    }
    return 0;
}