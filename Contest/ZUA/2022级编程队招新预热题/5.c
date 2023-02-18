#include <stdio.h>
#include <string.h>
int main() {
    char bin[30];
    int ans = 0;
    scanf("%s", bin);
    for (int i = strlen(bin) - 1, k = 0; i >= 0; i--, k++)
        ans += (int)(bin[i] - '0') << k;
    printf("%d", ans);
    return 0;
}