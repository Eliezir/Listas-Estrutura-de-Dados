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

void sort_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        struct node *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->data > temp2->data)
            {
                int aux = temp->data;
                temp->data = temp2->data;
                temp2->data = aux;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;

    while (1)
    {
        int data;
        if (scanf("%d", &data) == EOF)
        {
            break;
        }
        head = add_node(head, data);
    }

    // sort_list(head);
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}