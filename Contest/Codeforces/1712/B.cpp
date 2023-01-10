/** 
 * @file    :   Codeforces Round #813 (Div. 2) B
 * @author  :   Tanphoon 
 * @date    :   2022/08/13 22:35
 * @version :   2022/08/13 22:35
 * @link    :   https://codeforces.com/contest/1716/problem/B
*/
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
void solve()
{
    // ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vi a(n);
    iota(a.begin(), a.end(), 1);
    for (int i = n & 1; i < n; i += 2)
        swap(a[i], a[i + 1]);
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
    // vector<pair<int, vi>> mp;
    // do
    // {
    //     int ans = 0;
    //     for (int i = 0; i < n; i++)
    //         ans += (i + 1) * a[i] / __gcd(i + 1, a[i]);
    //     mp.push_back({ans, a});
    // } while (next_permutation(a.begin(), a.end()));
    // sort(mp.begin(), mp.end());
    // auto &[ans, arr] = *mp.rbegin();
    // cout << ans << " ";
    // for (auto &i : arr)
    //     cout << i;
    // cout << endl;
}
int main()
{

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}