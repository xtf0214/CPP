#include <stdio.h>
int C[35][35];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for (int i = 0; i <= n; i++)
        printf("%d ", C[n][i]);
    return 0;
}