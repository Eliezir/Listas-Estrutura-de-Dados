// Suponha dois números inteiros positivos representados por uma lista encadeada, em que cada nó armazena um único dígito. Escreva um programa para receber dois números representados desse modo e retornar a soma, também armazenada em uma lista encadeada.

// Obs1: Seu programa deve sempre ler e imprimir os dígitos de cada número do mais significativo para o menos significativo. A entrada pode conter zeros à esquerda; porém, no resultado calculado, a lista não deve incluir zeros à esquerda.

// Obs2: A referência para o início da lista deve ser padronizada: deve apontar sempre, ou para o dígito mais significativo, ou para o menos significativo, de todas as instâncias de listas utilizadas, de acordo com o padrão definido.

// Obs3: O símbolo '+' determina o término da entrada do primeiro número, enquanto que '=' determina o término da entrada do segundo número.

// Obs4: Caso uma lista que deveria representar um número esteja vazia, deve ser impressa na tela a mensagem 'Lista vazia!' no momento de sua impressão.

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

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    char num1, num2;
    char c;
    while (1)
    {
        scanf("%c", &num1);

        if (num1 == '+')
        {
            break;
        }
        if (num1 != ' ' && num1 != '\n')
        {
            int data = num1 - '0';
            head1 = add_node(head1, data);
        }
    }
    while (1)
    {
        scanf("%c", &num2);
        if (num2 == '=')
        {
            break;
        }
        if (num2 != ' ' && num2 != '\n')
        {

            int data = num2 - '0';
            head2 = add_node(head2, data);
        }
    }
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1 != NULL)
        {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != NULL)
        {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        head3 = add_node(head3, sum);
    }
    if (carry > 0)
    {
        head3 = add_node(head3, carry);
    }
    struct node *temp3 = head3;
    if (temp3 == NULL)
    {
        printf("Lista vazia!");
    }
    int isFirstDigit = 1;
    while (temp3 != NULL)
    {
        if (!isFirstDigit || temp3->data != 0)
        {
            printf("%d ", temp3->data);
            isFirstDigit = 0;
        }

        temp3 = temp3->next;
    }
    return 0;
}
