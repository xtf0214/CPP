/**
 * @file    :   F
 * @author  :   Tanphoon
 * @date    :   2024/06/12 21:22
 * @version :   2024/06/12 21:22
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

const ll Mlim = 1e18;
vector f(1000, vector<i128>(70));
vector p(1000, vector<i128>(70));
vector<int> lim(1000);
vector<int> primes{2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,
                   53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                   127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
                   199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                   283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
                   383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
                   467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
void init() {
    for (int i = 0; i < 100; i++) {
        int x = primes[i];
        f[x][0] = p[x][0] = 1;
        // f(x,i)=1+x+...+x^{i-1} 其含义是每 x^i 个数能提供 f(x,i) 个x因子
        // p(x,i)=x^i
        // lim(x)表示满足f(x,i)<=Mlim的最大i
        for (i128 t = x, j = 1;; t *= x, j++) {
            f[x][j] = (1 - t) / (1 - x);
            p[x][j] = t;
            if (f[x][j] > Mlim)
                break;
            lim[x] = j;
        }
    }
}
inline void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        int x = primes[i];
        ll res = 0;
        for (int j = lim[x]; j >= 1; j--) {
            if (a[i] >= f[x][j]) {
                ll cnt = a[i] / f[x][j]; // 可以分成多少个x^j
                a[i] -= cnt * f[x][j]; // 减去已经使用的x^j
                res += cnt * p[x][j]; // 
            }
            /* 
            这部分比较抽象，举个例子说明一下，假设需要去最小的n满足(5^176)|n!，a[i]=176
            根据已经处理的f(x,i)可知，f(5)=[1,1,6,31,156,781,...]
            每5^4个数能够提供f(5,4)=156个5因子，
            每5^3个数能够提供f(5,3)=31个5因子，
            每5^2个数能够提供f(5,2)=6个5因子
            每5^1个数可以提供f(5,1)=1个5因子
            由于156*1+6*3+1*2=176
            所以n=5^4+5^2*3+5^1*2=710
            */
        }
        mx = max(mx, res);
    }
    cout << mx << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}