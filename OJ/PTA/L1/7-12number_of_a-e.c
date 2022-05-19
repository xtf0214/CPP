#include <stdio.h>
int main()
{
    char str[100];
    int cnt[10] = {0};
    scanf("%[^\n]", str);
    for (int i = 0; str[i] != '\0'; i++)
        if ('a' <= str[i] && str[i] <= 'e')
            cnt[str[i] - 'a']++;
    printf("a(%d)b(%d)c(%d)d(%d)e(%d)", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
    return 0;
}