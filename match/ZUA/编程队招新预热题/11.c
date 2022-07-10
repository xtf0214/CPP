#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int ans = 1;
        char c;
        for (int i = 0; i < n; i++)
        {
            scanf(" %c", &c);
            if (c == 'y')
                ans = ans * 2 - 1;
            else if (c == 'n')
                ans = ans * 2;
        }
        printf("%d\n",ans);
    }
    return 0;
}