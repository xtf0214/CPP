#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[100], ch;
    int n = 0;
    gets(s);
    scanf("%c", &ch);
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == ch)
            n++;
    printf("%d", n);
    return 0;
}