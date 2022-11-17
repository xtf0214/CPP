#include <stdio.h>
#include <string.h>
void star(char s[])
{
    char s1[200];
    int n = 0;
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        s1[n++] = s[i];
        if ('a' <= s[i] && s[i] <= 'z')
            s1[n++] = '*';
    }
    s1[n] = '\0';
    strcpy(s, s1);
}
int main()
{
    char s[100];
    gets(s);
    star(s);
    puts(s);
    return 0;
}