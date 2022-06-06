#include <stdio.h>
#include <string.h>
#define MAX 10000 + 5
int main()
{
    int T;
    char s[MAX];
    while (scanf("%d", &T) != EOF)
        while (T--)
        {
            int cnt = 0;
            scanf("%s", s);
            int l = strlen(s);
            for (int i = 0; i < l; i++)
                if ('0' <= s[i] && s[i] <= '9')
                    cnt++;
            printf("%d\n", cnt);
        }
    return 0;
}