#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n][205];
    char ans[205];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    int finish = 0;
    for (int i = 0; !finish; i++) {
        finish = 0;
        for (int j = 1; j < n; j++)
            if (i >= strlen(s[j]) || s[j][i] != s[0][i]) {
                finish = 1;
                break;
            }
        if (!finish)
            ans[cnt++] = s[0][i];
    }
    if (cnt == 0)
        printf("Error");
    else
        printf("%s", ans);
    return 0;
}