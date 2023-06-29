/** 
 * @file    :   1845C
 * @author  :   Tanphoon 
 * @date    :   2023/06/30 01:25
 * @version :   2023/06/30 01:25
 * @link    :   https://codeforces.com/contest/1845/problem/C
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    string a, b, s;
    cin >> s >> m >> a >> b;
    n = s.size();
    vector<array<int, 10>> nxt(n + 1);
    nxt[n].fill(n);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - '0'] = i;
    }
    int cur = -1;
    for (int i = 0; i < m && cur < n; i++) {
        int next = 0;
        for (int j = a[i] - '0'; j <= b[i] - '0'; j++) {
            next = max(next, nxt[cur + 1][j]);
        }
        cur = next;
    }
    puts(cur == n ? "YES" : "NO");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}