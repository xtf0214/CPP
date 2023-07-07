/** 
 * @file    :   1847B
 * @author  :   Tanphoon 
 * @date    :   2023/07/07 12:53
 * @version :   2023/07/07 12:53
 * @link    :   https://codeforces.com/contest/1847/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0, t = INT_MAX;
    // for (int i = 0; i < n; i++) {
    //     t &= a[i];
    //     if (t == 0) {
    //         cnt++;
    //         t = INT_MAX;
    //     }
    // }
    for (int i = 0, j = 0; i < n;) {
        t = INT32_MAX;
        while (j < n && t != 0)
            t &= a[j], j++;
        if (j < n || t == 0)
            cnt++;
        i = j;
    }
    if (cnt == 0)
        cnt = 1;
    cout << cnt << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}