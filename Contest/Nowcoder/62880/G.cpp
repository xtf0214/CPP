/**
 * @file    :   G
 * @author  :   Tanphoon
 * @date    :   2023/08/02 15:06
 * @version :   2023/08/02 15:06
 * @link    :   https://ac.nowcoder.com/acm/contest/62880/G
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, mod = 1e9 + 7;

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
    static long Norm(long long x) { return x %= mod, x < 0 ? x + mod : x; }
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
    Z C(int m, int n) { return (m < n || n < 0) ? 0 : fac[m] * ifac[n] * ifac[m - n]; }
    Z P(int m, int n) { return (m < n || n < 0) ? 0 : fac[m] * ifac[m - n]; }
} math(N);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        if (mp.count(x)) {
            idx1 = mp[x];
            idx2 = i;
        } else
            mp[x] = i;
    }
    if (idx2 == -1) {
        cout << math.C(n, k) << '\n';
    } else {
        cout << math.C(n, k) - math.C(n - (idx2 - idx1 + 1), k - 1) << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}