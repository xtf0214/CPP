/** 
 * @file    :   Codeforces Round 875 (Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2023/05/29 03:10
 * @version :   2023/05/29 03:10
 * @link    :   https://codeforces.com/contest/1831/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << n + 1 - a[i] << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}