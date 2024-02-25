/**
 * @file    :   G
 * @author  :   Tanphoon
 * @date    :   2024/01/23 15:04
 * @version :   2024/01/23 15:04
 * @link    :   https://ac.nowcoder.com/acm/contest/74088/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

template <typename T> T pow(T a, long long b) {
    T s = 1;
    for (; b; a = a * a, b >>= 1)
        if (b & 1)
            s = s * a;
    return s;
}
struct Z {
    long long x;
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

inline void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k + 1), b(k + 1), pr(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i] >> b[i];
        pr[i] = pr[i - 1] + a[i];
    }
    ll x = 1LL << __lg(n - 1);
    int r = lower_bound(pr.begin(), pr.end(), x) - pr.begin();
    Z sum1 = 0, sum2 = 0;
    for (int i = 1; i < r; i++)
        sum1 = sum1 + a[i] * b[i];
    for (int i = r + 1; i <= k; i++)
        sum2 = sum2 + a[i] * b[i];
    if (r <= k) {
        sum1 = sum1 + (a[r] - (pr[r] - x)) * b[r];
        sum2 = sum2 + (pr[r] - x) * b[r];
    }
    cout << sum1 * sum1 + sum2 * sum2 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}