/**
 * @file    :   B1
 * @author  :   Tanphoon
 * @date    :   2023/11/19 22:53
 * @version :   2023/11/19 22:53
 * @link    :   https://ac.nowcoder.com/acm/contest/903/B
 */
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

template <typename T> T pow(T a, int b) {
    T s = 1;
    for (; b; a = a * a, b >>= 1)
        if (b & 1)
            s = s * a;
    return s;
}
struct Z {
    long long x = 0;
    Z() {}
    Z(long long x) : x(Norm(x)) {}
    static long long Norm(long long x) { return x %= mod, x < 0 ? x + mod : x; }
    Z inv() const { return pow(*this, mod - 2); }
    friend Z operator+(const Z &a, const Z &b) { return Z(a.x + b.x); }
    friend Z operator-(const Z &a, const Z &b) { return Z(a.x - b.x); }
    friend Z operator*(const Z &a, const Z &b) { return Z(a.x * b.x); }
    friend Z operator/(const Z &a, const Z &b) { return a * b.inv(); }
    friend ostream &operator<<(ostream &os, const Z &z) { return os << z.x; }
    friend istream &operator>>(istream &is, Z &z) { return cin >> z.x, z.x = Norm(z.x), is; }
};

Z calc(Z q, int n) {
    if (q.x == 0)
        return 0;
    if (n == 0)
        return 0;
    if (n & 1) {
        return (Z(1) + pow(q, n / 2)) * calc(q, n / 2) + pow(q, n);
    } else {
        return (Z(1) + pow(q, n / 2)) * calc(q, n / 2);
    }
}
inline void solve() {
    int n, q;
    cin >> q >> n >> mod;
    cout << calc(q, n) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
