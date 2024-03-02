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
            if (temp->data < temp2->data)
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

struct node *clone_list(struct node *head)
{
    struct node *new_head = NULL;
    struct node *temp = head;
    while (temp != NULL)
    {
        new_head = add_node(new_head, temp->data);
        temp = temp->next;
    }
    return new_head;
}

void clear_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        struct node *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}

int main()
{
    struct node *head = NULL;
    struct node *head2 = NULL;
    int testCases;
    scanf("%d", &testCases);
    for (int i = 0; i < testCases; i++)
    {
        int students;
        scanf("%d", &students);
        for (int j = 0; j < students; j++)
        {
            int data;
            scanf("%d", &data);
            head = add_node(head, data);
        }
        head2 = clone_list(head);
        sort_list(head);

        struct node *temp = head;
        struct node *temp2 = head2;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->data == temp2->data)
            {
                // printf("temp1 = %d, temp2 = %d\n", temp->data, temp2->data);
                count++;
            }

            // printf("temp1 = %d, temp2 = %d\n", temp->data, temp2->data);

            temp = temp->next;
            temp2 = temp2->next;
        }
        printf("%d\n", count);
        clear_list(head);
        head = NULL;
    }

    return 0;
}
