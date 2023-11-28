/**
 * @file    :   I
 * @author  :   Tanphoon
 * @date    :   2023/11/26 02:24
 * @version :   2023/11/26 02:24
 * @link    :   https://codeforces.com/gym/104095/problem/I
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e6 + 5, mod = 1e9 + 7;

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
struct Binom {
    vector<Z> fac, ifac;
    Binom(int n) : fac(n + 1), ifac(n + 1) {
        fac[0] = ifac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i;
        ifac[n] = 1 / fac[n];
        for (int i = n - 1; i >= 1; i--)
            ifac[i] = (i + 1) * ifac[i + 1];
    }
    Z C(int n, int m) { return (n < m || n < 0) ? 0 : fac[n] * ifac[m] * ifac[n - m]; }
    Z P(int n, int m) { return (n < m || n < 0) ? 0 : fac[n] * ifac[n - m]; }
} math(N);

inline void solve() {
    ll n, R1, R2, r, a, h;
    cin >> n >> R1 >> R2 >> r >> a >> h;
    if (R1 + r >= R2) {
        if (a * n < h)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
        return;
    }
    Z p = Z(R1 + r) * Z(R1 + r) / Z(R2 * R2);
    Z sp = 1 - p;
    Z ans = 0;
    int c = (h - 1) / a + 1; // ceil(h/a)
    for (int i = c; i <= n; i++)
        ans = ans + math.C(n, i) * pow(p, i) * pow(sp, n - i);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}