#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM char
#define TAM 50

typedef struct pilha
{
    ITEM vet[TAM];
    int topo;
} TPilha;

void create(TPilha *p)
{
    p->topo = -1;
}

int isfull(TPilha *p)
{
    return p->topo == TAM;
}

int destroy(TPilha *p)
{
    p->topo = -1;
}

int isempty(TPilha *p)
{
    return p->topo == -1;
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

ITEM pop(TPilha *p)
{
    if (isempty(p))
    {
        puts("underflow");
        abort();
    }
    ITEM x = p->vet[p->topo];
    p->topo--;
    return x;
}

ITEM top(TPilha *p)
{
    if (isempty(p))
    {
        puts("underflow");
        abort();
    }
    return p->vet[p->topo];
}

int main()
{
    TPilha back, forward;
    create(&back);
    create(&forward);
    int commands = 0;
    char comando[TAM];
    while (scanf("%s", comando) != EOF)
    {
        if (strcmp(comando, "ENTER") == 0 && commands > 0)
        {
            push(&back, comando[0]);
            if (!isempty(&forward))
            {
                destroy(&forward);
                create(&forward);
            }
        }
        else if (strcmp(comando, "BACK") == 0)
        {
            if (!isempty(&back))
            {
                pop(&back);
            }
            push(&forward, comando[0]);
        }
        else if (strcmp(comando, "FORWARD") == 0)
        {
            if (!isempty(&forward))
            {
                pop(&forward);
            }
            push(&back, comando[0]);
        }
        else if (strcmp(comando, "QUIT") == 0)
        {
            break;
        }
        commands++;
    }

    int countBack = 0, countForward = 0;
    while (!isempty(&back))
    {
        pop(&back);
        countBack++;
    }
    while (!isempty(&forward))
    {
        pop(&forward);
        countForward++;
        // printf("FORWARD: %d\n", countForward);
    }
    printf("BACK: %d\n", countBack);
    printf("FORWARD: %d\n", countForward);

    return 0;
}
