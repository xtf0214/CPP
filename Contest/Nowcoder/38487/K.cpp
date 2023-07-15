/**
 * @file    :   K 试稥
 * @author  :   Tanphoon
 * @date    :   2023/06/19 11:26
 * @version :   2023/06/19 11:26
 * @link    :   https://ac.nowcoder.com/acm/contest/38487/K
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define lowbit(x) (x & -x)
const int N = 1e2 + 5;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    bool a[N]{0};
    int id[N]{0};
    for (int i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        t = __lg(t);
        a[t] = 1;
        id[t] = i;
    }
    vector<int> ans;
    for (int i; x; x -= lowbit(x)) {
        i = __lg(lowbit(x));
        if (!a[i]) {
            cout << -1 << '\n';
            return;
        }
        ans.push_back(id[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}
int main() {
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}