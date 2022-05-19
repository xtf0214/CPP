#include <stdio.h>
int main()
{
    int n, s = 150;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int j = 50 - 4 * i;
        if (j >= 0)
            printf("%d %d %d\n", i, j, 100 - i - j);
        else
            break;
    }
    return 0;
}
