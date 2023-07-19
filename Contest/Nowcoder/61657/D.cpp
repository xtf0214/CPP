/**
 * @file    :   固执的RT
 * @author  :   Tanphoon
 * @date    :   2023/07/19 13:04
 * @version :   2023/07/19 13:04
 * @link    :   https://ac.nowcoder.com/acm/contest/61657/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (accumulate(a.begin(), a.end(), 0LL) >= m)
        puts("YES");
    else
        puts("NO");
    return 0;
}