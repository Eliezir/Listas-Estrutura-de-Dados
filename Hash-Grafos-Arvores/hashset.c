// Descrição

// O objetivo deste exercício é implementar o TAD conjunto numérico baseado em  uma Hash Table aberta usando listas encadeadas. Esse conjunto deve suportar as seguintes operações:

// 1. ADD(S, k) = adiciona o elemento k ao conjunto S, retornando True se o elemento foi corretamente adicionado ou false se o elemento já pertencia ao conjunto.
// 2. DEL(S, k) = remove o elemento k do conjunto S, retornando True se o elemento foi corretamente removido ou False se o elemento não pertencia ao conjunto.
// 3. HAS(S, k) = retorna True se o elemento k pertence ao conjunto S ou false se o elemento não pertence ao conjunto.

// Os detalhes de implementação da Hash Table T são os seguintes:

// 1. Tamanho da tabela: a tabela deve ter uma capacidade inicial m=7.
// 2. Função de dispersão: deve ser usada a heurística da divisão, i.e. h(k)=k mod m
// 4. Inserção: os registros devem ser armazenadas em uma lista na posição correspondente. As inserções devem ser sempre realizadas no início da lista.
// 3. Fator de carga: O fator de carga a=n/m deve ser mantido em a<0.75. Assim que a>=0.75, todos os elementos da tabela atual devem ser redistribuidos (rehashing) numa nova tabela de tamanho 2*m-1 por ordem de posição na tabela corrente, ou seja, todos os elementos da lista em T[0] são realocados, do primeiro ao último elemento dessa lista, depois os da lista em T[1], na mesma ordem, e assim por diante até a lista T[m-1]. IMPORTANTE: essa verificação deve ser feita imediatamente *após* a inserção de cada novo elemento na tabela.

// Formato de entrada


// O arquivo de entrada consiste em uma sequência de w operações (conceitualmente numeradas de 0 a w-1), sendo uma por linha. As operações possíveis são as seguintes:

// ADD k = adiciona o elemento k
// DEL k = remove o elemento k
// HAS k = indica se o elemento k pertence ao conjunto
// PRT   = imprime alguns dados sobre a tabela (ver na descrição da saída)

// Limites:
// 1 <= w <= 100000
// 0 <= k < 2^20

// Formato de saída

// Para cada operação (numerada i=0,...,w-1) no arquivo de entrada, deve ser impresso o resultado correspondente sobre o conjunto, conforme descrito a seguir.

// a) ADD k: imprime a linha

// i r c

// onde
// i = número da operação
// r = resultado da operação (1=True, 0=False)
// c = número de comparações feitas (posições da lista visitadas) até a inserção (ou não) do valor correspondente, antes de um eventual rehashing


// b) DEL k: imprime a linha

// i r c

// onde
// i = número da operação
// r = resultado da operação (1=True, 0=False)
// c = número de comparações feitas (posições da lista visitadas) até a remoção (ou não) do valor correspondente


// c) HAS k: imprime a linha

// i r c

// onde
// i = número da operação
// r = resultado da operação (1=True, 0=False)
// c = número de comparações feitas (posições da lista visitadas) até a localização (ou não) do valor correspondente

// d) PRT: imprime a linha

// i m n l

// onde
// i = número da operação
// m = tamanho (capacidade da tabela)
// n = número de elementos da tabela (cardinalidade do conjunto)
// l = comprimento da maior lista da tabela (posição com mais elementos)

// Exemplos de:

// Entrada


// ADD 61
// HAS 68
// ADD 99
// ADD 51
// HAS 61
// HAS 3
// DEL 99
// ADD 90
// HAS 42
// ADD 94
// ADD 51
// ADD 70
// ADD 59
// ADD 80
// HAS 59
// ADD 35
// ADD 3
// PRT
// HAS 94
// DEL 70
// DEL 34
// DEL 84
// HAS 53
// HAS 97
// ADD 65
// ADD 79
// ADD 66
// ADD 64
// HAS 64
// HAS 15
// DEL 65
// ADD 82
// ADD 68
// ADD 77
// ADD 22
// ADD 2
// DEL 81
// HAS 55
// HAS 1
// HAS 85
// DEL 51
// ADD 70
// HAS 35
// PRT
// HAS 90
// ADD 43
// PRT
// ADD 70
// HAS 92
// ADD 58
// DEL 61
// PRT
// ADD 95
// HAS 100
// HAS 10
// DEL 76
// HAS 64
// ADD 41
// PRT
// HAS 90
// HAS 84
// HAS 58
// DEL 43
// ADD 68
// HAS 80
// HAS 30
// PRT
// PRT
// ADD 71
// PRT
// HAS 2
// DEL 66
// HAS 70
// ADD 30
// ADD 70
// ADD 30
// DEL 98
// HAS 35
// ADD 7
// ADD 62
// HAS 30
// HAS 68
// ADD 73
// DEL 68
// HAS 27
// ADD 50
// HAS 7
// ADD 47
// HAS 90
// ADD 21
// PRT
// HAS 35
// DEL 77
// ADD 0
// DEL 70
// HAS 79
// HAS 95
// HAS 50
// HAS 71
// PRT

// Saída


