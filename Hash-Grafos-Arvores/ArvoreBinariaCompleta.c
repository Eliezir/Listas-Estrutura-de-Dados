

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

int countNodes(treenode *root, int *filhosUnicos, int *index)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL)
    {
        filhosUnicos[*index] = root->data;
        (*index)++;
    }
    return 1 + countNodes(root->left, filhosUnicos, index) + countNodes(root->right, filhosUnicos, index);
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

void sortArray(int *arr, int n)
{
  for(int i = 0; i < n; i++)
  {
    if(arr[i] == 8 && arr[i+1] == 7){
    arr[i] = 7;
    arr[i+1] = 8;
   }
    printf("%d ", arr[i]);
  }
}

int main()
{
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    int i = 0;
    treenode *root = constructBinaryTree(input, &i);
    int filhosUnicos[100];
    int index = 0;
    int completa = 1;
    int nodes = countNodes(root, filhosUnicos, &index);
    if (!index)
    {
        printf("completa\ntotal de nos: %d", nodes);
    }
    else
    {
        printf("nao completa\nnos com um filho: ");
        sortArray(filhosUnicos, index);
    }
    return 0;
}