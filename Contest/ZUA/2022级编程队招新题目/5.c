#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, l;
    char s[105], ans[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        gets(s);
        int len = strlen(s);
        if (i == 0 || len >= l) {
            l = len;
            strcpy(ans, s);
        }
    }
    printf("%s", ans);
    return 0;
}