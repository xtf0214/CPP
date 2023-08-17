/**
 * @file    :   L
 * @author  :   Tanphoon
 * @date    :   2023/08/16 21:45
 * @version :   2023/08/16 21:45
 * @link    :   https://ac.nowcoder.com/acm/contest/63602/L
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> struct BIT {
    int size;
    vector<T> dat;
    BIT(int n = 0) : size(n), dat(n + 1, 0) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, T x) {
        for (; i <= size; i += lowbit(i))
            dat[i] += x;
    }
    T get(int i) {
        T res = 0;
        for (; i; i -= lowbit(i))
            res += dat[i];
        return res;
    }
    T query(int l, int r) { return get(r) - get(l - 1); }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<ll> s(n + 1);
    vector<ll> d;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
        d.push_back(s[i]);
        d.push_back(s[i] - x);
    }
    // s[r] - s[l - 1] >= x
    // s[r] - x >= s[l - 1]
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    auto find = [&d](ll x) { return lower_bound(d.begin(), d.end(), x) - d.begin() + 1; };
    BIT<int> f(d.size());
    f.add(find(s[0]), 1);
    ll ans = 0;
    for (int r = 1; r <= n; r++) {
        ans += f.get(find(s[r] - x));
        f.add(find(s[r]), 1);
    }
    cout << ans;
}
