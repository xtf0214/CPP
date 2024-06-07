/** 
 * @file    :   扩展欧几里得
 * @author  :   Tanphoon
 * @date    :   2024/06/07 11:43
 * @version :   2024/06/07 11:43
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d;
    if (b == 0)
        x = 1, y = 0, d = a;
    else {
        d = extgcd(b, a % b, y, x); // x'  y'
        y -= a / b * x;             // y = y - a / b * x = x' - a / b * y' = y'' - a / b * y'
    }
    return d;
}
int main() {
    // ax + by = gcd(a,b)
    ll a, b, x, y;
    cin >> a >> b;
    extgcd(a, b, x, y);
    cout << x << ' ' << y << endl;
    return 0;
}
// pair<ll, ll> extgcd(ll a, ll b) {
//     if (b == 0)
//         return {1, 0};
//     else {
//         auto [x, y] = extgcd(b, a % b);
//         return {y, x - a / b * y};
//     }
// }
// pair<ll, ll> extgcd(ll a, ll b) {
//     ll A[100] = {0}, d[100] = {0}, n = 0;
//     while (b != 0) {
//         ll r = a % b;
//         d[n++] = a / b;
//         a = b, b = r;
//     }
//     A[n] = 0, A[n + 1] = 1;
//     d[n] = 0;
//     for (int i = n - 1; i >= 0; i--)
//         A[i] = A[i + 2] - A[i + 1] * d[i];
//     return {A[1], A[0]};
// }