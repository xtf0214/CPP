/** 
 * @file    :   Basis
 * @author  :   Tanphoon 
 * @date    :   2024/03/18 22:41
 * @version :   2024/03/18 22:41
 * @link    :   https://www.luogu.com.cn/problem/P3812
 */ 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p[64];

void insert(ll x) {
    for (int i = 62; ~i; --i) {
        if (!(x >> i))
            continue;
        if (!p[i]) {
            p[i] = x;
            break;
        }
        x ^= p[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        insert(a);
    }
    ll ans = 0;
    for (int i = 62; ~i; --i) {
        ans = max(ans, ans ^ p[i]);
    }
    cout << ans << '\n';
    return 0;
}