/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2024/05/30 14:56
 * @version :   2024/05/30 14:56
 * @link    :   https://codeforces.com/gym/105170/problem/C
 */
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
struct Z {
    long long x = 0;
    Z(long long x = 0) : x(Norm(x)) {}
    static long long Norm(long long x) { return x %= mod, x < 0 ? x + mod : x; }
    friend Z operator+(const Z &a, const Z &b) { return Z(a.x + b.x); }
    friend Z operator-(const Z &a, const Z &b) { return Z(a.x - b.x); }
    friend Z operator*(const Z &a, const Z &b) { return Z(a.x * b.x); }
    friend ostream &operator<<(ostream &os, const Z &z) { return os << z.x; }
    friend istream &operator>>(istream &os, Z &z) { return os >> z.x, z.x = Norm(z.x), os; }
};
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<Z> fib(2 * n + 2);
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 2 * n + 1; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    Z ans = 0;
    int one = 0;
    for (int i = 0, len = n - 1; i < n; i++, len--) {
        if (s[i] == '1') {
            Z x = 0;
            // Matrix Tpow, T1pow;
            // if (one == 0) {
            //     T1pow = {{1, 0}, {0, 1}};
            // } else {
            //     T1pow = {{fib[one + 1].x, fib[one].x}, {fib[one].x, fib[one - 1].x}};
            // }
            // if (len == 0) {
            //     Tpow = {{1, 0}, {0, 1}};
            // } else {
            //     Tpow = {{fib[2 * len + 1].x, fib[2 * len].x}, {fib[2 * len].x, fib[2 * len - 1].x}};
            // }
            // x = (T1pow * Tpow)[1][0];
            if (one == 0)
                x = fib[2 * len];
            else if (len == 0)
                x = fib[one];
            else
                x = fib[one] * fib[2 * len + 1] + fib[one - 1] * fib[2 * len];
            ans = ans + x;
            one++;
        }
    }
    ans = ans + fib[one];
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}