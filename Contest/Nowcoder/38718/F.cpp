/** 
 * @file    :   F
 * @author  :   Tanphoon 
 * @date    :   2023/07/18 18:37
 * @version :   2023/07/18 18:37
 * @link    :   https://ac.nowcoder.com/acm/contest/38718/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    ll s = 0;
    for (ll i = 3; i <= n; i++)
        s += i * (i - 1);
    cout << s;
    return 0;
}