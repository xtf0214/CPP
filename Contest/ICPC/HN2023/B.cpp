/** 
 * @file    :   B 循环数码
 * @author  :   Tanphoon 
 * @date    :   2023/08/31 09:37
 * @version :   2023/08/31 09:37
 * @link    :   https://ac.nowcoder.com/acm/contest/58860/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
template <typename T> T pow(T a, long long b) {
    T s = 1;
    for (; b; a = a * a, b >>= 1)
        if (b & 1)
            s = s * a;
    return s;
}
struct Z {
    long long x;
    Z() : x(0) {}
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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        t[i] = s[i] - '0';
    Z ans;
    // tmp[i] : 循环节长度为i时有多少种不同的方案
    vector<Z> tmp(n + 1);
    tmp[1] = 9;
    for (int i = 2; i <= n; i++)
        tmp[i] = tmp[i - 1] * 10;
    // 枚举循环节长度[2, n-1]，使用容斥原理减掉重复的方案，并进行计算总方案数
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 2; i * j <= n - 1; j++) {
            tmp[i * j] = tmp[i * j] - tmp[i];
            ans = ans + tmp[i];
        }
    }
    // for (int i = 2; i <= n - 1; i++) {
    //     for (int j = 1; j * j <= i; j++) {
    //         if (i % j == 0) {
    //             ans = ans + tmp[j];
    //             tmp[i] = tmp[i] - tmp[j];
    //             if (j * j != i && j != 1) {
    //                 ans = ans + tmp[i / j];
    //                 tmp[i] = tmp[i] - tmp[i / j];
    //             }
    //         }
    //     }
    // }
    // 计算n的所有约数
    vector<int> x;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            x.emplace_back(i);
            if (i * i != n && i != 1)
                x.emplace_back(n / i);
        }
    }
    sort(x.begin(), x.end());
    // 计算循环节长度n
    vector<Z> c(n + 1);
    for (int len : x) {
        // 长度为len的方案数，去掉前导零，tmp -= (10**(len - 1) - 1)
        Z tmp;
        for (int j = 0; j < len; j++)
            tmp = tmp * 10 + t[j];
        tmp = tmp - (pow(Z(10), len - 1) - 1);
        // 保证后面的都符合
        for (int j = len; j < n; j++) {
            if (t[j] > t[j % len]) {
                break;
            }
            if (t[j] < t[j % len]) {
                tmp = tmp - 1;
                break;
            }
        }
        c[len] = c[len] + tmp;
        // 容斥原理减掉重复
        for (int j = 2; len * j <= n; j++)
            c[len * j] = c[len * j] - c[len];
    }
    for (int len : x) {
        ans = ans + c[len];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false); 
    int T = 1;
    while (T--) 
        solve();
}
