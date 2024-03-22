/**
 * @file    :   1542A
 * @author  :   Tanphoon
 * @date    :   2023/11/21 22:40
 * @version :   2023/11/21 22:40
 * @link    :   https://codeforces.com/contest/1542/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    n *= 2;
    int cnt[2]{0};
    while (n--) {
        int x;
        cin >> x;
        cnt[x & 1]++;
    }
    puts(cnt[0] == cnt[1] ? "YES" : "NO");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}