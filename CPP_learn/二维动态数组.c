#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m = 4, n = 5;
    int **A = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        A[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            A[i][j] = i + j, printf("%d ", A[i][j]);
        printf("\n");
    }
}