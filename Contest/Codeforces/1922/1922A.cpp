/** 
 * @file    :   1922A
 * @author  :   Tanphoon 
 * @date    :   2024/01/20 20:04
 * @version :   2024/01/20 20:04
 * @link    :   https://codeforces.com/contest/1922/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    string t;
    bool ok = false;
    for (int i = 0; i < n; i++)
        if (a[i] != c[i] && b[i] != c[i])
            ok = true;
    // c[i]一个不匹配，则整个c就不匹配
    // 只有a[i]!=c[i]&&b[i]!=c[i]时才可以找到
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

/* 
aaa
aaa
aab

aaB
 */