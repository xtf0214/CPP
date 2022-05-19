#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[100], s1[100];
    int n = 0;
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++)
        if ('0' <= s[i] && s[i] <= '9')
            s1[n++] = s[i];
    s1[n] = '\0';
    printf("%d", atoi(s1));
    return 0;
}