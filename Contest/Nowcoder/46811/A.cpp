/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/01/20 13:57
 * @version :   2023/01/20 13:57
 * @link    :   https://ac.nowcoder.com/acm/contest/46811/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, x, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0)
            while (x % 2 == 0)
                x /= 2;
        sum += x;
    }
    cout << sum << endl;
    return 0;
}