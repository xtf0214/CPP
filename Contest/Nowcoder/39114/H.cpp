/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2023/08/29 15:56
 * @version :   2023/08/29 15:56
 * @link    :   https://ac.nowcoder.com/acm/contest/39114/H
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e11 + 3;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll a = 3, b = 1, s[4]{0, 1, 4, 4};
    for (int i = 3; i <= n; i++) {
        tie(a, b) = pair((a + b) % mod, a);
        s[3] = (s[3] + a) % mod;
    }
    if (n >= 3)
        cout << s[3] << endl;
    else
        cout << s[n] << endl;
    return 0;
}