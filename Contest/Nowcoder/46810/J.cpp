/**
 * @file    :   J
 * @author  :   Tanphoon
 * @date    :   2023/01/18 14:13
 * @version :   2023/01/18 14:13
 * @link    :   https://ac.nowcoder.com/acm/contest/46810/J
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
void solve() {
    int n, a;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        // 任意两个数的 max(|x-y|,|x+y|)=|x|+|y|
        ans += abs(a); 
    }
    ans *= n * 2;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}