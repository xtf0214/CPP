/** 
 * @file    :   P3807 【模板】卢卡斯定理/Lucas 定理
 * @author  :   Tanphoon 
 * @date    :   2024/05/13 22:52
 * @version :   2024/05/13 22:52
 * @link    :   https://www.luogu.com.cn/problem/P3807
 */
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
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
    friend istream &operator>>(istream &os, Z &z) { return os >> z.x, z.x = Norm(z.x), os; }
};
struct Binom {
    vector<Z> fac;
    Binom(int n = 0) : fac(n + 1) {
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i;
    }
    Z C(int m, int n) { return (m < n || n < 0) ? 0 : fac[m] / fac[n] / fac[m - n]; }
    Z P(int m, int n) { return (m < n || n < 0) ? 0 : fac[m] / fac[m - n]; }
} binom;
Z lucas(int n, int m, int p) {
    if (n < p && m < p)
        return binom.C(n, m);
    return binom.C(n % p, m % p) * lucas(n / p, m / p, p);
}
inline void solve() {
    int n, m;
    cin >> n >> m >> mod;
    binom = Binom(mod);
    cout << lucas(n + m, n, mod) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}