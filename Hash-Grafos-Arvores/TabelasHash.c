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
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->next = NULL;

    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        node *temp = table[index];
        node *prev = NULL;
        while (temp != NULL && temp->key < key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
        {
            newNode->next = table[index];
            table[index] = newNode;
        }
        else
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }
}

void removeNode(node **table, int key, int size)
{
    int index = key % size;
    node *temp = table[index];
    if (temp != NULL && temp->key == key)
    {
        table[index] = temp->next;
        free(temp);
    }
    else
    {
        while (temp != NULL && temp->next != NULL && temp->next->key != key)
        {
            temp = temp->next;
        }
        if (temp != NULL && temp->next != NULL)
        {
            node *aux = temp->next;
            temp->next = aux->next;
            free(aux);
        }
    }
}

void printTable(node **table, int size)
{
    printf("imprimindo tabela hash:\n");
    for (int i = 0; i < size; i++)
    {
        printf("[%d]:", i);
        node *temp = table[i];
        if (temp == NULL)
        {
            printf("Lista vazia!\n");
        }
        else
        {
            while (temp != NULL)
            {
                printf("%d=>", temp->key);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int countTableHash(node **table, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        node *temp = table[i];
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
    }
    return count;
}

void searchNode(node **table, int key, int size)
{
    int index = key % size;
    node *temp = table[index];
    int count = 0;
    int total = countTableHash(table, size);
    while (temp != NULL)
    {
        count++;
        if (temp->key == key)
        {
            printf("numero de elementos da tabela hash: %d\n", total);
            printf("elemento %d encontrado!\n", key);
            printf("numero de elementos acessados na tabela hash: %d\n", count);
            return;
        }
        temp = temp->next;
    }
    printf("numero de elementos da tabela hash: %d\n", total);
    printf("elemento nao encontrado!\n");
    printf("numero de elementos acessados na tabela hash: %d\n", count);
}

int main()
{
    int size;
    scanf("%d", &size);
    node **table = (node **)malloc(size * sizeof(node *));
    for (int j = 0; j < size; j++)
    {
        table[j] = NULL;
    }
    while (1)
    {
        char key;
        scanf(" %c", &key);
        // printf("comando: %c\n", key);
        switch (key)
        {
        case 'a':
        {
            int value;
            scanf("%d", &value);
            insertNode(table, value, size);
            break;
        }
        case 'r':
        {
            int value;
            scanf("%d", &value);
            removeNode(table, value, size);
            break;
        }
        case 'i':
        {
            printTable(table, size);
            break;
        }
        case 'p':
        {
            int value;
            scanf("%d", &value);
            printf("BUSCA POR %d\n", value);
            searchNode(table, value, size);
            break;
        }
        case 'f':
        {
            return 0;
        }
        }
    }
    return 0;
}
