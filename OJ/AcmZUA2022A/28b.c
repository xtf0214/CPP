#include <stdio.h>
int main()
{
    int cnt[1005] = {0};
    int x, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 0; i < 1000; i++)
        if (cnt[i])
            printf("%d ", i);
    return 0;
}