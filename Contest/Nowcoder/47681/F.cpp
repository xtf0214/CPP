/** 
 * @file    :   F
 * @author  :   Tanphoon 
 * @date    :   2023/09/29 21:29
 * @version :   2023/09/29 21:29
 * @link    :   https://ac.nowcoder.com/acm/contest/66272/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
    }
    cout << sum * n << '\n';
    return 0;
}