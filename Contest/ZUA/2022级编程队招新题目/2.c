#include <stdio.h>

int main() {
    char s[105];
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++)
        if ('a' <= s[i] && s[i] <= 'z')
            s[i] += -'a' + 'A';
        else if ('A' <= s[i] && s[i] <= 'Z')
            s[i] += -'A' + 'a';
    printf("%s", s);
    return 0;
}