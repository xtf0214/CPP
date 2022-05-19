#include <stdio.h>
#include <string.h>

#define MAXS 10

char *str_cat(char *s, char *t);

int main()
{
    char *p;
    char str1[MAXS + MAXS] = {'\0'}, str2[MAXS] = {'\0'};

    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);

    return 0;
}

char *str_cat(char *s, char *t)
{
    int l1 = strlen(s), l2 = strlen(t);
    for (int i = 0; i < l2; i++)
        s[l1 + i] = t[i];
    s[l1 + l2] = '\0';
    return s;
}
