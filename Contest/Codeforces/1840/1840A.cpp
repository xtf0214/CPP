/**
 * @file    :   Codeforces Round 878 (Div. 3) 1840A
 * @author  :   Tanphoon
 * @date    :   2023/06/06 22:45
 * @version :   2023/06/06 22:45
 * @link    :   https://codeforces.com/contest/1840/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #include <DEBUG.h>
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int read(int x = 0) { return cin >> x, x; }

void solve() {
    int n;
    cin >> n;
    string s, res;
    cin >> s;
    char l, r;
    l = s[0];
    for (int i = 1; i < n; i++)
        if (s[i] == l) {
            // cerr << dbg(l) << endl;
            res += l;
            l = s[i + 1];
            i++;
        }
    cout << res << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}