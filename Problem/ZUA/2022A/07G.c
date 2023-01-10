#include <stdio.h>
int find(int a[], int n, int q)
{
    int find = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == q)
        {
            find = i;
            break;
        }
    return find;
}
int main()
{
    int j, num[5];
    int x, ret;
    for (j = 0; j < 5; j++)
        scanf("%d", &num[j]);
    scanf("%d", &x);
    ret = find(num, 5, x);
    printf("%d", ret);
    return 0;
}