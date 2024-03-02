#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 255

typedef struct pilha
{
    ITEM vet[TAM];
    int topo;
} TPilha;

void create(TPilha *p)
{
    p->topo = -1;
}

void destroy(TPilha *p)
{
    p->topo = -1;
}

int isfull(TPilha *p)
{
    return p->topo == TAM;
}


void push(TPilha *p, ITEM x)
{
    if (isfull(p))
    {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}



// void printPilha(TPilha *p)
// {
//     for (int i = 0; i <= p->topo; i++)
//     {
//         printf("%c", p->vet[i]);
//     }
//     printf("\n");
// }

int isBalanced(char s[])
{
    TPilha pilha;
    create(&pilha);
    int start = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            push(&pilha, s[i]);
        }
    }
    int openBrackets = 0, openParentheses = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '(':
            openParentheses++;

            break;
        case ')':
            openParentheses--;
            break;
        case '[':
            openBrackets++;
            break;
        case ']':
            openBrackets--;
            break;
        }
        if (openBrackets < 0 || openParentheses < 0)
        {
            destroy(&pilha);
            return 0;
        }
    }
    // printPilha(&pilha);
    destroy(&pilha);
    // printf("openBrackets = %d, openParentheses = %d\n", openBrackets, openParentheses);
    return !openBrackets && !openParentheses;
}

int main(void)
{
    int loop;
    scanf("%d", &loop);
    getchar();
    for (int i = 0; i < loop; i++)
    {
        char string[TAM];
        fgets(string, TAM, stdin);
        // printf("%s\n", string);
        printf("%s\n", isBalanced(string) ? "Yes" : "No");
    }
    return 0;
}