/**
 * @file    :   1856C1
 * @author  :   Tanphoon
 * @date    :   2023/08/08 23:53
 * @version :   2023/08/08 23:53
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll l = -1, r = *max_element(a.begin(), a.end()) + k + 1, mid;
    auto check = [&](ll x) -> bool {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            ll s = 0;
            for (int j = i; j < n; j++) {
                ll mn = max(x - (j - i), 0LL);
                if (mn <= a[j])
                    break; // 当前物品满足之后，就不需要再修改后面的物品了
                if (j == n - 1) {
                    s = k + 1; // 第n个物品不满足，那么前面的都没办法修改
                    break;
                }
                s += mn - a[j];
            }
            if (s <= k)
                ok = true;
        }
        return ok;
    };
    while (r - l > 1)
        check(mid = (l + r) / 2) ? l = mid : r = mid;
    cout << l << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}