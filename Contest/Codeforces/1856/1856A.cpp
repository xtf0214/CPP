/** 
 * @file    :   1856A
 * @author  :   Tanphoon 
 * @date    :   2023/08/05 22:39
 * @version :   2023/08/05 22:39
 * @link    :   https://codeforces.com/contest/1856/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);    
    for (int &x : a)
        cin >> x;
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            ans = max(ans, a[i - 1]);
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