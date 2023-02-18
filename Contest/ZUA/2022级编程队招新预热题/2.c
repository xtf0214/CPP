#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    int cnt[128] = {0};
    scanf("%s", s);
    for (int i = 0, len = strlen(s); i < len; i++)
        cnt[s[i]]++;
    printf("z:%d\n", cnt['z'] + cnt['Z']);
    printf("u:%d\n", cnt['u'] + cnt['U']);
    printf("a:%d", cnt['a'] + cnt['A']);
    return 0;
}