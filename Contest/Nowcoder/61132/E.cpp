/** 
 * @file    :   E
 * @author  :   Tanphoon 
 * @date    :   2023/07/13 00:37
 * @version :   2023/07/13 00:37
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/E
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll sum = 0;
    int cnt = 0;
    for (int i = 1, j = 1; i <= n;) {
        while (j <= n && sum < m)
            sum += a[j++];
        if (sum == m)
            cnt++;
        sum -= a[i++];
    }
    cout << cnt << '\n';
}