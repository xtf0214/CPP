#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, m, a[1002], f[1002][1002];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = 1; i <= n; i++) {
        f[i][a[i]] = 1;
        for (int j = 0; j < m; j++) {
            f[i][j] |= f[i - 1][j];
            f[i][(j + a[i]) % m] |= f[i - 1][j];
        }
    }
    if (f[n][0])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}