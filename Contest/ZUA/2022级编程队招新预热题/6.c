#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[n][n], ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        ans += a[i][i] + a[i][n - 1 - i];
    if (n % 2 == 0)
        printf("%d", ans);
    else
        printf("%d", ans - a[n / 2][n / 2]);
    return 0;
}