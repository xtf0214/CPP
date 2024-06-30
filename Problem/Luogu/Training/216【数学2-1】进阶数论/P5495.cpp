/**
 * @file    :   【模板】Dirichlet 前缀和
 * @author  :   Tanphoon
 * @date    :   2024/06/30 16:23
 * @version :   2024/06/30 16:23
 * @link    :   https://www.luogu.com.cn/problem/P5495
 */
#include <bits/stdc++.h>
using namespace std;

uint32_t seed;
inline uint32_t getnext() {
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}

inline void solve() {
    int n;
    cin >> n >> seed;
    vector<uint32_t> a(n + 1), b(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = getnext();
        b[i] = a[i];
    }
    uint32_t ans = 0;
    for (int i = 2; i <= n; i++) {
        if (!c[i])
            for (int j = 1; i * j <= n; j++)
                b[i * j] += b[j], c[i * j] = 1;
    }
    for (int i = 1; i <= n; i++)
        ans ^= b[i];
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}