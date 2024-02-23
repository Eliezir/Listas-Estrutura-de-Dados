// Suponha que um texto está armazenado em um array onde cada posição contém um caracter. O texto pode conter os 256 caracteres da tabela ASCII. Escreva uma função para criar uma lista encadeada onde cada nó possui o caracter e a sua frequência no texto. Para esta questão, navegar pela lista que está sendo criada é proibido. Lembre-se que para inserir um nó na lista, podemos ter O(1).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    int frequency;
    struct node *next;
};

struct node *add_node(struct node *head, char data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->frequency = 1;
    new_node->next = head;
    return new_node;
}

void print_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%c %d\n", temp->data, temp->frequency);
        temp = temp->next;
    }
}

void bubble_sort(char *input, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (input[j] > input[j + 1])
            {
                char temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char input[100];
    struct node *head = NULL;
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        int length = strlen(input);
        bubble_sort(input, length);
        for (int i = 0; i < length; i++)
        {
            struct node *temp = head;
            while (temp != NULL)
            {
                if (temp->data == input[i])
                {
                    temp->frequency++;
                    break;
                }
                temp = temp->next;
            }
            if (temp == NULL)
                head = add_node(head, input[i]);
        }
    }
    print_list(head);
    return 0;
}