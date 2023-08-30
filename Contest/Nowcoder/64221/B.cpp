/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2023/08/30 14:09
 * @version :   2023/08/30 14:09
 * @link    :   https://ac.nowcoder.com/acm/contest/64221/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5, mod = 1e9 + 7;

ll a[N], b[N];
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
    friend istream &operator>>(istream &is, Z &z) { return cin >> z.x, z.x = Norm(z.x), is; }
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2)
            swap(l1, l2), swap(r1, r2);
        // 被覆盖的点
        ++a[l1], --a[r1 + 1];
        ++a[l2], --a[r2 + 1];
        // 不被覆盖的点
        ++b[1], --b[l1];
        if (r1 < l2)
            ++b[r1 + 1], --b[l2];
        ++b[max(r1, r2) + 1], --b[N - 1];
    }
    for (int i = 1; i < N; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    Z ans;
    for (int i = 1; i <= 5e5; i++)
        if (b[i] == 0) {
            ll s = a[i] - n;
            ans = ans + pow(Z(2), s);
        }
    cout << ans << '\n';
    return 0;
}