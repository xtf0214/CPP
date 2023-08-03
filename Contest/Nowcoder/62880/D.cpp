/** 
 * @file    :   D
 * @author  :   Tanphoon 
 * @date    :   2023/08/02 13:47
 * @version :   2023/08/02 13:47
 * @link    :   https://ac.nowcoder.com/acm/contest/62880/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, p;
    cin >> n >> p;
    ll a = 2;
    for (int i = 1; i <= n; i++)
        a = a * a % p;
    cout << a << '\n';
    return 0;
}