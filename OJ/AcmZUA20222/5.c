#include <stdio.h>
#define MAX 10000 + 5
int main()
{
    int a, b, c;
    for (int i = 1; scanf("%d %d %d", &a, &b, &c) != EOF; i++)
    {
        int ans = 0;
        for (int s = 10; s <= 100; s++)
            if (s % 3 == a && s % 5 == b && s % 7 == c)
            {
                ans = s;
                break;
            }
        if (ans)
            printf("Case %d: %d\n", i, ans);
        else
            printf("Case %d: No answer\n", i);
    }

    return 0;
}