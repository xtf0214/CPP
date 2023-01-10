/** 
 * @file    :   Good Bye 2022: 2023 is NEAR A
 * @author  :   Tanphoon 
 * @date    :   2022/12/30 22:35
 * @version :   2022/12/30 22:35
 * @link    :   https://codeforces.com/contest/1770/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n>>m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}