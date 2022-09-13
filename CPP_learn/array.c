#include <stdio.h>
void print(int *a, int m, int n)
{
    // int(*b)[n] = (int(*)[n])a;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         printf("%d ", b[i][j]);
    //     printf("\n");
    // }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i * n + j]);
        printf("\n");
    }
}
int main()
{
    int a[3][2] = {{1, 2},
                   {3, 4},
                   {5, 6}};
    print(a[0], 3, 2);
}