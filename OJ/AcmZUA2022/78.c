#include <stdio.h>
#define MAXN 20

void strmcpy(char *t, int m, char *s)
{
    int n, i, p = 0;
    n = strlen(t); //计算字符串t的长度
    for (i = m - 1; i <= n - 1; i++)
    {
        s[p] = t[i];
        p++;
    }
}


int main()
{
    char t[MAXN], s[MAXN];
    int m;

    scanf("%d\n", &m);
    gets(t);
    strmcpy(t, m, s);
    printf("%s\n", s);

    return 0;
}