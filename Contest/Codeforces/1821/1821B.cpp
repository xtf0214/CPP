/** 
 * @file    :   1821B
 * @author  :   Tanphoon 
 * @date    :   2023/07/09 13:34
 * @version :   2023/07/09 13:34
 * @link    :   https://codeforces.com/contest/1821/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];
    int l = 0, r = n - 1;
    while (b[l] == a[l])
        l++;
    while (b[r] == a[r])
        r--;
    while (r + 1 < n && b[r + 1] >= b[r])
        r++;
    while (l - 1 >= 0 && b[l - 1] <= b[l])
        l--;
    cout << l + 1 << ' ' << r + 1 << '\n'; 
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}