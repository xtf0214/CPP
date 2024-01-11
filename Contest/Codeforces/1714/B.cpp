/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2024/01/11 21:34
 * @version :   2024/01/11 21:34
 * @link    :   https://codeforces.com/contest/1714/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pos = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (b[a[i]] == 0) {
            b[a[i]] = 1;
        } else {
            pos = i;
            break;
        }
    }
    cout << pos + 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}