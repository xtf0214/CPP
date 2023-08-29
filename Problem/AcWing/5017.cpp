/**
 * @file    :   5017. 垦田计划
 * @author  :   Tanphoon
 * @date    :   2023/08/29 14:42
 * @version :   2023/08/29 14:42
 * @link    :   https://www.acwing.com/problem/content/description/5020/
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i] >> c[i];
    auto check = [&](int x) {
        ll s = 0;
        for (int i = 0; i < n; i++)
            if (t[i] - x > 0)
                s += (t[i] - x) * c[i];
        return s <= m;
    };
    ll l = k - 1, r = 1e5 + 5, mid;
    while (r - l > 1)
        check(mid = (l + r) / 2) ? r = mid : l = mid;
    cout << r << '\n';
}