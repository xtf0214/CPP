// 找鞍点
#include <stdio.h>
int main()
{
    int n;
    int a[10][10] = {0};
    int max_line[10] = {0}, min_row[10] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
    {
        max_line[i] = a[i][0];
        min_row[i] = a[0][i];
        for (int j = 0; j < n; j++)
        {
            if (max_line[i] < a[i][j])
                max_line[i] = a[i][j];
            if (min_row[i] > a[j][i])
                min_row[i] = a[j][i];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (min_row[j] == a[i][j] && max_line[i] == a[i][j])
            {
                printf("%d %d\n", i, j);
                return 0;
            }
    printf("NONE");
    return 0;
}