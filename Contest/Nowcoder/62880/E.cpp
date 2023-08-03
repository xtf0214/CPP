/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2023/08/02 13:03
 * @version :   2023/08/02 13:03
 * @link    :   https://ac.nowcoder.com/acm/contest/62880/E
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, s;
    cin >> n >> s;
    ll t = s / n;
    ll m = s % n;
    for (int i = 0; i < n - m; i++)
        cout << t << ' ';
    for (int i = n - m; i < n; i++)
        cout << t + 1 << ' ';
    return 0;
}