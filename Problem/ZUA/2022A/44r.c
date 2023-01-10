#include <stdio.h>
int c[10][10];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
            printf(" ");
        for (int j = 0; j <= i; j++)
        {
            c[i][j] = j ? c[i - 1][j] + c[i - 1][j - 1] : 1;
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}