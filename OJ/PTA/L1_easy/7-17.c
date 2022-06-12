// 7-17求斐波那契数的尾数
#include <stdio.h>
int main()
{
    int n, a = 1, b = 1;
    scanf("%d", &n);
    if (n < 3)
    {
        printf("1");
        return 0;
    }
    for (int i = 3; i <= n; i++)
    {
        b = a + b;
        a = b - a;
        b %= 10;
        a %= 10;
    }
    printf("%d", b);
    return 0;
}
// 考虑溢出
