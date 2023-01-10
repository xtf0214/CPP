// 7-18逆序对
#include <stdio.h>
int main()
{
    int a[1005], n, cnt = 0, T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        cnt = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        for (int i = 1; i < n; i++)
            for (int j = n - 1; j >= i; j--)
                if (a[j] < a[j - 1])
                {
                    cnt++;
                    int t = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = t;
                }
        printf("%d\n", cnt);
    }
    return 0;
}