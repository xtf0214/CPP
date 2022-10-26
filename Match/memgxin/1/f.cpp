#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    priority_queue<int> pq;
    vector<pii> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].fi >> a[i].se;
    sort(all(a));
    int ans = 0, st = 0;
    while (st == m || t < a.back().fi)
    {
        pii max;
        for (int i = st; /* i < m && a[i].fi <= t ? true : st = i, false */; i++)
        {
            if (i >= m || a[i].fi > t)
            {
                st = i;
                break;
            }
            if (max.se < a[i].se)
                max = a[i];
        }
        t = max.fi + max.se;
        ans++;
    }
    cout << ans << endl;
    return 0;
}