/**
 * @file    :   1867B
 * @author  :   Tanphoon
 * @date    :   2023/09/12 01:22
 * @version :   2023/09/12 01:22
 * @link    :   https://codeforces.com/contest/1867/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> t(n + 1);
    int m = n / 2 - 1;
    int cnt = 0, cnt1 = 0;
    for (int i = m; i >= 0; i--) {
        if (s[i] != s[n - 1 - i])
            cnt++;
        else
            cnt1++;
    }
    if (n & 1) {
        for (int i = 0; i <= cnt1; i++)
            t[cnt + i * 2] = 1, t[cnt + i * 2 + 1] = 1;
    } else {
        for (int i = 0; i <= cnt1; i++)
            t[cnt + i * 2] = 1;
    }
    for (int i = 0; i <= n; i++)
        cout << t[i];
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}