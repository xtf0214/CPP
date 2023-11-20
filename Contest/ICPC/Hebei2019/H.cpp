/** 
 * @file    :   H
 * @author  :   Tanphoon 
 * @date    :   2023/11/20 15:23
 * @version :   2023/11/20 15:23
 * @link    :   https://ac.nowcoder.com/acm/contest/69987/H
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int count(ll x) {
    int s = 0;
    while (x)
        s += x % 10, x /= 10;
    return s;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        ll x = n;
        if (k == 2) 
            x = n * n;
        while (x >= 10) {
            x = count(x);
        }
        cout << x << '\n';
    }
}