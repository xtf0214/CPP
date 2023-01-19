/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2023/01/18 23:14
 * @version :   2023/01/18 23:14
 * @link    :   https://ac.nowcoder.com/acm/contest/46810/H
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++)
        cin >> x, mp[x]++;
    multiset<int> st;
    for (auto &[_, x] : mp)
        st.insert(x);
    ll lesum = 0, ge = st.size();
    for (int k = 1; k <= n; k++) {
        // 把st里<=k的数字求和保存到lesum, ge保存>k的数的个数，其贡献为ge*(k-1)
        while (!st.empty() && *st.begin() <= k) {
            lesum += *st.begin();
            st.erase(st.begin());
            ge--;
        }
        cout << lesum + ge * (k - 1) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}