#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
} node;

node *newNode(int key)
{
    node *new = (node *)malloc(sizeof(node));
    new->key = key;
    new->next = NULL;
    return new;
}

void insertNode(node **table, int key, int size)
{
    int index = key % size;
    node *new = newNode(key);
    if (table[index] == NULL)
    {
        table[index] = new;
    }
    else
    {
        node *temp = table[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void printTable(node **table, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d -> ", i);
        node *temp = table[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\\\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int m, c;
        scanf("%d %d", &m, &c);
        node **table = (node **)malloc(m * sizeof(node *));
        for (int j = 0; j < m; j++)
        {
            table[j] = NULL;
        }
        for (int j = 0; j < c; j++)
        {
            int key;
            scanf("%d", &key);
            insertNode(table, key, m);
        }
        printTable(table, m);
        printf("\n");
    }
    return 0;
}