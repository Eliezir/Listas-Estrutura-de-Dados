// Escreva um programa que aceita uma árvore binária, e um inteiro N.
// Seu programa deve ser capaz de dizer se existe um nó cujo inteiro é N bem como em que profundidade ele se encontra.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *newTree(int data, treenode *left, treenode *right)
{
    treenode *newNode = (treenode *)malloc(sizeof(treenode));
    newNode->data = data;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

treenode *constructBinaryTree(char *input, int *i)
{
    if (input[*i] == '\0' || input[*i] == ')')
    {
        (*i)++;
        return NULL;
    }

    if (input[*i] == '(' && input[*i + 1] == ')')
    {
        (*i) += 2;
        return NULL;
    }

    (*i)++;

    int num = 0;
    while (input[*i] >= '0' && input[*i] <= '9')
    {
        num = num * 10 + (input[*i] - '0');
        (*i)++;
    }

    treenode *node = newTree(num, NULL, NULL);
    node->left = constructBinaryTree(input, i);
    node->right = constructBinaryTree(input, i);

    if (input[*i] == ')')
    {
        (*i)++;
    }

    return node;
}


int checkNode(treenode *root, int searchNumber, int depth)
{
    if (root == NULL)
    {
        return -1;
    }
    // printf("root->data: %d & searchNumber = %d\n", root->data, searchNumber);
    if (root->data == searchNumber)
    {
        return depth;
    }
    int left = checkNode(root->left, searchNumber, depth + 1);
    if (left != -1)
    {
        return left;
    }
    return checkNode(root->right, searchNumber, depth + 1);
}

int main()
{
    int searchNumber;
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    scanf("%d", &searchNumber);
    int i = 0;
    treenode *root = constructBinaryTree(input, &i);
    int result = checkNode(root, searchNumber, 0);
    printf(result == -1 ? "NAO ESTA NA ARVORE\n%d" : "ESTA NA ARVORE\n%d", result);
    return 0;
}