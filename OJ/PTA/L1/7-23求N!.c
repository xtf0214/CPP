#include <stdio.h>
int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int s = 1;
        for (int i = 1; i <= n; i++)
            s *= i;
        printf("%d\n", s);
    }
    return 0;
}