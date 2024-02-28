/* Complete as funções de modo que o programa possa fazer as leituras das entradas e gerar as saídas correspondentes.

O programa deverá manipular uma estrutura de dados em que um único vetor é compartilhado por duas pilhas com o seguinte comportamento:

(I) A primeira pilha terá o topo na posição anterior ao primeiro índice do vetor e, antes da inserção de um novo item, será reposicionado para a posição sucessora, isto é, crescerá em direção ao fim do vetor.

(II) A segunda pilha terá o topo na posição seguinte ao último índice do vetor e, antes da inserção de um novo item, será reposicionado para a posição antecessora, isto é, crescerá em direção ao início do vetor.

Note que nesta estrutura o topo de uma pilha crescerá em direção ao topo da outra.

Observação: ambas as pilhas poderão usar todas as posições livres do vetor, ou seja, o vetor será compartilhado entre as pilhas de modo que, em um caso extremo, uma das pilhas ocupe todo o vetor e a outra, consequentemente, não ocupe posição alguma. */

#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

typedef struct pilha_dupla
{
    ITEM vet[TAM];
    int topo1, topo2;
} TPilhaDupla;

void create(TPilhaDupla *pd)
{
    pd->topo1 = -1;
    pd->topo2 = TAM;
}

void destroy(TPilhaDupla *pd)
{
    pd->topo1 = -1;
    pd->topo2 = TAM;
}

int isfull(TPilhaDupla *pd)
{
    return pd->topo1 + 1 == pd->topo2;
}

int isempty(TPilhaDupla *pd, int topo)
{
    return topo == -1 || topo == TAM;
}

void push(TPilhaDupla *pd, ITEM x, int topo)
{
    if (isfull(pd))
    {
        puts("overflow");
        abort();
    }
    if (topo == 1)
    {
        pd->topo1++;
        pd->vet[pd->topo1] = x;
    }
    else
    {
        pd->topo2--;
        pd->vet[pd->topo2] = x;
    }
}

ITEM pop(TPilhaDupla *pd, int topo)
{
    if (isempty(pd, topo))
    {
        puts("underflow");
        abort();
    }
    if (topo == 1)
    {
        ITEM x = pd->vet[pd->topo1];
        pd->topo1--;
        return x;
    }
    else
    {
        ITEM x = pd->vet[pd->topo2];
        pd->topo2++;
        return x;
    }
}

ITEM top(TPilhaDupla *pd, int topo)
{
    if (isempty(pd, topo))
    {
        puts("underflow");
        abort();
    }
    if (topo == 1)
    {
        ITEM x = pd->vet[pd->topo1];
        pd->topo1--;
        return x;
    }
    else
    {
        ITEM x = pd->vet[pd->topo2];
        pd->topo2++;
        return x;
    }
}

void preenche(TPilhaDupla *pd)
{
    ITEM x;
    int topo, qtd, i;

    scanf("%d%*c", &qtd);

    for (i = 0; i < qtd; i++)
    {
        scanf("%c %d%*c", &x, &topo);
        push(pd, x, topo);
    }
}

void exibe(TPilhaDupla *pd)
{
    int topo;

    while (scanf("%d", &topo) != EOF)
        printf("TOPO %d = %c\n", topo, pop(pd, topo));
}

int main(void)
{
    TPilhaDupla pd;

    create(&pd);
    preenche(&pd);
    exibe(&pd);
    destroy(&pd);

    return 0;
}
