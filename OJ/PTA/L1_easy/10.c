// 7-10 删除字符串中下标为偶数的字符
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    scanf("%s", str);
    for (int i = 1; i < strlen(str); i += 2)
        printf("%c", str[i]);
    return 0;
}