/** 
 * @file    :   J
 * @author  :   Tanphoon 
 * @date    :   2024/05/06 13:24
 * @version :   2024/05/06 13:24
 * @link    :   https://codeforces.com/gym/105139/problem/J
 */
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
template <typename T> T ksm(T a, long long b) {
    T s = 1;
    for (; b; a = a * a, b >>= 1)
        if (b & 1)
            s = s * a;
    return s;
}
struct Z {
    long long x = 0;
    Z(long long x = 0) : x(Norm(x)) {}
    static long long Norm(long long x) { return x %= mod, x < 0 ? x + mod : x; }
    Z inv() const { return ksm(*this, mod - 2); }
    friend Z operator+(const Z &a, const Z &b) { return Z(a.x + b.x); }
    friend Z operator-(const Z &a, const Z &b) { return Z(a.x - b.x); }
    friend Z operator*(const Z &a, const Z &b) { return Z(a.x * b.x); }
    friend Z operator/(const Z &a, const Z &b) { return a * b.inv(); }
    friend ostream &operator<<(ostream &os, const Z &z) { return os << z.x; }
    friend istream &operator>>(istream &os, Z &z) { return os >> z.x, z.x = Norm(z.x), os; }
};

int main() {
    int n;
    cin >> n;
    Z a = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a = a + x;
    }
    a = a / n;
    cout << a << '\n';
}