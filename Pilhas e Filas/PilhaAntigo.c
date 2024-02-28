#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int current_size;
    int items[100];
};

struct stack *create_stack()
{
    struct stack *new_stack = (struct stack *)malloc(sizeof(struct stack));
    new_stack->current_size = 0;
    return new_stack;
}

void push(struct stack *stack, int item)
{

    stack->items[stack->current_size++] = item;
}

int pop(struct stack *stack)
{

    return stack->items[--stack->current_size];
}

void print_stack(struct stack *stack)
{
    for (int i = stack->current_size - 1; i >= 0; i--)
    {
        if (i == 0)
            printf("%d", stack->items[i]);
        else
            printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {

        char input[100];
        struct stack *stack = create_stack();
        while (1)
        {
            scanf(" %s", input);
            if (strcmp(input, "Empilhar") == 0)
            {
                int value;
                scanf(" %d", &value);
                push(stack, value);
                print_stack(stack);
            }
            else if (strcmp(input, "Desempilhar") == 0)
            {
                pop(stack);
                print_stack(stack);
            }

            else if (strcmp(input, "Fim") == 0)
                break;
        }
        break;
    }
}