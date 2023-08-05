/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/07/18 20:18
 * @version :   2023/07/18 20:18
 * @link    :   https://ac.nowcoder.com/acm/contest/38718/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod;
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
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n;
    mod = n;
    Z x, m;
    cin >> m >> k >> x;
    cout << (x + m * pow(Z(10), k)) << endl;
    return 0;
}