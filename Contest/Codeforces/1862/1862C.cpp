/**
 * @file    :   1862C
 * @author  :   Tanphoon
 * @date    :   2023/08/24 23:11
 * @version :   2023/08/24 23:11
 * @link    :   https://codeforces.com/contest/1862/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), d(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x > n) {
            puts("NO");
            return;
        }
        d[0]++;
        d[x]--;
    }
    d.pop_back();
    for (int i = 1; i < d.size(); i++)
        d[i] += d[i - 1];
    bool yes = true;
    for (int i = 0; i < n; i++)
        if (a[i] != d[i])
            yes = false;
    puts(yes ? "YES" : "NO");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}