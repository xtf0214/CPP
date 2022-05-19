#include <stdio.h>
int main()
{
    int n, A[10][10] = {0};
    scanf("%d", &n);
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            scanf("%d", &A[y][x]);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            printf("%4d", A[y][x]);
        printf("\n");
    }
    return 0;
}