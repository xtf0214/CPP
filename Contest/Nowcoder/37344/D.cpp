/**
 * @file    :   D 数对
 * @author  :   Tanphoon
 * @date    :   2023/05/18 01:59
 * @version :   2023/05/18 01:59
 * @link    :   https://ac.nowcoder.com/acm/contest/37344/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

template <typename T> struct BIT {
    int size;
    vector<T> dat, arr;
    BIT(int n = 0) : size(n), dat(n + 1), arr(n + 1) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, T x) {
        for (arr[i] += x; i <= size; i += lowbit(i))
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> b(n + 1);
    vector<ll> prb(n + 1), d(1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] -= y;
        prb[i] = prb[i - 1] + b[i];
        d.push_back(prb[i]);
        d.push_back(prb[i] - x);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    auto get = [&d](int x) { return lower_bound(d.begin(), d.end(), x) - d.begin() + 1; };
    BIT<int> bit(d.size());
    bit.add(get(prb[0]), 1);
    ll ans = 0; 
    // rep(r, 1, n)每次查询满足 prb[r] - x <= prb[l - 1] 的 l 的个数
    for (int r = 1; r <= n; r++) {
        ans += bit.query(get(prb[r] - x), d.size());
        bit.add(get(prb[r]), 1);
    }
    cout << ans << endl;
    return 0;
}