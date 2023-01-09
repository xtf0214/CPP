/** 
 * @file    :   Educational Codeforces Round 132 (Rated for Div. 2) B
 * @author  :   Tanphoon 
 * @version :   2022/07/21 22:35
 * @date    :   2022/07/21 22:35
 * @link    :   https://codeforces.com/contest/1709/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// ifstream fin("2.in");
// #define cin fin
const int MAXN = 2e5 + 5;
ll high[MAXN]{0};
ll pre_Right[MAXN]{0}, pre_Left[MAXN]{0};
inline void print(ll arr[], int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << arr[i] << " \n"[i == r];
}
inline ll query(ll a[], int l, int r) { return a[r] - a[l - 1]; }
int main()
{
    ll T, n, u, v;
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
        cin >> high[i];
    for (int i = 1; i <= n; i++)
    {
        pre_Right[i] = pre_Right[i - 1] + max(high[i - 1] - high[i], 0LL);
        pre_Left[i] = pre_Left[i - 1] + max(high[i + 1] - high[i], 0LL);
    }
    // print(pre_Right, 1, n);
    // print(pre_Left, 1, n);
    while (T--)
    {
        cin >> u >> v;
        if (u < v)
            cout << query(pre_Right, u + 1, v) << endl;
        else
            cout << query(pre_Left, v, u - 1) << endl;
    }
    return 0;
}