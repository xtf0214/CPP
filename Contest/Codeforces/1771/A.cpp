/** 
 * @file    :   Codeforces Round #837 (Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2022/12/11 22:35
 * @version :   2022/12/11 22:35
 * @link    :   https://codeforces.com/contest/1771/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    map<ll, ll> Map;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        Map[x]++;
    }
    ll a = Map.begin()->second, b = Map.rbegin()->second;
    if (Map.size() > 1)
        cout << a * b * 2 << endl;
    else {
        cout << n * (n - 1) << endl;
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}