/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2023/11/19 21:05
 * @version :   2023/11/19 21:05
 * @link    :   https://ac.nowcoder.com/acm/contest/903/B
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

using Matrix = std::vector<std::vector<Z>>;
Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix C(A.size(), vector<Z>(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            for (int j = 0; j < B[0].size(); j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
    return C;
}
Matrix matrixPow(Matrix A, ll n) {
    Matrix B(A.size(), vector<Z>(A[0].size(), 0));
    for (int i = 0; i < B.size(); i++)
        B[i][i] = 1;
    for (; n; n >>= 1, A = A * A)
        if (n & 1)
            B = B * A;
    return B;
}

inline void solve() {
    int n, q;
    cin >> q >> n >> mod;
    Matrix A = {
        {q, 1},
        {0, 1},
    };
    Matrix S = matrixPow(A, n);
    cout << (S[0][0] + S[0][1] - 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}