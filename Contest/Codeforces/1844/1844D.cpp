/**
 * @file    :   1844D
 * @author  :   Tanphoon
 * @date    :   2023/07/12 01:07
 * @version :   2023/07/12 01:07
 * @link    :   https://codeforces.com/contest/1844/problem/D
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans;
    for (int i = 2; i <= n; i++)
        if (n % i != 0) {
            ans = i;
            break;
        }
    string s;
    for (int i = 0, j = 0; i < n; i++, j = (j + 1) % ans) {
        s.push_back('a' + j);
    }
    cout << s << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}