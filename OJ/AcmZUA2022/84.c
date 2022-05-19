#include <stdio.h>
#include <string.h>
#define MAXS 30

char *search(char *s, char *t)
{
    int l1 = strlen(s), l2 = strlen(t);
    for (int i = 0; i < l1; i++)
        if (s[i] == t[0])
        {
            int find = 1;
            for (int j = 0; j < l2; j++)
                if (i + j >= l1 || s[i + j] != t[j])
                    find = 0;
            if (find)
                return s + i;
        }
    return NULL;
}

int main()
{
    char s[MAXS], t[MAXS], *pos;

    gets(s);
    gets(t);
    pos = search(s, t);
    if (pos != NULL)
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */