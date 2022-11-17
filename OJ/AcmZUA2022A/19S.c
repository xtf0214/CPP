#include <stdio.h>
#include <string.h>
void invert(char s[])
{
    char s1[100], n = 0;
    int l = strlen(s);
    for (int i = l - 1; i >= 0; i--)
        s1[n++] = s[i];
    s1[n] = '\0';
    strcpy(s, s1);
}
int main()
{
    char s[100];
    scanf("%s", &s);
    invert(s);
    printf("%s", s);
    return 0;
}