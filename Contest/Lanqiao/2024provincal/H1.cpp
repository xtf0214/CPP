/**
 * @file    :   H 11/11 100分
 * @author  :   Tanphoon
 * @date    :   2024/04/13 16:12
 * @version :   2024/04/13 16:12
 * @link    :   https://www.dotcpp.com/oj/train/1118/
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

template <typename T> struct BIT {
    int n;
    vector<T> dat;
    BIT(int n = 0) : n(n), dat(n + 1, 0) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, T x) {
        for (assert(i > 0); i <= n; i += lowbit(i))
            dat[i] += x;
    }
    T get(int i) {
        T res = 0;
        for (i = min(i, n); i; i -= lowbit(i))
            res += dat[i];
        return res;
    }
    T rangeQuery(int l, int r) { return get(r) - get(l - 1); }
};

int main() {
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> mp;
    while (n--) {
        int l, w, c;
        cin >> l >> w >> c;
        mp[l].push_back({w, c});
    }
    for (auto &it : mp)
        sort(it.second.begin(), it.second.end());
    ll ans = 0;
    vector<BIT<int>> bit(3, BIT<int>(1e5 + 1));
    for (auto &it1 : mp) {
        int l1 = it1.first;
        for (auto &it2 : it1.second) {
            int w1 = it2.first, c = it2.second;
            for (int d = 0; d < 3; d++)
                if (d != c) {
                    ans = (ans + bit[d].rangeQuery(w1 + 1, 1e5)) % mod;
                }
            bit[c].add(w1, 1);
        }
    }
    cout << ans << '\n';
}