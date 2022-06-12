// 7-21大小写字母转换
#include <stdio.h>
int main()
{
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if ('a' <= c && c <= 'z')
            printf("%c\n", c - 'a' + 'A');
        else if ('A' <= c && c <= 'Z')
            printf("%c\n", c - 'A' + 'a');
    }
    return 0;
}