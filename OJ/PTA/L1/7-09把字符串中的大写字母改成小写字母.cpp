#include <stdio.h>
int main()
{
    char str[100];
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    printf("%s", str);
    return 0;
}