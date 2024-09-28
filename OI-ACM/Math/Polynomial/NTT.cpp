/**
 * @file    :   P3803 【模板】多项式乘法（FFT）
 * @author  :   Tanphoon
 * @date    :   2023/09/03 02:45
 * @version :   2023/09/03 02:45
 * @link    :   https://www.luogu.com.cn/problem/P3803
 */
#include <bits/stdc++.h>
using namespace std;

using Poly = vector<int>;
int rev[1 << 22];
const int P = 998244353;

int ksm(int a, int b) {
    int s = 1;
    for (; b; b >>= 1, a = 1LL * a * a % P)
        if (b & 1)
            s = 1LL * s * a % P;
    return s;
}
void NTT(int a[], int n, int inv) {
    for (int i = 0; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << std::__lg(n >> 1));
    for (int i = 0; i < n; i++)
        if (i < rev[i])
            std::swap(a[i], a[rev[i]]);
    for (int i = 2; i <= n; i <<= 1) {
        int gn = ksm(3, (P - 1) / i);
        for (int j = 0; j < n; j += i) {
            int g0 = 1;
            for (int k = j; k < j + i / 2; ++k, g0 = 1LL * g0 * gn % P) {
                int x = a[k], y = 1LL * g0 * a[k + i / 2] % P;
                a[k] = (x + y) % P;
                a[k + i / 2] = (x - y + P) % P;
            }
        }
    }
    if (inv == -1) {
        reverse(a + 1, a + n);
        int n_inv = ksm(n, P - 2);
        for (int i = 0; i < n; i++)
            a[i] = 1LL * a[i] * n_inv % P;
    }
}
Poly operator*(Poly a, Poly b) {
    int n = a.size() + b.size() - 1;
    a.resize(2 << __lg(n - 1));
    b.resize(2 << __lg(n - 1));
    NTT(a.data(), a.size(), 1);
    NTT(b.data(), b.size(), 1);
    Poly c(2 << __lg(n - 1));
    for (int i = 0; i < c.size(); i++)
        c[i] = 1LL * a[i] * b[i] % P;
    NTT(c.data(), c.size(), -1);
    c.resize(n);
    return c;
}

int main() {
    int n, m;
    cin >> n >> m;
    Poly a(n + 1), b(m + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= m; i++)
        cin >> b[i];
    Poly ans = a * b;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}

// int main() {
//     Poly vec1{1, 2, 3, 4}, vec2{4, 3, 2, 1};
//     Poly ans = vec1 * vec2;
//     for (int i = 0; i < ans.size(); i++)
//         cout << ans[i] << ' ';
//     return 0;
// }