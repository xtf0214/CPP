/**
 * @file    :   P1063
 * @author  :   Tanphoon
 * @date    :   2023/09/26 08:33
 * @version :   2023/09/26 08:33
 * @link    :   https://www.luogu.com.cn/problem/P1063
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    vector f(2 * n + 1, vector<ll>(2 * n + 1, -1));
    for (int i = 1; i <= 2 * n; i++)
        f[i][i] = 0;
    for (int L = 2; L <= n; L++)
        for (int i = 1, j = i + L - 1; j <= 2 * n; i++, j++)
            for (int k = i; k < j; k++)
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i][i + n - 1]);
    cout << ans << '\n';
}