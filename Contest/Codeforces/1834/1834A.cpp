/**
 * @file    :   Codeforces Round 879 (Div. 2) 1834A
 * @author  :   Tanphoon
 * @date    :   2023/06/18 22:20
 * @version :   2023/06/18 22:20
 * @link    :   https://codeforces.com/contest/1834/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x == 1 ? b++ : a++;
    }
    int ans = 0;
    if (a % 2 == 1)
        ans++, a--, b++;
    while (a > b)
        ans += 2, a -= 2, b += 2;
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}