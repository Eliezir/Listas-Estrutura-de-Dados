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


treenode *constructBinaryTree(char *input, int *i) {
    if (input[*i] == '\0' || input[*i] == ')') {
        (*i)++;
        return NULL;
    }

    if (input[*i] == '(' && input[*i + 1] == ')') {
        (*i) += 2;
        return NULL;
    }

    (*i)++;

    int num = 0;
    int sign = 1;
    if (input[*i] == '-') {
        sign = -1;
        (*i)++;
    }
    while (input[*i] >= '0' && input[*i] <= '9') {
        num = num * 10 + (input[*i] - '0');
        (*i)++;
    }
    num *= sign;

    treenode *node = newTree(num, NULL, NULL);
    node->left = constructBinaryTree(input, i);
    node->right = constructBinaryTree(input, i);

    if (input[*i] == ')') {
        (*i)++;
    }

    return node;
}

int insertNode(treenode *matriz, treenode *newTree)
{
    if (matriz == NULL || newTree == NULL)
    {
        return -1 ;
    }
    if (matriz->data == newTree->data)
    {
        matriz->left = newTree->left;
        matriz->right = newTree->right;
        return 1;
    }
    int left = insertNode(matriz->left, newTree);
    if (left != -1)
    {
        return left;
    }
    return insertNode(matriz->right, newTree);
}

void printTree(treenode *node)
{
    if (node == NULL)
    {
        printf("()");
        return;
    }
    printf("(%d", node->data);
    printTree(node->left);
    printTree(node->right);
    printf(")");
}

int main()
{
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    int i = 0;
    treenode *root = constructBinaryTree(input, &i);
    while (fgets(input, sizeof(input), stdin))
    {
        input[strcspn(input, "\n")] = 0;
        i = 0;
        treenode *newTree = constructBinaryTree(input, &i);
        insertNode(root, newTree);
    }
    printTree(root);
    return 0;
}