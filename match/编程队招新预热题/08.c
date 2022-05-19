#include <stdio.h>
int main()
{
    int n;
    int a[10][10] = {0};
    int x_max[10] = {0}, y_min[10] = {0};
    scanf("%d", &n);
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            scanf("%d", &a[y][x]);
    for (int y = 0; y < n; y++)
    {
        x_max[y] = a[y][0];
        for (int x = 0; x < n; x++)
            if (a[y][x] > x_max[y])
                x_max[y] = a[y][x];
    }
    for (int x = 0; x < n; x++)
    {
        y_min[x] = a[0][x];
        for (int y = 0; y < n; y++)
            if (a[y][x] < y_min[x])
                y_min[x] = a[y][x];
    }
    int exist = 0;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            if (y_min[x] == a[y][x] && x_max[y] == a[y][x])
                exist = 1, printf("%d %d\n", y, x);
    if (!exist)
        printf("NONE");
    return 0;
}