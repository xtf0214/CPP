/**
 * @file    :   Codeforces Round 872 (Div. 2) 1824B
 * @author  :   Tanphoon
 * @date    :   2023/06/19 16:43
 * @version :   2023/06/19 16:43
 * @link    :   https://codeforces.com/contest/1825/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    vector<int> a(n * m);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int s1 = a[0], s2 = a[1];
    int t1 = a[n * m - 1], t2 = a[n * m - 2];
    ll ans1 = (n - 1) * m * (t1 - s1) + (m - 1) * (t2 - s1); // 最小值填在左上角
    ll ans2 = (n - 1) * m * (t1 - s1) + (m - 1) * (t1 - s2); // 最大值填在左上角
    cout << max(ans1, ans2) << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}