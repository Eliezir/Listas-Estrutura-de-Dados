#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void insert(treenode *root, treenode *newNode)
{
    if (root == NULL)
    {
        root = newNode;
    }
    if (root->left == NULL)
    {
        root->left = newNode;
    }
    else
    {
        root->right = newNode;
    }
}

int printMinMax(treenode *root, int level, int *max, int *min)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = printMinMax(root->left, level - 1, max, min);
    int right = printMinMax(root->right, level - 1, max, min);
    if (level == 1)
    {
        if (root->data > *max)
        {
            *max = root->data;
        }
        if (root->data < *min)
        {
            *min = root->data;
        }
        return 1;
    }
    return left || right;
}

// int printEachLevel(treenode *root, int level)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     if (level == 1)
//     {
//         printf("%d ", root->data);
//     }
//     else if (level > 1)
//     {
//         printEachLevel(root->left, level - 1);
//         printEachLevel(root->right, level - 1);
//     }
// }

int main()
{
    treenode *root = NULL;
    treenode *current = NULL;
    int data, inputs;
    scanf("%d", &inputs);
    treenode *nosBackup[inputs];
    treenode *nos[inputs];
    for (int i = 0; i < inputs; i++)
    {
        nos[i] = NULL;
    }
    for (int i = 0; i < inputs; i++)
    {
        int data, left, right;
        scanf("%d %d %d", &data, &left, &right);
        current = newTree(data, NULL, NULL);
        if (left != -1)
        {
            if (left > i)
                nos[left] = current;
            else
            {
                treenode *aux = nosBackup[left];
                insert(current, aux);
            }
        }
        if (right != -1)
        {
            if (right > i)
                nos[right] = current;
            else
            {
                treenode *aux = nosBackup[right];
                insert(current, aux);
            }
        }
        if (nos[i] != NULL)
        {
            treenode *aux = nos[i];
            insert(aux, current);
        }
        else if (i == 0)
        {
            root = current;
        }
        else
        {
            nosBackup[i] = current;
        }
    }

    int max = -100000;
    int min = 100000;
    int level = 1;
    while (printMinMax(root, level, &max, &min))
    {
        printf("Nivel %d: Maior = %d, Menor = %d\n", level, max, min);
        level++;
        max = -100000;
        min = 100000;
    }
    level = 1;
    return 0;
}
