/** 
 * @file    :   L
 * @author  :   Tanphoon 
 * @date    :   2023/07/12 23:50
 * @version :   2023/07/12 23:50
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/L
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

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

int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    vector<int> a(n + 1);
    BIT<int> bit(N);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bit.add(a[i], 1);
    }
    while (m--) {
        int p, x;
        cin >> p >> x;
        bit.add(a[p], -1);
        bit.add(x, 1);
        a[p] = x;
        int l = 0, r = N, mid;
        auto check = [&](int x) { return bit.get(x) < (n + 1) / 2; };
        while (r - l > 1)
            check(mid = (l + r) / 2) ? l = mid : r = mid;
        cout << r << '\n';
    }
    return 0;
}