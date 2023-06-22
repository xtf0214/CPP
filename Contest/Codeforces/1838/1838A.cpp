/**
 * @file    :   Codeforces Round 877 (Div. 2) 1838A
 * @author  :   Tanphoon
 * @date    :   2023/06/04 22:49
 * @version :   2023/06/04 22:49
 * @link    :   https://codeforces.com/contest/1838/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    if (a[0] < 0) 
        cout << a[0] << '\n';
    else    
        cout << a.back() << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}