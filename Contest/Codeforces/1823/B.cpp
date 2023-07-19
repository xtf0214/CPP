/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2023/07/20 00:09
 * @version :   2023/07/20 00:09
 * @link    :   https://codeforces.com/contest/1823/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if (x % k != i % k)
            cnt++;
    }
    if (cnt == 0)
        cout << 0 << '\n';
    else if (cnt == 2)
        cout << 1 << '\n';
    else 
        cout << -1 << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}