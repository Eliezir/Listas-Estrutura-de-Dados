#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

typedef struct deque
{
    ITEM vet[TAM];
    int front, rear;
} TDeque;

void create(TDeque *d)
{
    d->front = d->rear = 0;
}

void destroy(TDeque *d)
{
    d->front = d->rear;
}

int isfull(TDeque *d)
{
    return (d->rear + 1) % TAM == d->front;
}

int isempty(TDeque *d)
{
    return d->front == d->rear;
}

void store(TDeque *d, int extremidade, ITEM x)
{
    if (isfull(d))
    {
        puts("overflow");
        abort();
    }
    if (extremidade == 1)
    {
        d->front = (d->front - 1 + TAM) % TAM;
        d->vet[d->front] = x;
    }
    else
    {
        d->vet[d->rear] = x;
        d->rear = (d->rear + 1) % TAM;
    }
}

ITEM retrieve(TDeque *d, int extremidade)
{
    if (isempty(d))
    {
        puts("underflow");
        abort();
    }
    ITEM auxiliar;
    if (extremidade == 1)
    {
        auxiliar = d->vet[d->front];
        d->front = (d->front + 1) % TAM;
    }
    else
    {
        d->rear = (d->rear - 1 + TAM) % TAM;
        auxiliar = d->vet[d->rear];
    }
    return auxiliar;
}

void preenche(TDeque *d)
{
    ITEM x;
    int qtd, extremidade, i;

    scanf("%d%*c", &qtd);

    for (i = 0; i < qtd; i++)
    {
        scanf("%c %d%*c", &x, &extremidade);
        store(d, extremidade, x);
    }
}

void exibe(TDeque *d)
{
    int extremidade;

    while (scanf("%d", &extremidade) != EOF)
    {
        if (extremidade == 1)
            printf("INICIO = %c\n", retrieve(d, extremidade));
        else
            printf("FIM = %c\n", retrieve(d, extremidade));
    }
}

int main(void)
{
    TDeque d;

    create(&d);
    preenche(&d);
    exibe(&d);
    destroy(&d);

    return 0;
}