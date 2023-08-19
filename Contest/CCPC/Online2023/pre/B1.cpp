/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2023/08/19 18:29
 * @version :   2023/08/19 18:29
 * @link    :   https://codeforces.com/gym/103389/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    string s;
    cin >> s;
    vector nxt(n + 1, vector<int>(m));
    nxt[n].assign(m, n);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }
    int logn = __lg(n);
    vector f(n + 1, vector<int>(logn + 1));
    for (int i = 0; i <= n; i++)
        f[i][0] = *max_element(nxt[i].begin(), nxt[i].end());
    for (int t = 1; t <= logn; t++)
        for (int i = 0; i <= n; i++) {
            f[i][t] = f[min(f[i][t - 1] + 1, n)][t - 1];
        }
    // cout << f;
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int cur = l, cnt = 0;
        for (int t = logn; t >= 0; t--)
            if (f[cur][t] <= r) {
                cur = f[cur][t] + 1;
                cnt += 1 << t;
            }
        cout << cnt + 1 << '\n';
    }
    return 0;
}