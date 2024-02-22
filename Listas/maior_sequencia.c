#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void checkSequence(struct node *head)
{
    struct node *temp = head;
    int sequenceInitialPosition = 0;
    int sequenceFinalPosition = 0;
    int sequenceInitialPositionAux = 0;
    while (temp != NULL)
    {
        int sequenceSize = 0;
        while (temp->data == 0 && temp != NULL)
        {
            sequenceSize++;
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        if (sequenceSize > sequenceFinalPosition - sequenceInitialPosition)
        {
            sequenceInitialPosition = sequenceInitialPositionAux;
            sequenceFinalPosition = sequenceInitialPositionAux + sequenceSize;
        }
        if (sequenceSize == 0)
            sequenceInitialPositionAux++;
        else
            sequenceInitialPositionAux += sequenceSize + 1;
        temp = temp->next;
    }
    printf("%d %d\n", sequenceInitialPosition, sequenceFinalPosition += sequenceFinalPosition > 0 ? -1 : 0);
}

int main()
{

    while (1)
    {
        char input[100];
        struct node *previous = NULL;
        struct node *head = NULL;
        struct node *first = NULL;
        scanf(" %s", input);

        if (strcmp(input, "0") == 0)
        {

            break;
        }
        int i = 0;
        while (input[i] != '\0' && input[i] != '\n')
        {
            int data = input[i] - '0';
            head = add_node(NULL, data);
            first = first != NULL ? first : head;
            if (previous != NULL)
                previous->next = head;
            previous = head;

            i++;
        }
        checkSequence(first);
    }

    return 0;
}