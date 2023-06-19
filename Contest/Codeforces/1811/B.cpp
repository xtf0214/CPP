/** 
 * @file    :   Codeforces Round 863 (Div. 3) 1811B
 * @author  :   Tanphoon 
 * @date    :   2023/06/19 23:04
 * @version :   2023/06/19 23:04
 * @link    :   https://codeforces.com/contest/1811/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, y1, x1, y2, x2;
    cin >> n >> y1 >> x1 >> y2 >> x2;
    auto get = [n](int x) {
        return  x <= n / 2 ? (n / 2 + 1 - x) : x - n / 2;
    };
    y1 = get(y1);
    x1 = get(x1);
    y2 = get(y2);
    x2 = get(x2);
    int r1 = max(y1, x1);
    int r2 = max(y2, x2);
    cout  << abs(r1 - r2) << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}