/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2023/01/18 13:35
 * @version :   2023/01/18 13:35
 * @link    :   https://ac.nowcoder.com/acm/contest/46810/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int main() {
    cin >> n;
    vector<int> dep(n), v(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        dep[i] = dep[--p] + 1;
    }
    sort(dep.begin(), dep.end());
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += 1LL * (dep[i] + 1) * v[i];
    cout << ans << endl;
    return 0;
}