/** 
 * @file    :   Codeforces Round #812 (Div. 2) B
 * @author  :   Tanphoon 
 * @date    :   2022/08/06 22:35
 * @version :   2022/08/06 22:35
 * @link    :   https://codeforces.com/contest/1713/problem/B
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
    int n, ans = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], ans = max(ans, a[i]);
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1])
            sum += a[i] - a[i - 1];
    sum += a[0];
    cout << (sum == ans ? "YES" : "NO") << endl;
    // iota(a.begin(), a.end(), 1);
    // do
    // {
    //     int sum = a[0];
    //     for (int i = 1; i < a.size(); i++)
    //         if (a[i] > a[i - 1])
    //             sum += a[i] - a[i - 1];
    //     for (int i = 0, l = a.size(); i < l; i++)
    //         cout << a[i];
    //     cout << " " << sum << endl;
    // } while (next_permutation(a.begin(), a.end()));
}
int main()
{
    ios::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}