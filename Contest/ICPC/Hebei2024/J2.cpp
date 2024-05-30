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
    friend istream &operator>>(istream &os, Z &z) { return os >> z.x, z.x = Norm(z.x), os; }
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
Matrix matPow(Matrix A, ll n) {
    Matrix B(A.size(), vector<Z>(A[0].size()));
    for (int i = 0; i < B.size(); i++)
        B[i][i] = 1;
    for (; n; n >>= 1, A = A * A)
        if (n & 1)
            B = B * A;
    return B;
}
void solve() {
    int m;
    int a[10];
    std::cin >> m;
    for (int i = 0; i < 10; i++) {
        std::cin >> a[i];
    }

    if (m == 1 && a[0] > 0) {
        std::cout << 0 << "\n";
        return;
    }

    Z ans = 0;
    for (int i = 1; i < 10; i++) {
        if (a[i]) {
            a[i]--;
            m--;
            ans = i;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        int t = std::min(m, a[i]);
        m -= t;
        Z pw = pow(Z(10), t);
        ans = ans * pw;
        ans = ans + (pw - 1) / Z(9) * i;
    }
    std::cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
