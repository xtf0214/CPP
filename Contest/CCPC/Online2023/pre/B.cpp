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
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int cur = l - 1, cnt = 0;
        while (cur <= r) {
            int next = 0;
            for (int j = 0; j < m; j++)
                next = max(next, nxt[cur + 1][j]);
            cur = next;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}