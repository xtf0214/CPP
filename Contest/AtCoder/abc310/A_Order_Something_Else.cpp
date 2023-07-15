/** 
 * @file    :   A_Order_Something_Else
 * @author  :   Tanphoon 
 * @date    :   2023/07/15 23:39
 * @version :   2023/07/15 23:39
 * @link    :   https://atcoder.jp/contests/abc310/tasks/abc310_a
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << min(p, q + *min_element(a.begin(), a.end()));
    return 0;
}