/** 
 * @file    :   1846A
 * @author  :   Tanphoon 
 * @date    :   2023/07/07 22:38
 * @version :   2023/07/07 22:38
 * @link    :   https://codeforces.com/contest/1846/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            cnt++;
    }
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