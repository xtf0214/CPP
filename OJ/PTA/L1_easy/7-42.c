#include <stdio.h>
int main()
{
    int n, a[105], used[105] = {0}, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if (a[i] + a[j] == a[k] && !used[k])
                {
                    cnt++;
                    used[k] = 1;
                }
            }
    printf("%d", cnt);
    return 0;
}