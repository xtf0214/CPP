// 7-8 查找字符串
#include <stdio.h>
int main()
{
    int n, index;
    char str[80];
    char ch;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        index = -1;
        scanf(" %c", &ch);
        scanf(" %[^\n]", str);
        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] == ch)
                index = i;
        if (index == -1)
            printf("Not Found\n");
        else
            printf("index = %d\n", index + 1);
    }
    return 0;
}