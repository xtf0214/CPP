/** 
 * @file    :   C
 * @author  :   Tanphoon 
 * @date    :   2024/03/22 00:01
 * @version :   2024/03/22 00:01
 * @link    :   https://codeforces.com/contest/1945/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + (s[i] == '0');
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
        int l0 = a[i];
        int r1 = (n - i) - (a[n] - a[i]);
        int ls = i, rs = n - i;
        if (l0 >= (ls + 1)/ 2 && r1 >= (rs + 1) / 2) {
            ans.push_back(i);
        }
    }
    int res = ans[0];
    for (int x : ans) {
        if (abs(n / 2.0 - res) > abs(n / 2.0 - x))
            res = x;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}