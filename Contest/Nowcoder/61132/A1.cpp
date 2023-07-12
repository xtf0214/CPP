/**
 * @file    :   A2
 * @author  :   Tanphoon
 * @date    :   2023/07/12 23:50
 * @version :   2023/07/12 23:50
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

struct Z {
    long long x;
    Z(long long x = 0) : x(Norm(x)) {}
    static long long Norm(long long x) { return x %= mod, x < 0 ? x + mod : x; }
    Z pow(Z a, long long b) const {
        Z s = 1;
        for (; b; a = a * a, b >>= 1)
            if (b & 1)
                s = s * a;
        return s;
    }
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
    Z k;
    cin >> k;
    cout << (k * (k + 1) * (2 * k + 1) / 12) + (k * (k + 1) / 4);
    return 0;
}