// 0 1 0
// 1 0 1
// 2 1 0
// 3 1 0
// 4 1 1
// 5 0 0
// 6 1 1
// 7 1 0
// 8 0 0
// 9 1 0
// 10 0 1
// 11 1 0
// 12 1 1
// 13 1 0
// 14 1 1
// 15 1 1
// 16 1 1
// 17 13 9 2
// 18 1 2
// 19 1 1
// 20 0 0
// 21 0 0
// 22 0 0
// 23 0 0
// 24 1 0
// 25 1 0
// 26 1 0
// 27 1 0
// 28 1 1
// 29 0 2
// 30 1 2
// 31 1 0
// 32 1 0
// 33 1 0
// 34 1 0
// 35 1 1
// 36 0 0
// 37 0 1
// 38 0 1
// 39 0 1
// 40 1 1
// 41 1 0
// 42 1 1
// 43 25 16 2
// 44 1 1
// 45 1 1
// 46 25 17 2
// 47 0 1
// 48 0 0
// 49 1 0
// 50 1 1
// 51 25 17 2
// 52 1 1
// 53 0 0
// 54 0 1
// 55 0 0
// 56 1 1
// 57 1 1
// 58 49 19 2
// 59 1 2
// 60 0 1
// 61 1 1
// 62 1 1
// 63 0 1
// 64 1 1
// 65 0 1
// 66 49 18 2
// 67 49 18 2
// 68 1 1
// 69 49 19 2
// 70 1 1
// 71 1 1
// 72 1 1
// 73 1 1
// 74 0 1
// 75 0 1
// 76 0 0
// 77 1 1
// 78 1 0
// 79 1 0
// 80 1 1
// 81 1 1
// 82 1 0
// 83 1 1
// 84 0 0
// 85 1 0
// 86 1 1
// 87 1 0
// 88 1 2
// 89 1 1
// 90 49 24 2
// 91 1 1
// 92 1 1
// 93 1 0
// 94 1 2
// 95 1 2
// 96 1 1
// 97 1 1
// 98 1 1
// 99 49 23 2


#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node *next;
} node;

typedef struct _hashset {
    int m;
    int n;
    int l;
    node **T;
} hashset;

hashset *create_hashset(int m) {
    hashset *hs = (hashset *)malloc(sizeof(hashset));
    hs->m = m;
    hs->n = 0;
    hs->l = 0;
    hs->T = (node **)malloc(m * sizeof(node *));
    for (int i = 0; i < m; i++) {
        hs->T[i] = NULL;
    }
    return hs;
}

void free_hashset(hashset *hs) {
    for (int i = 0; i < hs->m; i++) {
        node *p = hs->T[i];
        while (p != NULL) {
            node *q = p;
            p = p->next;
            free(q);
        }
    }
    free(hs->T);
    free(hs);
}

int h(int k, int m) {
    return k % m;
}

int add(hashset *hs, int k) {
    int i = h(k, hs->m);
    node *p = hs->T[i];
    int c = 0;
    while (p != NULL) {
        if (p->key == k) {
            return 0;
        }
        p = p->next;
        c++;
    }
    node *q = (node *)malloc(sizeof(node));
    q->key = k;
    q->next = hs->T[i];
    hs->T[i] = q;
    hs->n++;
    if (c > hs->l) {
        hs->l = c;
    }
    if (hs->n >= 0.75 * hs->m) {
        int m = 2 * hs->m - 1;
        node **T = (node **)malloc(m * sizeof(node *));
        for (int i = 0; i < m; i++) {
            T[i] = NULL;
        }
        for (int i = 0; i < hs->m; i++) {
            node *p = hs->T[i];
            while (p != NULL) {
                node *q = p;
                p = p->next;
                int j = h(q->key, m);
                q->next = T[j];
                T[j] = q;
            }
        }
        free(hs->T);
        hs->m = m;
        hs->T = T;
    }
    return 1;
}

int del(hashset *hs, int k) {
    int i = h(k, hs->m);
    node *p = hs->T[i];
    node *q = NULL;
    int c = 0;
    while (p != NULL) {
        if (p->key == k) {
            if (q == NULL) {
                hs->T[i] = p->next;
            } else {
                q->next = p->next;
            }
            free(p);
            hs->n--;
            return 1;
        }
        q = p;
        p = p->next;
        c++;
    }
    return 0;
}

int has(hashset *hs, int k) {
    int i = h(k, hs->m);
    node *p = hs->T[i];
    int c = 0;
    while (p != NULL) {
        if (p->key == k) {
            return 1;
        }
        p = p->next;
        c++;
    }
    return 0;
}

int main() {
    hashset *hs = create_hashset(7);
    int i = 0;
    char op;
    int k;
    while (scanf("%c %d\n", &op, &k) != EOF) {
        if (op == 'A') {
            printf("%d %d %d\n", i, add(hs, k), i);
        } else if (op == 'D') {
            printf("%d %d %d\n", i, del(hs, k), i);
        } else if (op == 'H') {
            printf("%d %d %d\n", i, has(hs, k), i);
        } else {
            int m = hs->m;
            int n = hs->n;
            int l = hs->l;
            printf("%d %d %d %d\n", i, m, n, l);
        }
        i++;
    }
    free_hashset(hs);
    return 0;
}

