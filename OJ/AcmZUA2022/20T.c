#include <stdio.h>
#include <string.h>
int space = 0, number = 0, word = 0;
void count(char s[])
{

    int l = strlen(s);
    for (int i = 0; i < l; i++)
        if ('A' <= s[i] && s[i] <= 'Z' || 'a' <= s[i] && s[i] <= 'z')
            word++;
        else if ('0' <= s[i] && s[i] <= '9')
            number++;
        else if (s[i] == ' ')
            space++;
}
int main()
{
    char s[100];
    gets(s);
    count(s);
    printf("%d %d %d", space, number, word);
    return 0;
}