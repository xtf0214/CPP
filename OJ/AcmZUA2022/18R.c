#include <stdio.h>
#include <string.h>
void delete_char(char s[], char c)
{
    char s1[100], n = 0;
    int l = strlen(s);
    for (int i = 0; i < l; i++)
        if (s[i] != c)
            s1[n++] = s[i];
    s1[n] = '\0';
    strcpy(s, s1);
}
int main()
{
    char s[100];
    char c;
    gets(s);
    c = getchar();
    delete_char(s, c);
    printf("%s", s);
    return 0;
}