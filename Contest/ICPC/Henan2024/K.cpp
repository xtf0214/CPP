/** 
 * @file    :   K
 * @author  :   Tanphoon
 * @date    :   2024/06/12 14:11
 * @version :   2024/06/12 14:11
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/K
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = max(ans, a[i] | a[j]);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}