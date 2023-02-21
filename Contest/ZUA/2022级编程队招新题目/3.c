#include <stdio.h>

int main() {
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    int a[n][n], b[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[(i + l) % n][(j + k) % n] = a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", b[i][j]);
        printf("\n");
    }
    return 0;
}
