/** 
 * @file    :   Codeforces Round 881 (Div. 3) 1843A
 * @author  :   Tanphoon 
 * @date    :   2023/06/21 01:38
 * @version :   2023/06/21 01:38
 * @link    :   https://codeforces.com/contest/1843/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if (i != j)
            ans += a[j] - a[i];
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}