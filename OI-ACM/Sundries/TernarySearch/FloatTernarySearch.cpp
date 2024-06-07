/**
 * @file    :   实数三分
 * @author  :   Tanphoon
 * @date    :   2024/05/29 11:56
 * @version :   2024/05/29 11:56
 * @link    :   https://www.luogu.com.cn/problem/P3382
 */
#include <bits/stdc++.h>
using namespace std;
using lld = long double;
int main() {
    int n;
    lld l, r;
    cin >> n >> l >> r;
    vector<lld> a(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    auto calc = [&](lld x) {
        lld ans = a[n], mul = x;
        for (int i = n - 1; i >= 0; i--, mul *= x)
            ans += a[i] * mul;
        return ans;
    };
    auto ternary = [&](lld l, lld r) {
        for (int t = 1; t <= 100; t++) {
            lld m1 = l + (r - l) / 3;
            lld m2 = r - (r - l) / 3;
            calc(m1) > calc(m2) ? r = m2 : l = m1; // 凸函数>，凹函数<
        }
        return l;
    };
    cout << fixed << setprecision(10) << ternary(l, r) << '\n';
}