#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int f[N][N];

int solve(int n, int m) {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6 * n; j++)
            for (int k = 1; k <= 6; k++)
                if (j >= k)
                    f[i][j] += f[i - 1][j - k];
    return f[n][m];
}
int main() {
    int n, m, k;
    cin >> k;
    while (k--) {
        cin >> m >> n;
        int ans = solve(m, n);
        printf("%.2lf\n", ans / pow(6, m));
    }
    return 0;
}