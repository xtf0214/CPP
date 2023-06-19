/**
 * @file    :   Codeforces Round 880 (Div. 2) 1836B
 * @author  :   Tanphoon
 * @date    :   2023/06/18 23:13
 * @version :   2023/06/18 23:13
 * @link    :	https://codeforces.com/contest/1836/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, g;
    cin >> n >> k >> g;
    ll lim = (g - 1) / 2; // 四舍五入的最大舍去值
    if (lim * n >= k * g) { // 如果每个人的最小，加起来的的值还是大于等于k*g，那么说明没法省钱了
        cout << k * g << '\n';
        return;
    }
	// 对x按照规则进行四舍五入
    auto get = [g](ll x) {
        ll r = x % g;
        return x - r + ((r >= (g + 1) / 2) ? g : 0);
    };
    ll last = k * g - (n - 1) * lim; // 最后一个人的钱数
    cout << k * g - get(last) << '\n'; // 前n-1个人，实际发放0，最后一个人发放get(last)
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}