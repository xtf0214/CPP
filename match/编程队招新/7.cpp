#include <stdio.h>
int count(int x)
{
    int s = 0;
    while (x)
        s += x % 10, x /= 10;
    return s;
}
int main()
{
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        int bf = count(x);
        bool same = true;
        for (int i = 2; i <= 9; i++)
            if (count(x * i) != bf)
            {
                same = false;
                break;
            }
        if (!same)
            printf("NO\n");
        else
            printf("%d\n", bf);
    }
    return 0;
}