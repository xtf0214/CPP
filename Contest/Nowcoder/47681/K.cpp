/**
 * @file    :   K
 * @author  :   Tanphoon
 * @date    :   2023/09/28 17:59
 * @version :   2023/09/28 17:59
 * @link    :   https://ac.nowcoder.com/acm/contest/47681/K
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(N), b(N), s(N);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        b[x]++;
    }
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; i * j <= n; j++)
            s[i * j] += a[i] * b[j];
    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        cout << s[i] << '\n';
    }
    return 0;
}