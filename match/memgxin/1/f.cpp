#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAXN = 10000 + 5;
int main()
{
    int n, m, t;
    int ans = 0;
    pii a[MAXN];
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + m);
    for (int i = 0; i < m; i++)
        if (a[i + 1].first >= t)
        {
            t += a[i].second;
            ans++;
        }
    cout << ans << endl;
    return 0;
}