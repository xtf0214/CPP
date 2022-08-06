#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
void solve()
{
    int n, t;
    cin >> n;
    vector<int> a(n), st(n), sqr(n);
    for (int i = 0; i * i < 2 * n; i++)
        sqr[i * i] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int j = n - 1;
        for (; !sqr[j + i]&&st[j]; j--)
            ;
        a[i] = j, st[j] = 1;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
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