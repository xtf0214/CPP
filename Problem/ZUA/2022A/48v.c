#include <stdio.h>
int main()
{
    int x, m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x);
            s += x;
        }
        printf("%d\n",s);
    }
    return 0;
}