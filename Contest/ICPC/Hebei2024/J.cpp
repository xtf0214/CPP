/** 
 * @file    :   J
 * @author  :   Tanphoon 
 * @date    :   2024/05/28 23:04
 * @version :   2024/05/28 23:04
 * @link    :   https://codeforces.com/gym/105184/problem/J
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
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
ll ksm(ll a, ll b) {
    ll s = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            s = s * a % mod;
    return s;
}

void solve() {
    int m;
    cin >> m;
    vector<int> a(10), b(11);
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    if (m == 1 && a[0] > 0) {
        cout << 0 << '\n';
        return;
    }
    int x = 0;
    for (int i = 1; i < 10; i++)
        if (a[i] > 0) {
            x = i;
            a[x]--;
            m--;
            break;
        }
    if (x == 0) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (m >= a[i]) {
            m -= a[i];
        } else {
            a[i] = m, m = 0;
        }
    }
    for (int i = 9; i >= 0; i--)
        b[i] = b[i + 1] + a[i];
    ll ans = x * ksm(10, b[0]) % mod;
    for (int i = 0; i < 10; i++)
        if (a[i] > 0) {
            Matrix A = {{10, 1}, {0, 1}};
            A = MatPow(A, a[i] - 1);
            Matrix S = A * Matrix{{i}, {i}};
            ans = (ans + S[0][0] * ksm(10, b[i + 1] % mod) % mod) % mod;
        }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
