#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *add_node(struct node *head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

void shift_list(struct node *head)
{
    struct node *previous = NULL;
    struct node *current = head;
    struct node *temp_next = current->next;
    while (1)
    {
        if (current->next == NULL)
        {
            current->next = previous;
            break;
        }
        current->next = previous;
        previous = current;
        current = temp_next;
        temp_next = current->next;
    }
}

void print_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *previous = NULL;
    struct node *head = NULL;
    struct node *first = NULL;

    while (1)
    {
        int data;
        if (scanf("%d", &data) == EOF)
            break;
        head = add_node(NULL, data);
        first = first != NULL ? first : head;
        if (previous != NULL)
            previous->next = head;
        previous = head;
    }

    shift_list(first);
    print_list(head);
    return 0;
}