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

int checkIntersection(struct node *firstListHead, struct node *secondListHead)
{
    struct node *temp1 = secondListHead;
    struct node *temp2 = firstListHead;
    while (temp1 != NULL)
    {
        while (temp2 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                break;
            }
            if (temp2->next == NULL)
            {
                return 0;
            }

            temp2 = temp2->next;
        }
        temp2 = firstListHead;
        temp1 = temp1->next;
    }
    return 1;
}

int main()
{
    int firstListSize, secondListSize;
    struct node *firstListHead = NULL;
    struct node *secondListHead = NULL;
    scanf("%d", &firstListSize);
    for (int i = 0; i < firstListSize; i++)
    {
        int data;
        scanf("%d", &data);
        firstListHead = add_node(firstListHead, data);
    }
    scanf("%d", &secondListSize);
    for (int i = 0; i < secondListSize; i++)
    {
        int data;
        scanf("%d", &data);
        secondListHead = add_node(secondListHead, data);
    }
    printf("%d\n", checkIntersection(firstListHead, secondListHead));
}