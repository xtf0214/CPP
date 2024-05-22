/** 
 * @file    :   A
 * @author  :   Tanphoon 
 * @date    :   2024/05/10 15:18
 * @version :   2024/05/10 15:18
 * @link    :   https://codeforces.com/gym/104883/
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s += x;
    }
    cout << s << '\n';
}