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

using ll = long long;
using Matrix = vector<vector<ll>>;
Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix C(A.size(), vector<ll>(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            for (int j = 0; j < B[0].size(); j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
    return C;
}
Matrix MatPow(Matrix A, ll b) {
    Matrix B(A.size(), vector<ll>(A[0].size()));
    for (int i = 0; i < B.size(); i++)
        B[i][i] = 1;
    for (; b; b >>= 1, A = A * A)
        if (b & 1)
            B = B * A;
    return B;
}
Matrix T0 = {{1, 0}, {0, 1}};
Matrix T1 = {{1, 1}, {1, 0}};
Matrix T = {{2, 1}, {1, 1}};

struct Brute {
    vector<int> fib;
    Brute() : fib(47) {
        fib[1] = fib[2] = 1;
        for (int i = 3; i < 47; i++)
            fib[i] = fib[i - 1] + fib[i - 2];
    }
    int f(int x) { return fib[x]; }
    int g(int x) { return __builtin_popcount(x); }
    int calc(int a, int b) {
        int res = 0;
        for (int i = a; i < b; i++)
            res += f(g(i));
        return res;
    }
};
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<Matrix> Tpow(n + 1), T1pow(n + 1);
    Tpow[0] = T1pow[0] = {{1, 0}, {0, 1}};
    Tpow[1] = T, T1pow[1] = T1;
    for (int i = 2; i <= n; i++) {
        Tpow[i] = T * Tpow[i - 1];
        T1pow[i] = T1 * T1pow[i - 1];
    }
    Z ans = 0;
    int one = 0;
    for (int i = 0, len = n - 1; i < n; i++, len--) {
        if (s[i] == '1') {
            ll x = (T1pow[one] * Tpow[len])[1][0];
            ans = ans + x;
            one++;
        }
    }
    ans = ans + T1pow[one][1][0];
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    // Brute brute;
    // for (int i = 1; i <= 63; i++) {
    //     debug(i, brute.f(brute.g(i)), MatPow(T1, brute.g(i))[1][0]);
    // }
    // debug(brute.calc(0b10000, 0b10100), (MatPow(T1, 1) * MatPow(T, 2))[1][0]);
    // debug(brute.calc(0b10100, 0b10110), (MatPow(T1, 2) * MatPow(T, 1))[1][0]);
    // for (int i = 1; i <= 6; i++) {
    //     int x = (1 << i) - 1;
    //     debug(x, brute.calc(1, x + 1), MatPow(T, i)[1][0]);
    // }
    return 0;
}