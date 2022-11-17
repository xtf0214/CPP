#include <stdio.h>
void solve()
{
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x);
            if (i > 0 && j < i && x != 0)
            {
                printf("NO\n");
                return;
            }
        }
    printf("YES\n");
}
int main()
{
    int T, n;
    int a[10][10];
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}