// 7-22鸡兔同笼
#include <stdio.h>
int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if (n % 2 == 0)
            printf("%d %d\n", n / 4 + n % 4 / 2, n / 2);
        else
            printf("0 0\n");
    }
    return 0;
}