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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(treenode **root, int data)
{
    if (*root == NULL)
    {
        *root = newTree(data, NULL, NULL);
    }
    else if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}
void printTree(treenode *node)
{
    if (node == NULL)
    {
        printf(" () ");
        return;
    }
    printf(" ( %d ", node->data);
    printTree(node->left);
    printTree(node->right);
    printf(") ");
}

int main()
{
    treenode *root = NULL;
    int data;
    printf("----\n");
    while (scanf("%d", &data) != EOF)
    {
        printf("Adicionando %d\n", data);
        insert(&root, data);
        printf("  ");
        printTree(root);
        printf("\n----\n");
    }
    return 0;
}
