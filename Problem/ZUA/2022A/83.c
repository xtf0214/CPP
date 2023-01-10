#include <stdio.h>
#include<string.h>
#define MAXS 10

char *match(char *s, char ch1, char ch2)
{
    int l = strlen(s);
    for (int i = 0; i < l; i++)
        if (s[i] == ch1)
        {
            for (int j = 0; j + i < l; j++)
            {
                printf("%c", s[i + j]);
                if (s[i + j] == ch2)
                    break;
            }
            printf("\n");
            return s + i;
        }
    return s + l;
}
// 私认为以下注释函数才是正确答案，找不到ch2不能直接输出
// char *match(char *s, char ch1, char ch2)
// {
//     int size = strlen(s);
//     int l = -1, r = -1;
//     for (l = 0; l < size && s[l] != ch1; l++)
//         ;
//     for (r = l; r < size && s[r] != ch2; r++)
//         ;
//     if (l != size && r != size)
//     {
//         for (int i = l; i <= r; i++)
//             printf("%c", s[i]);
//         printf("\n");
//         return s + l;
//     }
//     return s + size;
// }
int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}