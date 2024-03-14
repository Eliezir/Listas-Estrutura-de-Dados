
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

void printtreemeudeusfuncionapfvr(treenode *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d ", node->data);
    printtreemeudeusfuncionapfvr(node->left);
    printtreemeudeusfuncionapfvr(node->right);
}

int checkBST(treenode *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->data < min || root->data > max)
    {
        return 0;
    }
    return checkBST(root->left, min, root->data - 1) && checkBST(root->right, root->data + 1, max);
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
    while (input[*i] >= '0' && input[*i] <= '9') {
        num = num * 10 + (input[*i] - '0');
        (*i)++;
    }

    treenode *node = newTree(num, NULL, NULL);
    node->left = constructBinaryTree(input, i);
    node->right = constructBinaryTree(input, i);

    if (input[*i] == ')') {
        (*i)++;
    }

    return node;
}

int main()
{
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    int i = 0;
    treenode *root = constructBinaryTree(input, &i);
    // printtreemeudeusfuncionapfvr(root);
    printf(checkBST(root, -100000, 100000) ? "VERDADEIRO" : "FALSO");
    return 0;
}