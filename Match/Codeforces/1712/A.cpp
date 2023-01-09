/** 
 * @file    :   Codeforces Round #813 (Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2022/08/13 22:35
 * @version :   2022/08/13 22:35
 * @link    :   https://codeforces.com/contest/1716/problem/A
*/
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
void solve()
{
    // ios::sync_with_stdio(0);
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        if (a[i] > k)
            cnt++;
    cout << cnt << endl;
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}