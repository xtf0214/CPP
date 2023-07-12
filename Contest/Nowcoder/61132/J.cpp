/** 
 * @file    :   J
 * @author  :   Tanphoon 
 * @date    :   2023/07/13 00:35
 * @version :   2023/07/13 00:35
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/J
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto [mn, mx] = minmax_element(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    double l = 1.0 * (sum - *mx) / (n - 1);
    double r = 1.0 * (sum - *mn) / (n - 1);
    printf("%.6lf %.6lf", l, r);
    return 0;
}