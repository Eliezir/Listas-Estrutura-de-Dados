#include <stdio.h>

int checkIntersection(int array1[], int array2[], int intersectionArray[])
{
    int k = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (array1[i] == array2[j])
            {
                int checkDuplicate = 0;
                for (int l = 0; l < k; l++)
                {
                    if (array1[i] == intersectionArray[l])
                    {
                        checkDuplicate = 1;
                        break;
                    }
                }
                if (checkDuplicate == 0)
                {
                    intersectionArray[k] = array1[i];
                    k++;
                }
            }
        }
    }
    return k;
}

void sortAndPrintList(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (array[i] > array[j])
            {
                int aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main()
{
    int array1[20], array2[20], intersectionArray[20];
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &array1[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &array2[i]);
    }
    int k = checkIntersection(array1, array2, intersectionArray);
    if (k == 0)
        printf("VAZIO");
    else
    {
        sortAndPrintList(intersectionArray, k);
    }
}