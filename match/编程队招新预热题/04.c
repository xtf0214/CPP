#include <stdio.h>
int main()
{
    char str[100];
    int cnt = 0;
    scanf("%[^\n]", str);
    for (int i = 0; str[i] != '\0'; i++)
        if ('0' <= str[i] && str[i] <= '9')
            cnt++;
    printf("%d", cnt);
    return 0;
}