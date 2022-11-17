#include <stdio.h>
#include <math.h>
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 101; i <= n; i++)
    {
        int a = i % 10, b = i / 10 % 10, c = i / 100 % 10;
        if (a == b || a == c || b == c)
            if (sqrt(i) == (int)sqrt(i))
                cnt++;
    }
    printf("count=%d", cnt);
    return 0;
}